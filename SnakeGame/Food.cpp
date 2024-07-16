#include "Food.h"

void Food::Render(sf::RenderWindow& window)
{
	sf::CircleShape shape(10.0f);
	shape.setFillColor(sf::Color(colour1, colour2, colour3));
	shape.setPosition(m_position);
	window.draw(shape);
}
void Food::Spawn(sf::Vector2f pos)
{	//random values of RGB for each new food
	colour1 = rand() % 255;
	colour2 = rand() % 255;
	colour3 = rand() % 255;
	m_position = pos;
	//random score from 0 to 4 + 1
	m_score = rand() % 5 + 1;
	//sets contition to true so the food is seached for in game for test conditions
	m_alive = true;
}
