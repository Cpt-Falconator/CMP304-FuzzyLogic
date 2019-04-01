#include "Input.h"
#include "Demo.h"
#include "fl/Headers.h"
#include <SFML/Graphics.hpp>


//For Loading in FIS file.

//Completely reworked project. Only borrowing the Input class from previous submission.

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Furry Car Demo");
	Input input;
	Demo demo(&window, &input);
	sf::Clock clock;
	float deltaTime;
	int stage;

	std::cout << "Please select which stage to test:" << std::endl;
	std::cout << "Stage (1) - Manual Input." << std::endl;
	std::cout << "Stage (2) - Interactive Input." << std::endl;
	std::cin >> stage;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

				//Handles events of the key being pressed
			case sf::Event::KeyPressed:
				input.setKeyDown(event.key.code);
				break;

				//Handles events of the key being released
			case sf::Event::KeyReleased:
				input.setKeyUp(event.key.code);
			default:
				break;
			}

		}
		switch (stage)
		{
		case 1:
			fl::Engine* fisEngine;
			fisEngine = fl::FisImporter().fromFile("FuzzyCar.fis");
			fl::OutputVariable* fisOutput;
			float distance, cspeed;
			std::cout << "Input 1 - Please enter the distance from the line." << std::endl;
			std::cout << "(Range: -10, 10)" << std::endl;
			std::cin >> distance;
			fisEngine->getInputVariable(0)->setValue(distance);
			std::cout << "Input 2- Please enter current speed." << std::endl;
			std::cin >> cspeed;
			fisEngine->getInputVariable(1)->setValue(cspeed);
			fisEngine->process();
			fisOutput = fisEngine->getOutputVariable(0);
			std::cout << "Output - Velocity: " << fisOutput->getValue() << std::endl;
			std::cout << "Negative value is acceleration to the left, Positive value is acceleration to the right." << std::endl;
			break;
		case 2:
			deltaTime = clock.restart().asSeconds();
			demo.handleInput(deltaTime);
			demo.update(deltaTime);
			demo.render();
			break;
		default:
			std::cout << "Invalid stage, please enter a valid input!" << std::endl;
			break;
	}
	}
}