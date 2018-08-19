#pragma once
#ifndef _Box_H
#define _Box_H

#include "GameEntity.h"

class Box :public GameEntity {
protected:
	//vairbles
	
public:
	Box(sf::Vector2f pos);// Box constructor.
	~Box();//Box deconstructor.
	void Update(); //moves the points of the shape and the shape depending on the rotation posistion.



};
#endif