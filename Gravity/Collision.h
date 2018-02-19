//#pragma once
//#ifndef _Collision_H
//#define _Collision_H
//
////includes
//#include <SFML/Graphics.hpp>
//#include <SFML/OpenGL.hpp>
//#include <vector>
//#include "GameEntity.h"
//
//
//
//class Collision {
//protected:
//	//vairbles
//	float DegreToRad; // used for conversion between degrees and radians.
//	float numSides; // the number of sides the shape will have.
//	float width, height; //stores the width and height of the 
//	sf::ConvexShape shape; // stores the convex shape to be displaied.
//	sf::Vector2f direction; //stores the direction the object should pointing.
//	sf::Transform rotation; //stores the rotation of the object.
//	sf::Vector2f posCentre; //stores the centre posistion of the object.
//	std::vector<sf::Vector2f> points; //stores the points for the shape.
//	float rotateSpeed; //stores the rotation speed to rotate by.
//	float radius; //stores the size of the surounding circle.
//public:
//	//SAT methods
//	virtual std::pair<bool, sf::Vector2f> CollisionWithPlayer(sf::RenderWindow &w, GameEntity* shape2);
//	sf::Vector2f ProjectOnToAxis(sf::Vector2f axis) const;
//	std::pair<bool, double> checkOverlap(const sf::Vector2f &A, const sf::Vector2f &B);
//	sf::Vector2f GetDirection();
//	std::vector<sf::Vector2f> GetAxis();
//	void GetAxis(std::vector<sf::Vector2f> normalsList);
//	std::vector<sf::Vector2f> ReverseVector(std::vector<sf::Vector2f> v);
//
//	//vector methods
//	float vectorDotProduct(const sf::Vector2f &A, const sf::Vector2f &B) const; //performs the vector dot product between two vector2f's.
//	sf::Vector2f vectorNormalize(const sf::Vector2f &V); //normalises a cector2f.
//
//
//};
//#endif