#pragma once
#ifndef _GameEntity_H
#define _GameEntity_H

//includes
#include "..\..\External Dependencies\SFML-2.4.2\include\SFML\Graphics.hpp"
#include "..\..\External Dependencies\SFML-2.4.2\include\SFML\OpenGL.hpp"
#include <vector>


class GameEntity {
protected:
	//vairbles
	sf::Vector2f m_force;//stores the current forces applied to the object.
	sf::ConvexShape m_shape;// basic shape
	sf::Vector2f m_pos;//shape posistion
	std::vector<sf::Vector2f> m_points; //stores the points for the shape.
public:
	GameEntity(); //basic constructor
	~GameEntity(); //basic deconstructor.
	void Draw(sf::RenderWindow &w); //draws the shape to the screen.
	void SetPos(sf::RenderWindow &w); //sets the objects posisiton.
	void ApplyForce(sf::Vector2f f); //updated variable m_force.
	

	
};
#endif