#include "Input.h"
#include "fl/Headers.h"
#include <SFML/Graphics.hpp>

//For Loading in FIS file.


//This shit goes in update function, saving here for future use
//int main(int argc, char **argv)
//{
//fl::Engine* engine = fl::FisImporter().fromFile("MatL.fis");
//
//	engine->getInputVariable(0)->setValue(2);
//	engine->getInputVariable(1)->setValue(-1);
//
//	engine->process();
//
//	fl::OutputVariable* output = engine->getOutputVariable(0);
//
//	printf("%f\n", output->getValue());
//
//	system("PAUSE");
//}

using namespace std;

//Completely reworked project. Only borrowing the Input class from previous submission.

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 300), "Pong Server");
	Input input;
	sf::Clock clock;
	float deltaTime;

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

		deltaTime = clock.restart().asSeconds();

	}
}