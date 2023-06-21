#pragma once

#include "Map.h"

class Info
{
public:
    static Info& instance();
    void draw(sf::RenderWindow& window);
    void update(const Data& data);

    Info(const Info&) = delete;
    Info& operator=(const Info&) = delete;

private:
    Info();
    void init(sf::Text& text, const int& size, const sf::Vector2f& position);
    void init(sf::RectangleShape& bar, const sf::Color& color,
              const sf::Vector2f& position, const sf::Vector2f& size);
    
    // Font
    sf::Font infoFont;

    // Text
    sf::Text level;
    sf::Text HP;
    sf::Text MP;
    sf::Text EXP;
    sf::Text job;

    // Graphics
    sf::Sprite panel;
    sf::RectangleShape HPbar;
    sf::RectangleShape MPbar;
    sf::RectangleShape EXPbar;
    sf::RectangleShape background1;
    sf::RectangleShape background2;
    sf::RectangleShape background3;
};
