#include "..\..\External Dependencies\SFML-2.4.2\include\SFML\Graphics.hpp"
#include "GameEntity.h"


GameEntity::GameEntity() {
	
}

GameEntity::~GameEntity() {
	
}

void GameEntity::Draw(sf::RenderWindow &w) {
	w.draw(m_shape);
}

void GameEntity::SetPos(sf::RenderWindow &w) {
	
}

void GameEntity::ApplyForce(sf::Vector2f f) {
	m_force += f;
}

