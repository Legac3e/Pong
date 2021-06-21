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

void Ball::Update(const std::vector<Entity*>& eVec)
{
	Move();
	CheckForCollisions(eVec);
}


bool Ball::CheckLeftWall()
{
	if (m_pos.x < 2.0)
		return true;

	return false;
}

bool Ball::CheckRightWall()
{
	if (m_pos.x + (2.0 * m_dimensions.x) + 2.0 > m_windowWidth)
		return true;

	return false;
}

bool Ball::CheckTopWall()
{
	if (m_pos.y < 2.0)
		return true;

	return false;
}

bool Ball::CheckBottomWall()
{
	if (m_pos.y + (2.0 * m_dimensions.y) > m_windowHeight)
		return true;

	return false;
}

bool Ball::CheckLeftPaddle(const Entity* e)
{
	// check right side of paddle
	if (m_pos.x <= e->getPositions().x + e->getDimensions().x)
		// check top and bottom of paddle
		if (m_pos.y + (2.0 * m_dimensions.y) >= e->getPositions().y && m_pos.y <= e->getPositions().y + e->getDimensions().y)
		//if (m_pos.y < e->getPositions().y && m_pos.y + (2.0 * m_dimensions.y) > e->getPositions().y + e->getDimensions().y)
			return true;

	return false;
}

bool Ball::CheckRightPaddle(const Entity* e)
{
	// check left side of paddle
	if (m_pos.x + (2.0 * m_dimensions.x) >= e->getPositions().x)
		// check top and bottom of paddle
		if (m_pos.y + (2.0 * m_dimensions.y) >= e->getPositions().y && m_pos.y <= e->getPositions().y + e->getDimensions().y)
			return true;

	return false;
}

void Ball::CheckForCollisions(const std::vector<Entity*>& eVec)
{
	
	if (CheckLeftWall())
		m_vel.x *= -1.0;
	else if (CheckRightWall())
		m_vel.x *= -1.0;

	if (CheckTopWall())
		m_vel.y *= -1.0;
	else if (CheckBottomWall())
		m_vel.y *= -1.0;

	/*if (CheckLeftPaddle(eVec[0]))
		m_vel.x *= -1.0;
	else if (CheckRightPaddle(eVec[1]))
		m_vel.x *= -1.0;*/
}

std::string Ball::getType()
{
	return "circle";
}
