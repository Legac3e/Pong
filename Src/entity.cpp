#include "entity.hpp"

Entity::Entity(float x, float y, float dX, float dY, float width, float height, int windowWidth, int windowHeight)
	: m_pos{ x, y },
	m_vel{ dX, dY },
	m_dimensions{ width, height },
	m_windowWidth{ windowWidth },
	m_windowHeight { windowHeight }
	{}

[[nodiscard]] const sf::Vector2f& Entity::getPositions() const
{
	return m_pos;
}

[[nodiscard]] const sf::Vector2f& Entity::getVelocity() const
{
	return m_vel;
}

[[nodiscard]] const sf::Vector2f& Entity::getDimensions() const
{
	return m_dimensions;
}


bool Entity::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;

	return true;
}

bool Entity::setVel(float dX, float dY)
{
	m_vel.x += dX;
	m_vel.y += dY;

	return true;
}

/*void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}*/

void Entity::Move()
{
	m_pos.x += m_vel.x;
	m_pos.y += m_vel.y;
}

void Entity::Update()
{
	Entity::Move();
}

std::string Entity::getType()
{
	return "rect";
}