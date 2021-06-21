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
    //std::vector<std::vector<Entity*>> m_entities;
    std::vector<Entity*> m_paddles;
    std::vector<Entity*> m_walls;
    std::vector<Entity*> m_balls;
    Ball m_ball;
    Paddle m_leftPaddle;
    Paddle m_rightPaddle;

public:
    Pong(int, int);
    ~Pong() = default;
    void init();
    void addEntityPointer(std::vector<Entity*>&, Entity*);
    std::vector<Entity*> getObjects();
    std::vector<Entity*> getPaddles();
    std::vector<Entity*> getWalls();
    std::vector<Entity*> getBalls();
};
