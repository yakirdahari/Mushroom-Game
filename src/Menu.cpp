#pragma once
#include "Menu.h"


// Constractor
Menu::Menu()
	: m_windowWidth(1440), m_windowHeight(900),
	  m_window(sf::VideoMode(1440, 900), "Pacman", sf::Style::Close),
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
	m_window.draw(help);
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
			start.setPosition(((m_windowWidth / 2.f) - (start.getGlobalBounds().width / 2.f)), 400-15);
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
			start.setPosition(((m_windowWidth / 2.f) - (start.getGlobalBounds().width / 2.f)), 400);
		}

		if (help.getGlobalBounds().contains(mousePos))
		{
			help.setCharacterSize(100);
			help.setOutlineThickness(4);
			help.setPosition(((m_windowWidth / 2.f) - (help.getGlobalBounds().width / 2.f)), 550-15);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//m_window.close();
				//auto h = Help();
				//h.run();
				Menu::~Menu();
			}
		}
		else
		{
			help.setCharacterSize(80);
			help.setOutlineThickness(0);
			help.setPosition(((m_windowWidth / 2.f) - (help.getGlobalBounds().width / 2.f)), 550);
		}

		if (exit.getGlobalBounds().contains(mousePos))
		{
			exit.setCharacterSize(100);
			exit.setOutlineThickness(4);
			exit.setPosition(((m_windowWidth / 2.f) - (exit.getGlobalBounds().width / 2.f)), 700-15);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
			}
		}
		else
		{
			exit.setCharacterSize(80);
			exit.setOutlineThickness(0);
			exit.setPosition(((m_windowWidth / 2.f) - (exit.getGlobalBounds().width / 2.f)), 700);
		}
	}
}


void Menu::initTitle()
{
	titleFont.loadFromFile("arial.ttf");
	title.setString("MUSHROOM GAME");
	title.setFont(titleFont);
	title.setCharacterSize(160);
	title.setFillColor(sf::Color::Black);
	title.setOutlineColor(sf::Color::White);
	title.setOutlineThickness(6);
	title.setPosition(((m_windowWidth / 2.f) - (title.getGlobalBounds().width / 2.f)), 30);
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
	start.setPosition(((m_windowWidth / 2.f) - (start.getGlobalBounds().width / 2.f)), 400);

	// help
	help.setString("HELP");
	help.setFont(buttonsFont);
	help.setFillColor(sf::Color(0, 240, 60));
	help.setOutlineColor(sf::Color::White);
	help.setCharacterSize(80);
	help.setPosition(((m_windowWidth / 2.f) - (help.getGlobalBounds().width / 2.f)), 550);

	// exit
	exit.setString("EXIT");
	exit.setFont(buttonsFont);
	exit.setFillColor(sf::Color::Blue);
	exit.setOutlineColor(sf::Color::White);
	exit.setCharacterSize(80);
	exit.setPosition(((m_windowWidth / 2.f) - (exit.getGlobalBounds().width / 2.f)), 700);
}




