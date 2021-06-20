#include "paddle.hpp"

Paddle::Paddle(float x, float y, float dX, float dY, float width, float height, int windowWidth, int windowHeight)
	: Entity{x, y, dX, dY, width, height, windowWidth, windowHeight }
	{}

/*void Ball::draw(sf::RenderTarget&, sf::RenderStates) const
{

}*/

void Paddle::Move()
{
	m_pos.y += m_vel.y;
}

void Paddle::Update()
{
	Move();
	CheckForWalls();
}

void Paddle::CheckForWalls()
{
	if (m_pos.y > 2.0)
		m_vel.y *= -1.0;

	if (m_pos.y + (m_dimensions.y) < m_windowHeight)
		m_vel.y *= -1.0;
}
