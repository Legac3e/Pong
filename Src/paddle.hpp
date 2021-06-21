#pragma once

#include "entity.hpp"

class Paddle : public Entity
{
private:

public:
    Paddle(float, float, float, float, float, float, int, int);
    ~Paddle() = default;

    //[[nodiscard]] const float& getRadius() const;
    //void draw(sf::RenderWindow&);
    //void draw(sf::RenderTarget&, sf::RenderStates) const override;

    void Move();
    void Update();
    void CheckForCollisions();
    bool CheckTopWall();
    bool CheckBottomWall();
};
