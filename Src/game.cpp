#include "game.hpp"

bool redSwap = true;
bool greenSwap = true;
bool blueSwap = true;
uint8_t red = 0;
uint8_t green = 0;
uint8_t blue = 100;
uint8_t counter = 0;

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

void Game::init()
{
    window.setFramerateLimit(m_frameRate);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    window.clear(sf::Color(0, 0, 0));
}

void Game::Run()
{
    while (window.isOpen())
    {
        Update();
        Render();
    }
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

void Game::Render()
{
    // window.clear(sf::Color(0, 0, 0));
    changeColor();

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

    window.display();
}

void changeColor()
{
    if (red <= 0)
    {
        red = 0;
        redSwap = true;
    }
    else if (red >= 255)
    {
        red = 255;
        redSwap = false;
    }

    if (green <= 1)
    {
        green = 0;
        greenSwap = true;
    }
    else if (green >= 254)
    {
        green = 255;
        greenSwap = false;
    }

    if (blue <= 150)
    {
        blue = 150;
        blueSwap = true;
    }
    else if (blue >= 255)
    {
        blue = 255;
        blueSwap = false;
    }

    counter++;

    switch (counter % 3)
    {
    case 0:
        if (redSwap)
            red += 1;
        else
            red -= 1;

        break;
    case 1:
        if (greenSwap)
            green += 2;
        else
            green -= 2;

        break;
    case 2:
        if (blueSwap)
            blue += 1;
        else
            blue -= 1;

        break;

    default:
        red += 1;
        break;
    }

    std::cout << int(red) << " " << int(green) << " " << int(blue) << std::endl;
}
