#pragma once
#ifndef _ForceManager_H
#define _ForceManager_H

//includes
#include "..\..\External Dependencies\SFML-2.4.2\include\SFML\Graphics.hpp"
#include "..\..\External Dependencies\SFML-2.4.2\include\SFML\OpenGL.hpp"
#include <vector>
#include "GameEntity.h"

class ForceManager {
protected:
	//vairbles
	std::vector<std::pair<GameEntity, sf::Vector2f>> m_forceStore;//Stores a reference to each force applied to each object.
public:
	ForceManager(); //basic constructor
	~ForceManager(); //basic deconstructor.

	void ApplyForce(sf::Vector2f f, GameEntity gE); //updated variable m_force.



};
#endif