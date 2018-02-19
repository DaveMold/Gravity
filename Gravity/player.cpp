#include "Player.h"
#include "InputManager.h"

Player::Player(float size, float sides, sf::Vector2f pos, Shape s, sf::Vector2f SBounds)
	:GameEntity(size, sides, pos), debug(false), boundingOffSet(6), screenBounds_(SBounds) {



	//Follow Camra Set-up
	followPlayer.setCenter(400, 300);
	followPlayer.setSize(800, 600);
	followPlayer.setViewport(sf::FloatRect(0, 0, 1, 1));

	activeShape = s;


	shape.setFillColor(sf::Color::Black);
	shape.setPosition(pos.x - radius, pos.y - radius);

	//Color Preset
	shape.setOutlineColor(sf::Color::Blue);
}

Player::~Player() {
	points.clear();
}


void Player::Draw(sf::RenderWindow &w) {
	w.draw(shape);
}

bool Player::IsOffScreen() {
	if (posCentre.x > -50.f && posCentre.x < screenBounds_.x)
	{
		if (posCentre.y > -500.f && posCentre.y < screenBounds_.y)
		{
			return false;
		}
	}
	return true;
}



sf::View Player::getView() {
	return followPlayer;
}

void Player::SetPos(float x, float y) {
	posCentre = sf::Vector2f(x, y);
}

sf::Vector2f Player::GetPos() {
	return posCentre;
}


void Player::UpdateForce(sf::Vector2f force) {
	force_ = force;
}


void Player::Update(sf::Vector2f g) {
	if (InputManager::instance()->Pressed("Delete"))
	{
		if (debug)
			debug = false;
		else
			debug = true;
	}



	sf::Vector2f force = g + force_;
	posCentre += force;
	rotation.rotate(rotateSpeed);
	followPlayer.setCenter(posCentre.x, followPlayer.getCenter().y);

	for (int i = 0; i < shape.getPointCount(); i++) {
		points[i] = rotation * points[i];
	}
	for (int i = 0; i < shape.getPointCount(); i++) {
		shape.setPoint(i, points[i]);
	}
	shape.setPosition(posCentre);
	


}

sf::Vector2f Player::Vec2Multiply(sf::Vector2f v1, sf::Vector2f v2) {
	sf::Vector2f temp;
	temp.x = v1.x * v2.x;
	temp.y = v1.y * v2.y;
	return temp;
}



void Player::SetActiveShape(Shape s) {
	switch (s)
	{
	case SQUARE:
		activeShape = SQUARE;
		break;
	case CIRCLE:
		activeShape = CIRCLE;
		break;
	default:
		std::cout << "Player :: set Active Shape Default." << std::endl;
		break;
	}
}


sf::ConvexShape Player::getSquareShape() {
	return shape;
}

sf::CircleShape Player::getBoundingShape() {
	return boundingCircle;
}

bool Player::SquareCircle(sf::Shape* s) {
	return shape.getGlobalBounds().intersects(s->getGlobalBounds());
}

float Player::clamp(float value, const float min, const float max)
{
	value = std::min(value, max);
	value = std::max(value, min);

	return value;
}