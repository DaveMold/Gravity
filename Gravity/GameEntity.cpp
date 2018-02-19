#include "SFML/Graphics.hpp"
#include "GameEntity.h"


GameEntity::GameEntity(float size, float sides, sf::Vector2f pos) :shape(sides) {
	rotateSpeed = 0;
	radius = size;
	numSides = sides;
	DegreToRad = 3.14 / 180;
	rotateSpeed = 0;
	posCentre = pos;
	points.reserve(numSides + 1);
	float indexOfPointsInCircle;

	/*shapes are created in the centre of a circle with radius "size",
	I devide the amount of sides by the degrees of a circle to get the
	intervals at which to posistion my points.*/
	switch (static_cast<int>(numSides))
	{
	case 3: //triangle
			/*as sf::shape will create with 0 degrees pointing left and not up,
			These figures are used to offset the triangle so it points up. */
		points.push_back(sf::Vector2f(cos(DegreToRad * 270), sin(DegreToRad * 270)));
		points.push_back(sf::Vector2f(cos(DegreToRad * 30), sin(DegreToRad * 30)));
		points.push_back(sf::Vector2f(cos(DegreToRad * 150), sin(DegreToRad * 150)));
		width = sqrt(pow((points[2].x - points[1].x), 2) + pow((points[2].y - points[1].y), 2));
		height = sqrt(pow(width, 2) - (pow(width, 2) / 4.0f));
		for (int i = 0; i < numSides; i++) {
			points[i] *= radius;
		}
		break;
	case 6: //Distruction Object
			//This will draw a square rotated to one side as well as having a line drawn through it.
		points.push_back(sf::Vector2f(-size / 2.f, 0));
		points.push_back(sf::Vector2f(0, -size / 2.f));
		points.push_back(sf::Vector2f(size / 2.f, 0));
		points.push_back(sf::Vector2f(-size / 2.f, 0));
		points.push_back(sf::Vector2f(0, size / 2.f));
		points.push_back(sf::Vector2f(size / 2.f, 0));
		break;
	default:
		for (int i = 0; i < numSides; i++) {
			indexOfPointsInCircle = /*degrees in circle / number of points*/ 360.0 / numSides;
			indexOfPointsInCircle = (i * indexOfPointsInCircle) + (indexOfPointsInCircle / 2);
			points.push_back(sf::Vector2f(cos(DegreToRad * indexOfPointsInCircle), sin(DegreToRad * indexOfPointsInCircle)));
		}
		width = sqrt(pow((points[2].x - points[1].x), 2) + pow((points[2].y - points[1].y), 2));
		height = width;
		for (int i = 0; i < numSides; i++) {
			points[i] *= radius;
		}
		break;
	}//end switch

	for (int i = 0; i < numSides; i++) {
		shape.setPoint(i, points[i]);
	}

	/*direction.x = (rand() % 10 - 5) / 60.0;
	direction.y = (rand() % 10 - 5) / 60.0;*/
	shape.setOutlineThickness(-4);
	//Color Preset
	shape.setOutlineColor(sf::Color::Blue);
	
	shape.setFillColor(sf::Color::Black);
}

GameEntity::GameEntity(float Width, float Height, float sides, sf::Vector2f pos) :shape(sides) {
	rotateSpeed = 0;
	numSides = 4;
	DegreToRad = 3.14 / 180;
	rotateSpeed = 0;
	posCentre = pos;
	points.reserve(numSides + 1);
	width = Width;
	height = Height;

	//set points for a retangle or square.
	/*points.push_back(sf::Vector2f(posCentre.x - (Width / 2), posCentre.y - (Height / 2)));
	points.push_back(sf::Vector2f(posCentre.x + (Width / 2), posCentre.y - (Height / 2)));
	points.push_back(sf::Vector2f(posCentre.x - (Width / 2), posCentre.y + (Height / 2)));
	points.push_back(sf::Vector2f(posCentre.x + (Width / 2), posCentre.y + (Height / 2)));*/

	points.push_back(sf::Vector2f(0, 0));
	points.push_back(sf::Vector2f(width, 0));
	points.push_back(sf::Vector2f(width, height));
	points.push_back(sf::Vector2f(0, height));

	for (int i = 0; i < numSides; i++) {
		shape.setPoint(i, points[i]);
	}

	/*direction.x = (rand() % 10 - 5) / 60.0;
	direction.y = (rand() % 10 - 5) / 60.0;*/
	shape.setOutlineThickness(-4);
	//Color Preset
	shape.setOutlineColor(sf::Color::Green);
	shape.setFillColor(sf::Color::Black);
}

GameEntity::~GameEntity() {
	points.clear();
}

void GameEntity::Draw(sf::RenderWindow &w) {
	w.draw(shape);
}

void GameEntity::SetPos(sf::RenderWindow &w) {
	posCentre = sf::Vector2f((rand() % (w.getSize().x - 2) + 5), (rand() % (w.getSize().y - 2) + 5));
}

void GameEntity::Update() {
	//posCentre += direction;
	rotation.rotate(rotateSpeed);

	for (int i = 0; i < shape.getPointCount(); i++) {
		points[i] = rotation * points[i];
	}
	for (int i = 0; i < shape.getPointCount(); i++) {
		shape.setPoint(i, points[i]);
	}
	shape.setPosition(posCentre);
}

void GameEntity::SetColor(sf::Color color) {
	if (shape.getOutlineColor() != color)
		shape.setOutlineColor(color);
	else
		shape.setOutlineColor(sf::Color::White);
}

sf::Vector2f GameEntity::GetPos() {
	return posCentre;
}

float GameEntity::GetRadius() {
	return radius;
}

sf::ConvexShape GameEntity::getShape() {
	return shape;
}