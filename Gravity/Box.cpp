#include "Box.h"

Box::Box(sf::Vector2f pos) {
	m_pos = pos;
	float width = 100, height = 100;
	int numSides = 4;
	m_shape = sf::ConvexShape(numSides);
	m_points.reserve(numSides + 1);

	m_points.push_back(sf::Vector2f(0, 0));
	m_points.push_back(sf::Vector2f(width, 0));
	m_points.push_back(sf::Vector2f(width, height));
	m_points.push_back(sf::Vector2f(0, height));

	for (int i = 0; i < numSides; i++) {
		m_shape.setPoint(i, m_points[i]);
	}

	m_shape.setOutlineThickness(10);
	m_shape.setOutlineColor(sf::Color::Green);
	m_shape.setFillColor(sf::Color::Yellow);
}

Box::~Box() {

}

void Box::Update() {
	m_pos += m_force;
	m_shape.setPosition(m_pos);
}

