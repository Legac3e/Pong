#include "game.hpp"

int8_t red = 100;
int8_t green = 255;
int8_t blue = 150;
int8_t counter = 0;

Game::Game(int winWidth = 1920, int winHeight = 1080, int frameRate = 120, std::string title = "Pong")
    : m_windowWidth{ winWidth },
    m_windowHeight{ winHeight },
    m_frameRate { frameRate },
    m_title{ title },
    window{ sf::VideoMode(m_windowWidth, m_windowHeight), "SFML works!"},
    pong{ winWidth, winHeight }
    {
        init(); 
    }

void Game::Run()
{
    while (window.isOpen())
    {
        Update();
        Render();
    }
}

void Game::init()
{
    window.setFramerateLimit(m_frameRate);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    //window.clear(sf::Color(0, 0, 0));
}

void Game::Render()
{
    //window.clear(sf::Color(0, 0, 0));

    //sf::CircleShape circleShape(1.0f);
    //sf::RectangleShape rectangleShape(1.0f);

    for (const auto& i : pong.getObjects())
    {
        std::string type = i->getType();
        if (type == "circle")
        {
            sf::CircleShape circleShape(i->getDimensions().x);
            circleShape.setPosition(i->getPositions().x, i->getPositions().y);
            circleShape.setFillColor(sf::Color(red, green, blue));
            window.draw(circleShape);
        } else if (type == "rectangle")
        {
            sf::RectangleShape shape(i->getDimensions());
            shape.setPosition(i->getPositions().x, i->getPositions().y);
            shape.setFillColor(sf::Color(red, green, blue));
            window.draw(shape);
        }

    }

    counter++;
    if (counter >= 50)
    {
        red += 2;
        green += 3;
        blue += 4;
        counter = 0;
    }

    window.display();
}

void Game::Update()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    for (const auto& i : pong.getBalls())
    {
        const auto& paddles = pong.getPaddles();
        i->Update(paddles);
    }

}