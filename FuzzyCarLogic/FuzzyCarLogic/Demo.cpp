#include "Demo.h"
#include <iostream>


Demo::Demo(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	font.loadFromFile("font/Square.ttf");

	bar.setSize(sf::Vector2f(10, window->getSize().y));
	bar.setOrigin(bar.getSize().x / 2, bar.getSize().y / 2);
	bar.setPosition(sf::Vector2f((window->getSize().x / 2), window->getSize().y / 2));
	bar.setFillColor(sf::Color::Yellow);

	carTex.loadFromFile("gfx/car.png");
	car.setTexture(carTex);
	car.setOrigin(car.getTexture()->getSize().x / 2, car.getTexture()->getSize().y / 2);
	car.setPosition(bar.getPosition().x, bar.getPosition().y);

	outputs.setString("Output");
	outputs.setCharacterSize(15);
	outputs.setPosition(500, 1);
	outputs.setFont(font);
	outputs.setOutlineColor(sf::Color::Black);
	outputs.setOutlineThickness(2);

	inputs.setString("Input");
	inputs.setPosition(1, 1);
	inputs.setCharacterSize(15);
	inputs.setFont(font);
	inputs.setOutlineColor(sf::Color::Black);
	inputs.setOutlineThickness(2);

	in_distance.setString("Distance = ");
	in_distance.setPosition(1, 21);
	in_distance.setCharacterSize(15);
	in_distance.setFont(font);
	in_distance.setOutlineColor(sf::Color::Black);
	in_distance.setOutlineThickness(2);

	in_roc.setString("Rate of Change = ");
	in_roc.setPosition(1, 41);
	in_roc.setCharacterSize(15);
	in_roc.setFont(font);
	in_roc.setOutlineColor(sf::Color::Black);
	in_roc.setOutlineThickness(2);

	out_velocity.setString("Velocity = ");
	out_velocity.setPosition(500, 21);
	out_velocity.setCharacterSize(15);
	out_velocity.setFont(font);
	out_velocity.setOutlineColor(sf::Color::Black);
	out_velocity.setOutlineThickness(2);

	fisEngine = fl::FisImporter().fromFile("FuzzyCar.fis");
	fisOutput = fisEngine->getOutputVariable(0);

	roc = 0;
}


Demo::~Demo()
{
}

void Demo::handleInput(float dt)
{
	//Handles the player inputs.
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (bar.getPosition().x > (bar.getSize().x / 2))
		{
			bar.move(sf::Vector2f(-250 * dt, 0));
		}
			//Move something Left
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (bar.getPosition().x < (window->getSize().x - (bar.getSize().x / 2)))
		{
			bar.move(sf::Vector2f(250 * dt, 0));
		}
		
		//Move something Right
	}
}

//Demo update function.
void Demo::update(float dt)
{
	fisEngine->getInputVariable(0)->setValue((car.getPosition().x - bar.getPosition().x) / window->getSize().x);
	fisEngine->getInputVariable(1)->setValue(roc);

	fisEngine->process();
	fisOutput = fisEngine->getOutputVariable(0);

	roc += fisOutput->getValue();

	car.move(sf::Vector2f(roc, 0));

	in_distance.setString("Distance = " + std::to_string((car.getPosition().x - bar.getPosition().x) / window->getSize().x));
	in_roc.setString("Rate of Chance = " + std::to_string(roc));
	out_velocity.setString("Velocity = " + std::to_string(fisOutput->getValue()));
	//Do update things
}

//Standard render function
void Demo::render()
{
	beginDraw();

	window->draw(bar);
	window->draw(car);
	window->draw(inputs);
	window->draw(outputs);
	window->draw(in_distance);
	window->draw(in_roc);
	window->draw(out_velocity);
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