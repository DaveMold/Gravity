#ifndef	LEVEL_H
#define LEVEL_H

#include "Player.h"
#include "Platform.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Level {
private:
	Player * player_;
	sf::Time startLevelTime_; //Stores the time the Curret Level was started at.
	sf::Time levelTime_; //Stores the time the player has been playing the current Level.
	std::vector<std::vector<sf::Color>> map_; //stores all the valuse read from the file to use to populate the level.
	int tileSize_, width_, height_; //store the size of the level tiles.
	enum Shape { CIRCLE, SQUARE }; //Used to identify which shape is active.

	std::vector<Platform*> platforms_;//stores all the Platforms for the level.

	const sf::Color EmptyRGB = sf::Color(0, 0, 0, 255);
	//Entities and their color values from reading from an image.
	const sf::Color PlatRGB = sf::Color(0, 255, 33, 255);
	const sf::Color PlayerS_RGB = sf::Color(0, 0, 245, 255);
	const sf::Color PlayerC_RGB = sf::Color(0, 0, 255, 255);
public:
	Level(sf::RenderWindow &w); //creates an empty level with a time of zero.
	~Level(); //deconstructor.
	void clearLevel(); //clears all the entities form a level. for repopulation.
	float GetLevelTime(); //returns the level time.
	void ResetLevelTime(); //sets the level time back to zero incase a level is to be replaied.
	sf::Vector2f GetPlayerPos(); //returns the players posisiton in the level.
	void UpdateLevelTime(sf::Time totalTime); //updates the time the level has been on from the the time since game start and the time since the game started when we started in this current level.
	bool PlayerOffScreen(Player * p); //checks weather player has gone off the screen bounds.
	
	std::pair<bool, bool> Update(sf::Vector2f g, sf::RenderWindow &w, sf::Time runTime); /*Returns the out come of the level as two bools. The first signafies if the level is over. The
																						 secoud is wether or not the player passed the level. eg got to the end with the correct shape.*/
	
	sf::View getFollowCamView(); //gets the follow camra sf::view from the player.
	void Draw(sf::RenderWindow &w); //renders the objects in the level.
};
#endif