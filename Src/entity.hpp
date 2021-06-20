#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include <string>

// class Entity : public sf::Drawable, public sf::Transformable
class Entity
{
protected:
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::Vector2f m_dimensions;
    int m_windowWidth;
    int m_windowHeight;

public:
    Entity(float, float, float, float, float, float, int, int);
    ~Entity() = default;

    [[nodiscard]] const sf::Vector2f& getPositions() const;
    [[nodiscard]] const sf::Vector2f& getVelocity() const;
    [[nodiscard]] const sf::Vector2f& getDimensions() const;
    bool setPos(float, float);
    bool setVel(float, float);
    void virtual Move();
    void virtual Update();
    std::string virtual getType();

    //void draw(sf::RenderTarget&, sf::RenderStates) const override;
};
