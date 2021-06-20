#include "ball.hpp"

Ball::Ball(float x, float y, float dX, float dY, float width, float height, int windowWidth, int windowHeight)
	: Entity{x, y, dX, dY, width, height, windowWidth, windowHeight }
	  //m_radius { r },
	{}

/* [[nodiscard]] const float& Ball::getRadius() const
{
	//return m_radius;
}*/

//void Ball::draw(sf::RenderWindow& window)
/*void Ball::draw(sf::RenderTarget&, sf::RenderStates) const
{
	
}*/

void Ball::Move()
{
	m_pos.x += m_vel.x;
	m_pos.y += m_vel.y;
}

void Ball::Update()
{
	Move();
	CheckForWalls();
}

void Ball::CheckForWalls()
{
	if (m_pos.x + (2.0 * m_dimensions.x) + 2.0 > m_windowWidth)
		m_vel.x *= -1.0;

	if (m_pos.x < 2.0)
		m_vel.x *= -1.0;

	if (m_pos.y > 2.0)
		m_vel.y *= -1.0;

	if (m_pos.y + (2.0 * m_dimensions.y) < m_windowHeight)
		m_vel.y *= -1.0;
}

std::string Ball::getType()
{
	return "circ";
}
