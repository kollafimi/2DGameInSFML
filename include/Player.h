#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	float x, y, dx, dy, w, h;
	
	sf::String File;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
public:

	float d;
	int dir;
	float speed;
	Player(sf::String F, float X, float Y, float W, float H);
	void update(float time);
	void controlPerson(float& CurrentFrame, float time);
	void render(sf::RenderWindow& window);
};

#endif // !PLAYER_H
