#pragma once
#ifndef _Forces_H
#define _Forces_H

//includes
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>


class Forces {
protected:
	//vairbles
	float radus; //stores the radius of the 
	sf::Vector2f posCentre; //stores the centre posistion of the object.
	float radius; //stores the size of the surounding circle.
public:
	~Forces(); //basic constructor.
	Forces(float size, float sides, sf::Vector2f pos);
	void Update(); //moves the points of the shape and the shape depending on the rotation posistion.
	sf::Vector2f GetPos(); //returns the posisiton of the shape.
};
#endif