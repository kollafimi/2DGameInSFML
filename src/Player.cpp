#include "Player.h"

Player::Player(sf::String F, float X, float Y, float W, float H)
{
    dx = 0; dy = 0;
    dir = 0; speed = 0;
	File = F;
	w = W; h = H;
	image.loadFromFile("assets/textures/" + File);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X; y = Y;
	sprite.setTextureRect(sf::IntRect(0, 159, w, h));
}

void Player::update(float time)
{
    {
        switch (dir)
        {
        case 0: dx = speed; dy = 0; break;
        case 1: dx = -speed; dy = 0; break;
        case 2: dx = 0; dy = speed; break;
        case 3: dx = 0; dy = -speed; break;
        }

        x += dx * time;
        y += dy * time;

        speed = 0;
        sprite.setPosition(x, y);
    }
}

void Player::controlPerson(float& CurrentFrame, float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dir = 2; speed = 0.25;
        CurrentFrame += 0.008f * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(159 * int(CurrentFrame), 0, 159, 159));
        //getPlayerCoordinateForView(cat.getPlayerCoordinateX(), cat.getPlayerCoordinateY());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dir = 3; speed = 0.25;
        CurrentFrame += 0.008f * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(159 * int(CurrentFrame), 318, 159, 159));
        //getPlayerCoordinateForView(cat.getPlayerCoordinateX(), cat.getPlayerCoordinateY());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = 0; speed = 0.25;
        CurrentFrame += 0.008f * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(159 * int(CurrentFrame), 159, 159, 159));
        //getPlayerCoordinateForView(cat.getPlayerCoordinateX(), cat.getPlayerCoordinateY());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir = 1; speed = 0.25;
        CurrentFrame += 0.008f * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(159 * int(CurrentFrame), 477, 159, 159));
        //getPlayerCoordinateForView(cat.getPlayerCoordinateX(), cat.getPlayerCoordinateY());
    }
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(sprite);
}