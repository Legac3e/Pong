#include "pong.hpp"

float ballSpeedX = 5.0f;
float ballSpeedY = 8.0f;
float ballWidthHeight = 15.0f;

float paddleSpeedX = 0.0f;
float paddleSpeedY = 5.0f;
float paddleWidth = 15.0f;
//int paddleHeight = m_windowHeight / 6.0f;
float paddleHeight = 240.0f;

Pong::Pong(int winWidth, int winHeight)
	: m_windowWidth{ winWidth },
	m_windowHeight{ winHeight },
	m_ball{ float(m_windowWidth) / 2.0, (float(m_windowHeight) / 2.0) + 240.0, ballSpeedX, ballSpeedY, ballWidthHeight, ballWidthHeight, m_windowWidth, m_windowHeight },
	m_leftPaddle { 20, float(m_windowHeight) / 2.0, paddleSpeedX, paddleSpeedY, paddleWidth, paddleHeight, m_windowWidth, m_windowHeight},
	m_rightPaddle { m_windowWidth - 45, float(m_windowHeight) / 2.0, paddleSpeedX, paddleSpeedY, paddleWidth, paddleHeight, m_windowWidth, m_windowHeight}
{init(); }

void Pong::init()
{
	//addEntityPointer(&m_topWall);
	//addEntityPointer(&m_bottomWall);
	addEntityPointer(m_entities, &m_ball);
	addEntityPointer(m_balls, &m_ball);

	/*addEntityPointer(m_entities, &m_leftPaddle);
	addEntityPointer(m_entities, &m_rightPaddle);

	addEntityPointer(m_paddles, &m_leftPaddle);
	addEntityPointer(m_paddles, &m_rightPaddle);*/

	//addEntityPointer(&m_net);
}

void Pong::addEntityPointer(std::vector<Entity*>& entityVec, Entity* e)
{
	entityVec.emplace_back(e);
}

std::vector<Entity*> Pong::getObjects()
{
	return m_entities;
}

std::vector<Entity*> Pong::getPaddles()
{
	return m_paddles;
}

std::vector<Entity*> Pong::getBalls()
{
	return m_balls;
}

std::vector<Entity*> Pong::getWalls()
{
	return m_walls;
}
