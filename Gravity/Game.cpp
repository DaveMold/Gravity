#pragma once
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

//#include "stdafx.h"
#include "..\..\External Dependencies\SFML-2.4.2\include\SFML\Graphics.hpp"
#include "..\..\External Dependencies\SFML-2.4.2\include\SFML\OpenGL.hpp"
#include <windows.h>
#include <Xinput.h>
#pragma comment(lib, "XInput9_1_0.lib")   // Library. If your compiler doesn't support this type of lib include change to the corresponding one

//Entities include
#include <iostream>
#include <fstream>

#include "InputManager.h"
#include "Player.h"
#include "level.h"

int main()
{	
	// Create the main window
	std::pair<float, float> windowDimentions;
	windowDimentions.first = 800;
	windowDimentions.second = 600;
	sf::RenderWindow window(sf::VideoMode(windowDimentions.first, windowDimentions.second, 32), "Gravity");
	
	
	//set up fixed time step update as well as a clock used for recording the LevelTime.
	sf::Clock levelClock = sf::Clock();
	sf::Clock fixedUpdateClock = sf::Clock();
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(0.025f / 60.f);
	//Gravity
	sf::Vector2f gravity = sf::Vector2f(0, 0);//0.2996);// 0.0981);

	//Games State used to cycle through a switch statment simular to a FSM.
	enum States { GAME};
	//Start state == MENU.
	States GameState = GAME;

	//Levels
	//create blank levels for the levels the game will use.
	std::pair<bool, bool> level_result;
	int levelCount = 1;
	int currentLevel = 0;
	std::vector<Level*> levels;
	for (int i = 0; i < levelCount; i++)
	{
		levels.push_back(new Level(window));
	}

	//InputManager
	InputManager* inputMgr = InputManager::instance();
	
	Player player_ = Player(100, 4, sf::Vector2f(1 * 100, 1 * 100), Player::SQUARE, sf::Vector2f(50 * 100, 50 * 100));
	
	// Start game loop
	while (window.isOpen()) {
		//Fixed Time Step
		sf::Time elapsedTime = fixedUpdateClock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			// Process events
			sf::Event Event;

			while (window.pollEvent(Event)) {
				switch (Event.type) {
					// Close window : exit
				case sf::Event::Closed:
					//If the game is closed deconstruct all the levels and Menu.
					for (std::vector<Level*>::iterator itr = levels.begin(); itr != levels.end(); itr++) {
						(*itr)->~Level();
					}
					window.close();
					break;
				case sf::Event::KeyPressed:
					inputMgr->KeyPressEvent(Event);
					break;
				case sf::Event::KeyReleased:
					inputMgr->KeyReleaseEvent(Event);
					break;
				default:
					break;
				}//end switch
			}//end while

			 //Update
			level_result = levels[currentLevel]->Update(gravity, window, levelClock.getElapsedTime());
			

			//prepare frame
			window.clear();
			//Draw Switch Statement.
			switch (GameState)
			{
			case GAME:
				window.setView(levels[currentLevel]->getFollowCamView());
				levels[currentLevel]->Draw(window);
				break;
			}

			// Finally, display rendered frame on screen
			window.display();
		}
	} //loop back for next frame
	return EXIT_SUCCESS;
}