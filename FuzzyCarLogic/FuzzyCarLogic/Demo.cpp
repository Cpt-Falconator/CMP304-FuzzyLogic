#include "Demo.h"
#include <iostream>


Demo::Demo(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
}


Demo::~Demo()
{
}

void Demo::handleInput(float dt)
{
	//Handles the player inputs.
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		//Move something Left
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		//Move something Right
	}
}

//Demo update function.
void Demo::update(float dt)
{
	//Do update things
}

//Standard render function
void Demo::render()
{
	beginDraw();

	//window->draw();

	endDraw();
}

//Standard begin/end draw functions.
void Demo::beginDraw()
{
	window->clear(sf::Color::Black);
}

void Demo::endDraw()
{
	window->display();
}