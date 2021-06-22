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
    int m_frameRate;
    std::string m_title;
    sf::RenderWindow window;
    Pong pong;

public:
    Game(int, int, int, std::string);
    ~Game() = default;
    Game(const Game&) = default;
    void init();
    void Run();
    void Update();
    void Render();
};

void changeColor();