#pragma once
#include "Victory.h"


// Constractor
Victory::Victory()
	: m_windowWidth(1440), m_windowHeight(900)
{
	initTitle();
	initButton();
}


// Public Functions
void Victory::run(sf::RenderWindow& m_window)
{
	while (m_window.isOpen())
	{
		draw(m_window);
		updateEvents(m_window);
	}
}

// Private Functions
void Victory::draw(sf::RenderWindow& m_window)
{
	m_window.clear(sf::Color::Black);

	// Draw the screen
	m_window.draw(title);
	m_window.draw(newGame);
	m_window.draw(exit);

	m_window.display();
}


void Victory::updateEvents(sf::RenderWindow& m_window)
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
		}

		// newGame
		if (newGame.getGlobalBounds().contains(mousePos))
		{
			newGame.setCharacterSize(100);
			newGame.setOutlineThickness(4);
			newGame.setPosition(((m_windowWidth / 2.f) - (newGame.getGlobalBounds().width / 2.f)), 430 - 15);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
				auto c = Controller();
				c.run();
			}
		}
		else
		{
			newGame.setCharacterSize(80);
			newGame.setOutlineThickness(0);
			newGame.setPosition(((m_windowWidth / 2.f) - (newGame.getGlobalBounds().width / 2.f)), 430);
		}

		// exit
		if (exit.getGlobalBounds().contains(mousePos))
		{
			exit.setCharacterSize(100);
			exit.setOutlineThickness(4);
			exit.setPosition(((m_windowWidth / 2.f) - (exit.getGlobalBounds().width / 2.f)), 600 - 15);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
			}
		}
		else
		{
			exit.setCharacterSize(80);
			exit.setOutlineThickness(0);
			exit.setPosition(((m_windowWidth / 2.f) - (exit.getGlobalBounds().width / 2.f)), 600);
		}
	}
}


void Victory::initTitle()
{
	titleFont.loadFromFile("Pacmania.otf");
	title.setString("VICTORY!");
	title.setFont(titleFont);
	title.setCharacterSize(200);
	title.setFillColor(sf::Color::Yellow);
	title.setOutlineColor(sf::Color::Blue);
	title.setOutlineThickness(6);
	title.setPosition(((m_windowWidth / 2.f) - (title.getGlobalBounds().width / 2.f)), 70);
}

void Victory::initButton()
{
	buttonsFont.loadFromFile("Buttons_Font.otf");

	// new game
	newGame.setString("NEW GAME");
	newGame.setFont(buttonsFont);
	newGame.setFillColor(sf::Color::Red);
	newGame.setOutlineColor(sf::Color::White);
	newGame.setCharacterSize(80);
	newGame.setPosition(((m_windowWidth / 2.f) - (newGame.getGlobalBounds().width / 2.f)), 430);

	// exit
	exit.setString("EXIT");
	exit.setFont(buttonsFont);
	exit.setFillColor(sf::Color(0, 240, 60));
	exit.setOutlineColor(sf::Color::White);
	exit.setCharacterSize(80);
	exit.setPosition(((m_windowWidth / 2.f) - (exit.getGlobalBounds().width / 2.f)), 600);
}
