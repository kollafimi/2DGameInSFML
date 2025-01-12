#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "ResourceManager.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Clock clock;

	Player player;


	void handleInput();
	void update(float& CurrentFrame, float time);
	void render();
	
public:
	Game();
	void run();
};

#endif // !GAME_H
