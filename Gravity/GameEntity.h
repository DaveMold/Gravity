#pragma once
#ifndef _GameEntity_H
#define _GameEntity_H

//includes
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>


class GameEntity {
protected:
	//vairbles
	float DegreToRad; // used for conversion between degrees and radians.
	float numSides; // the number of sides the shape will have.
	float width, height; //stores the width and height of the 
	sf::ConvexShape shape; // stores the convex shape to be displaied.
	sf::Vector2f direction; //stores the direction the object should pointing.
	sf::Transform rotation; //stores the rotation of the object.
	sf::Vector2f posCentre; //stores the centre posistion of the object.
	std::vector<sf::Vector2f> points; //stores the points for the shape.
	float rotateSpeed; //stores the rotation speed to rotate by.
	float radius; //stores the size of the surounding circle.
public:
	~GameEntity(); //basic constructor.
	GameEntity(float size, float sides, sf::Vector2f pos);
	GameEntity(float Width, float Height, float sides, sf::Vector2f pos);
	void Draw(sf::RenderWindow &w); //draws the shape to the screen.
	void SetPos(sf::RenderWindow &w); //sets the objects posisiton.
	void Update(); //moves the points of the shape and the shape depending on the rotation posistion.
	void SetColor(sf::Color color); //sets the outside shape color.
	sf::Vector2f GetPos(); //returns the posisiton of the shape.
	float GetRadius(); //returns the radius of the circle that can contain the shape.
	sf::ConvexShape getShape(); //returns the shape for access in the level class.

	
};
#endif