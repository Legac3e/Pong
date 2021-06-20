#pragma once

#include <utility>
#include "entity.hpp"

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
    void Update();
    void CheckForWalls();
    std::string getType();
};
