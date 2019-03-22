#pragma once
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "fl/Headers.h"

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

	sf::RectangleShape bar;
	sf::Sprite car;
	sf::Texture carTex;

	sf::Text outputs;
	sf::Text inputs;
	sf::Text in_distance;
	sf::Text in_roc;
	sf::Text out_velocity;
	sf::Font font;

	fl::Engine* fisEngine;
	fl::OutputVariable* fisOutput;

	float roc;

};

