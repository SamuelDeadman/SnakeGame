#pragma once
#include <SFML/Graphics.hpp>

class Food
{
private:
	sf::Vector2f m_position;
	//default values are needed
	int m_score{ 0 };
	bool m_alive{ false };
	int colour1{ 0 };
	int colour2{ 0 };
	int colour3{ 0 };
public:
	// a check to see it the food is draw
	bool IsAlive() const { return m_alive; }
	void Render(sf::RenderWindow& window);
	//sets the position of the food
	void Spawn(sf::Vector2f pos);
	//sets the alive status to false
	void Die() { m_alive = false; }
	//asks if the food is alive or not
	bool GetAlive() const { return m_alive; }
	//returns the position of the food (used for snake growing/scoring)
	sf::Vector2f Getposition() const { return m_position; }
	//gives the score value of the food to add to score and add the growth
	int GetValue() const { return m_score; }
};

