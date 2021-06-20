#pragma once

#include "pong.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Game
{
private:
    int m_windowWidth;
    int m_windowHeight;
    sf::RenderWindow window;
    Pong pong;

public:
    Game(int, int);
    ~Game() = default;
    Game(const Game&) = default;
    void Run();
    void Update();
    void Render();
};