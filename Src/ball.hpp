#pragma once

#include <utility>
#include "entity.hpp"
#include "paddle.hpp"

class Ball : public Entity
{
private:
    //float m_radius;

public:
    Ball(float, float, float, float, float, float, int, int);
    ~Ball() = default;

    //[[nodiscard]] const float& getRadius() const;
    //void draw(sf::RenderWindow&);
    //void draw(sf::RenderTarget&, sf::RenderStates) const override;

    void Move();
    void Update(const std::vector<Entity*>&) override;
    void CheckForCollisions(const std::vector<Entity*>&);
    bool CheckLeftWall();
    bool CheckRightWall();
    bool CheckTopWall();
    bool CheckBottomWall();
    bool CheckLeftPaddle(const Entity*);
    bool CheckRightPaddle(const Entity*);
    std::string getType();
};
