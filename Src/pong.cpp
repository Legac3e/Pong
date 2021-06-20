#include "pong.hpp"

Pong::Pong(int winWidth, int winHeight)
	: m_windowWidth{ winWidth },
	m_windowHeight{ winHeight },
	m_ball{ float(m_windowWidth) / 2.0, float(m_windowHeight) / 2.0, 10.0f, 7.5f, 7.5f, 7.5f, m_windowWidth, m_windowHeight },
	m_leftPaddle { 20, float(m_windowHeight) / 2.0, 0.0f, 5.0f, 15.0f, m_windowHeight / 6.0f,  m_windowWidth, m_windowHeight},
	m_rightPaddle{ m_windowWidth - 45, float(m_windowHeight) / 2.0, 0.0f, 5.0f, 15.0f, m_windowHeight / 6.0f,  m_windowWidth, m_windowHeight}
	{}

void Pong::init()
{
	/*addEntityPointer(&m_topWall);
	addEntityPointer(&m_bottomWall);*/
	addEntityPointer(&m_ball);

	//addEntityPointer(&m_leftPaddle);
	//addEntityPointer(&m_rightPaddle);

	//addEntityPointer(&m_net);
}

void Pong::addEntityPointer(Entity* e)
{
	m_entities.emplace_back(e);
}

std::vector<Entity*> Pong::getObjects()
{
	return m_entities;
}