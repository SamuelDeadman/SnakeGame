#pragma once
#include <SFML/Graphics.hpp>
#include <list>

//4 options for directional movement
enum class EDirection
{
	eNorth,
	eEast,
	eSouth,
	eWest
};
class Snake
{
//can only be seen inside the class
private:
	std::list<sf::Vector2f> m_segments;
	//sf::Vector2f m_position;
	sf::Color m_colour;
	EDirection m_direction{ EDirection::eNorth };
	int m_growAmout{ 4 };
//can be seen outside the class using #include
public:
	Snake(sf::Vector2f pos, sf::Color col);
	void ChangeDirection(EDirection newDirection);
	void Update();
	void Grow(int amout);
	//& is a reference so not to make a copy
	//render 'paints' the snake onto a part of the graphics card ready to be displayed
	void Render(sf::RenderWindow& window);
	sf::Vector2f Getposition() const { return m_segments.front(); };
};

