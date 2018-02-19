//#include "SFML/Graphics.hpp"
//#include "Collision.h"
//
//
//std::pair<bool, sf::Vector2f>  Collision::CollisionWithPlayer(sf::RenderWindow &w, GameEntity* shape2) {
//	float overLap = FLT_MAX;
//	std::vector<sf::Vector2f> axisListShape1;
//	std::vector<sf::Vector2f> axisListShape2;
//	sf::Vector2f smallest;
//	//axisListShape1 = GetAxis();
//	//shape2->GetAxis(axisListShape1);
//	sf::Vector2f projectionV1, projectionV2;
//	float min, max, tempS1, tempS2;
//
//
//	if (shape2->shape.getPosition().x + shape2->width / 2.0f > this->shape.getPosition().x)
//	{
//		//Left
//		axisListShape1 = GetAxis();
//		shape2->GetAxis(axisListShape1);
//	}
//	else
//	{
//		//right
//		axisListShape1 = GetAxis();
//		shape2->GetAxis(axisListShape1);
//		axisListShape1 = ReverseVector(axisListShape1);
//	}
//
//	//Project shapes onto axis
//	//iterates through axisListShape1
//	for (std::vector<sf::Vector2f>::iterator itr = axisListShape1.begin(); itr != axisListShape1.end(); itr++) {
//
//		sf::Vector2f axis = *itr;
//
//		projectionV1 = this->ProjectOnToAxis(axis);
//		projectionV2 = shape2->ProjectOnToAxis(axis);
//
//		std::pair<bool, float> result = checkOverlap(projectionV1, projectionV2);
//
//		if (result.first) {
//			// check for minimum
//			if (result.second < overLap) {
//				// then set this one as the smallest
//				overLap = result.second;
//				smallest = axis;
//
//				sf::Vector2f d = posCentre - shape2->posCentre;
//				if (vectorDotProduct(d, smallest) < 0)
//					smallest = -smallest;
//			}
//		}
//		else {
//			return std::make_pair(false, sf::Vector2f());
//		}
//	}//end for
//
//	 /* MTV is the Minimum Translation Vector.
//	 we multiply the smallest colliding axis (normalized) by the overlap to get
//	 a vector that will separate the shapes with smallest magnitude.
//	 smallest = vectorNormalize(smallest);*/
//
//	 //if already moving away from each other
//	if ((vectorDotProduct(this->GetDirection(), smallest) < 0)
//		&&
//		(vectorDotProduct(shape2->GetDirection(), smallest) < 0))
//		return std::make_pair(true, sf::Vector2f(0, 0));
//
//	//normalise smallest
//	smallest = vectorNormalize(smallest);
//	sf::Vector2f mtv = sf::Vector2f(smallest * (float)overLap);
//
//	return std::make_pair(true, mtv);	//YES COLLISION
//
//}//end Collision
//
// //Returns true if they overlap and the overlap distance if they do
//std::pair<bool, double> Collision::checkOverlap(const sf::Vector2f &A, const sf::Vector2f &B) {
//
//	if (A.x >= B.x && A.x <= B.y)
//		return std::make_pair(true, B.y - A.x);
//	else if (A.y >= B.x && A.y <= B.y)
//		return std::make_pair(true, A.y - B.x);
//	else
//		return std::make_pair(false, 0);
//}
//
//sf::Vector2f Collision::ProjectOnToAxis(sf::Vector2f axis) const {
//	//normalize the axis
//	float magnitude = sqrt((axis.x * axis.x) + (axis.y * axis.y));
//	//axis.x = axis.x / magnitude;
//	axis /= magnitude;
//
//	sf::Vector2f temp;
//
//	temp.x = posCentre.x + this->width / 2;
//	temp.y = posCentre.y + this->height / 2;
//
//	//keep track of minimum and maximum points on the axis
//	float min = vectorDotProduct(axis, this->shape.getPoint(0) + temp);
//	float max = min;
//	float p;
//
//	//loop through the points and find the min and max values for projection
//	for (int i = 1; i < points.size(); i++) {
//		p = vectorDotProduct(axis, (this->shape.getPoint(i) + posCentre));
//		if (p < min) {
//			min = p;
//		}
//		else if (p > max) {
//			max = p;
//		}
//	}
//
//	sf::Vector2f proj = sf::Vector2f(min, max);
//	return proj;
//}
//
//float Collision::vectorDotProduct(const sf::Vector2f &A, const sf::Vector2f &B) const {
//	return (A.x * B.x) + (A.y * B.y);
//}
//
//sf::Vector2f Collision::GetDirection() {
//	return direction;
//}
//
//std::vector<sf::Vector2f> Collision::GetAxis() {
//	std::vector<sf::Vector2f> normalsList;
//	sf::Vector2f normal;
//	for (int PointOne = 0, PointTwo = 1; PointTwo < this->points.size(); PointOne++, PointTwo++) {
//		/*normal.x = -(this->points[PointOne].y + this->points[PointTwo].y);
//		normal.y = this->points[PointOne].x + this->points[PointTwo].x;*/
//
//		sf::Vector2f pOne = this->points[PointOne];
//		sf::Vector2f pTwo = this->points[PointTwo];
//
//		sf::Vector2f temp = pOne - pTwo;
//
//		normal.x = -temp.y;
//		normal.y = temp.x;
//		normalsList.push_back(normal);
//	}
//	return normalsList;
//}
//
//void Collision::GetAxis(std::vector<sf::Vector2f> normalsList) {
//	sf::Vector2f normal;
//	for (int PointOne = 0, PointTwo = 1; PointTwo < this->points.size(); PointOne++, PointTwo++) {
//
//		sf::Vector2f pOne = this->points[PointOne];
//		sf::Vector2f pTwo = this->points[PointTwo];
//
//		sf::Vector2f temp = pOne - pTwo;
//
//		normal.x = -temp.y;
//		normal.y = temp.x;
//		normalsList.push_back(normal);
//	}
//}
//
//sf::Vector2f Collision::vectorNormalize(const sf::Vector2f &V) {
//	float magnitude = sqrt((V.x * V.x) + (V.y * V.y));
//
//	return V / magnitude;
//}
//
//std::vector<sf::Vector2f> Collision::ReverseVector(std::vector<sf::Vector2f> v) {
//	std::vector<sf::Vector2f> vector;
//	for (std::vector<sf::Vector2f>::reverse_iterator rev_itr = v.rbegin(); rev_itr != v.rend(); rev_itr++) {
//		vector.push_back(*rev_itr);
//	}
//	return vector;
//}