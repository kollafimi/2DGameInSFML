#include "Game.h"
#include <iostream>
#include <filesystem>

Game::Game() : player("cat2.png", 200, 200, 159, 159)
{
	window.create(sf::VideoMode(800, 600), "Game Cat");



	std::cout << "Текущая рабочая папка: " << std::filesystem::current_path() << std::endl;

}

void Game::run()
{
	float CurrentFrame = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		handleInput();
		update(CurrentFrame, time);
		render();
	}
}

void Game::handleInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::update(float& CurrentFrame, float time)
{
	player.controlPerson(CurrentFrame, time);
	player.update(time);
}

void Game::render()
{
	window.clear();
	player.render(window);
	window.display();
}