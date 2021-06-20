#pragma once

#include "entity.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include <vector>

class Pong 
{
private:
    int m_windowWidth;
    int m_windowHeight;
    
    std::vector<Entity*> m_entities;
    Ball m_ball;
    Paddle m_leftPaddle;
    Paddle m_rightPaddle;

public:
    Pong(int, int);
    ~Pong() = default;
    void init();
    void addEntityPointer(Entity*);
    std::vector<Entity*> getObjects();
};
