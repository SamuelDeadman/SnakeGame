#include "Snake.h"

constexpr float StepSize{ 20.0f };

Snake::Snake(sf::Vector2f pos, sf::Color col) :  m_colour(col)
{
	m_segments.push_back(pos);
}
//draws the snake with these values 
void Snake::Render(sf::RenderWindow& window)
{
	sf::CircleShape shape(StepSize/2.0f);
	shape.setFillColor(m_colour);
	for (sf::Vector2f pos : m_segments) 
	{
		shape.setPosition(pos);
		window.draw(shape);
	}
	window.draw(shape);
}
//every 'tick' we check to see what is the most recent key prees out of the 4 options
void Snake::Update()
{
	//backup controls worst system as the keybread update can not not read/missed
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		ChangeDirection(EDirection::eNorth);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		ChangeDirection(EDirection::eWest);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		ChangeDirection(EDirection::eSouth);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		ChangeDirection(EDirection::eEast);*/
	sf::Vector2f pos = m_segments.front();
	switch (m_direction)
	{
	case EDirection::eNorth:
		pos.y -= StepSize;
		break;
	case EDirection::eEast:
		pos.x += StepSize;
		break;
	case EDirection::eSouth:
		pos.y += StepSize;
		break;
	case EDirection::eWest:
		pos.x -= StepSize;
		break;
	default:
		break;
	}
	//add then romoves segment in front and back of the snake
	//wount reomve the back end of the smake if the snake needs to grow via growAmout
	m_segments.push_front(pos);
	if (m_growAmout == 0)
		m_segments.pop_back();
	else
		m_growAmout--;
}
//takes the score vaule of the food and adds that to the amout to grow by
void Snake::Grow(int amout)
{
	m_growAmout = m_growAmout + amout;
}
//gives the current direction of the snake
void Snake::ChangeDirection(EDirection newDirection) 
{
	m_direction = newDirection;
}

