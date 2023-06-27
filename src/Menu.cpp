#pragma once
#include "Menu.h"

// Constractor
Menu::Menu()
	: m_window(sf::VideoMode(WindowWidth, WindowHeight), "Mushroom Game", sf::Style::Fullscreen),
	  m_background(Resources::instance().texture(Resources::MenuBackground))
{
	initTitle();
	initButtons();
	srand(static_cast<unsigned>(time(nullptr)));
}

Menu::~Menu()
{
}


// Public Functions
void Menu::run()
{
	while (m_window.isOpen())
	{
		draw();
		updateEvents();
	}
}


// Private Functions
void Menu::draw()
{
	m_window.clear(sf::Color::Black);

	// Draw the screen
	m_window.draw(m_background);
	m_window.draw(title);
	m_window.draw(start);
	m_window.draw(exit);

	m_window.display();
}


void Menu::updateEvents()
{
	sf::Vector2f mousePos;
	mousePos.x = (float)(sf::Mouse::getPosition(m_window).x);
	mousePos.y = (float)(sf::Mouse::getPosition(m_window).y);
	for (auto event = sf::Event(); m_window.pollEvent(event); )
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_window.clear(sf::Color::Cyan);
				m_window.display();

			}
		}



		if (start.getGlobalBounds().contains(mousePos))
		{
			start.setCharacterSize(100);
			start.setOutlineThickness(4);
			start.setPosition(WindowWidth / 2.54f, 400-15);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
				auto c = Controller();
				c.run();
			}
		}
		else
		{
			start.setCharacterSize(80);
			start.setOutlineThickness(0);
			start.setPosition(WindowWidth / 2.54f, 400);
		}

		if (exit.getGlobalBounds().contains(mousePos))
		{
			exit.setCharacterSize(100);
			exit.setOutlineThickness(4);
			exit.setPosition(WindowWidth / 2.4f, 550-15);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
			}
		}
		else
		{
			exit.setCharacterSize(80);
			exit.setOutlineThickness(0);
			exit.setPosition(WindowWidth / 2.4f, 550);
		}
	}
}


void Menu::initTitle()
{
	titleFont.loadFromFile("arial.ttf");
	title.setString("MUSHROOM GAME");
	title.setFont(titleFont);
	title.setCharacterSize(140);
	title.setFillColor(sf::Color::Black);
	title.setOutlineColor(sf::Color::White);
	title.setOutlineThickness(6);
	title.setPosition(40.f, 30);
}


void Menu::initButtons()
{
	buttonsFont.loadFromFile("arial.ttf");

	// start
	start.setString("START");
	start.setFont(buttonsFont);
	start.setFillColor(sf::Color::Red);
	start.setOutlineColor(sf::Color::White);
	start.setCharacterSize(80);
	start.setPosition(WindowWidth / 3.f, 400);

	// help
	exit.setString("EXIT");
	exit.setFont(buttonsFont);
	exit.setFillColor(sf::Color(0, 240, 60));
	exit.setOutlineColor(sf::Color::White);
	exit.setCharacterSize(80);
	exit.setPosition(WindowWidth / 3.f, 550);
}




