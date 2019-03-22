#pragma once
#include <SFML/Graphics.hpp>
#include "Input.h"

class Demo
{
public:
	Demo(sf::RenderWindow* hwnd, Input* in);
	~Demo();
	void handleInput(float dt);
	void update(float dt);
	void render();
private:

	void beginDraw();
	void endDraw();

	Input * input;
	sf::RenderWindow* window;

};

