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
	CheckForCollisions();
}

bool Paddle::CheckTopWall()
{
	if (m_pos.y + (m_dimensions.y) < m_windowHeight)
		return true;

	return false;
}

bool Paddle::CheckBottomWall()
{
	if (m_pos.y > 0.0)
		return true;

	return false;
}

void Paddle::CheckForCollisions()
{
	if(CheckBottomWall())
		m_vel.y *= -1.0;
	else if (CheckTopWall())
		m_vel.y *= -1.0;
}
