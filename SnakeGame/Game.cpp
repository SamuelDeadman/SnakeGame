#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
#include <ctime>

void Game::Run()
{
	sf::RenderWindow window(sf::VideoMode(screenwidth, screenheigh), "C++ Snake ICA : U0018197");
	//uses the clock to get a 'radnom' seed for rand (only called once per game)
	srand(time(NULL));

	// We can still output to the console window
	std::cout << "SnakeGame: Starting" << std::endl;
	//pointer *
	std::vector<Snake*> Snakes;

	for (int i = 0; i < 20; i++)
	{
		sf::Vector2f pos;
		//sets the snaked postion aligned on a 20 grid
		pos.x = (float)(rand() % 40) * 20;
		pos.y = (float)(rand() % 30) * 20;
		Snakes.push_back(new Snake(pos, sf::Color::Blue));
	}
	/*Snake snake1(sf::Vector2f(200,1), sf::Color::Blue);*/
	// Main loop that continues until we call window.close()
	while (window.isOpen())
	{
		// Handle any pending SFML events
		// These cover keyboard, mouse,joystick etc.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					Snakes.front()->ChangeDirection(EDirection::eWest);
					/*std::cout << "test1" << std::endl;*/
					break;
				case sf::Keyboard::W:
					Snakes.front()->ChangeDirection(EDirection::eNorth);
					break;
				case sf::Keyboard::S:
					Snakes.front()->ChangeDirection(EDirection::eSouth);
					break;
				case sf::Keyboard::D:
					Snakes.front()->ChangeDirection(EDirection::eEast);
					break;
				break;
			default:
				break;
			}
		}

		sf::Clock Snakeclock;
		// main snake componet direction and growuth 
		for (Snake* s : Snakes)
			s->Update();

		if (rand() % 10 == 5) 
		{
			for (int i = 0; i < 5; i++)
			{
				//finds food that is not alive
				if (!m_food[i].IsAlive()) 
				{
					sf::Vector2f pos;

					pos.x = (float)(rand() % 40) * 20;
					pos.y = (float)(rand() % 30) * 20;
					//gives food a position
					m_food[i].Spawn(pos);
					break;
				}
			}
		}

		//add foods to the game (max 5 random scores + colours)
		for (Snake* s : Snakes)
		{
			for (int i = 0; i < 5; i++) 
			{
				if (m_food[i].IsAlive() && s->Getposition() == m_food[i].Getposition())
				{
					//collided
					m_food[i].Die();
					s->Grow(m_food[i].GetValue());
					score = score + m_food[i].GetValue();
					//outputs the score into console 
					std::cout << score << std::endl;
				}
			}
		}

		//could use time at this point for movment - advied to use the sf clock
		// We must clear the window each time around the loop
		window.clear();
		/*snake1.Render(window);*/
		//draws the snakes
		for (Snake* s : Snakes)
			s->Render(window);

		for (int i = 0; i < 5; i++) 
		{
			if (m_food[i].IsAlive())
				m_food[i].Render(window);
		}
		
		window.display();
		//main game clock/tick
		//the higher the score the 'faster' the snake moves
		while (Snakeclock.getElapsedTime().asMilliseconds() < 500 - score*10);
		clock++;

		//logic to check for collision with wall - pushis snake i other direction
			// :(
			// x <0 - 800> 
			// y <0 - 600>
			//const Vector2f & sf::Transformable::getPosition() const <
		//check the position of the player snakes head position within the windows confines
		for (int i = 0; i < 1; i++)
		{
			if (Snakes[i]->Getposition().y <= 0)
			{
				Snakes.front()->ChangeDirection(EDirection::eSouth);
				//works
				std::cout << "moved south score losted" << std::endl;
				score = score - 2;
			}
			else
			{
				if (Snakes[i]->Getposition().y >= screenheigh)
				{
					Snakes.front()->ChangeDirection(EDirection::eNorth);
					std::cout << "moved north score losted" << std::endl;
					score = score - 2;
				}
				else
				{
					if (Snakes[i]->Getposition().x <= 0)
					{
						Snakes.front()->ChangeDirection(EDirection::eEast);
						std::cout << "moved east score losted" << std::endl;
						score = score - 2;
					}
					else
					{
						if (Snakes[i]->Getposition().x >= screenwidth)
						{
							Snakes.front()->ChangeDirection(EDirection::eWest);
							std::cout << "moved west score losted" << std::endl;
							score = score - 2;
							break;
						}
					}		
				}
			}
		}

		//will end the game aproxximlity 135 seconds after start  
		if (clock > 270) 
		{
			window.close();
		}
		Snakeclock.restart();
	}
	/*std::cout << "Final Score" + score << std::endl;*/
	std::cout << "SnakeGame: Finished" << std::endl;
	//calls deconstructio for ever snake as to no reserve member no being used
	for (Snake* s : Snakes)
		delete s;	
	}
}

