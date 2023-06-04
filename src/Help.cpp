#pragma once
#include "Help.h"


// Constractor
Help::Help()
	: m_windowWidth(1440), m_windowHeight(900)
{
	initTitle();
	initInstructions();
	initButton();
	//run();
}


// Public Functions
void Help::run(sf::RenderWindow& m_window)
{
	while (m_window.isOpen())
	{
		draw(m_window);
		updateEvents(m_window);
	}
}


// Private Functions
void Help::draw(sf::RenderWindow& m_window)
{
	m_window.clear(sf::Color::Black);

	// Draw the screen
	m_window.draw(title);
	m_window.draw(row1);
	m_window.draw(row2);
	m_window.draw(row3);
	m_window.draw(row4);
	m_window.draw(row5);
	m_window.draw(back);

	m_window.display();
}


void Help::updateEvents(sf::RenderWindow& m_window)
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

		if (back.getGlobalBounds().contains(mousePos))
		{
			back.setCharacterSize(100);
			back.setOutlineThickness(4);
			back.setPosition((m_windowWidth - 315.f), (m_windowHeight - 155.f));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
				auto m = Menu();
				m.run();
			}
		}
		else
		{
			back.setCharacterSize(80);
			back.setOutlineThickness(0);
			back.setPosition((m_windowWidth - 290), (m_windowHeight - 140));
		}
	}
}


void Help::initTitle()
{
	titleFont.loadFromFile("Pacmania.otf");
	title.setString("Instructions");
	title.setFont(titleFont);
	title.setCharacterSize(170);
	title.setFillColor(sf::Color::Yellow);
	title.setOutlineColor(sf::Color::Blue);
	title.setOutlineThickness(5);
	title.setPosition(((m_windowWidth / 2.f) - (title.getGlobalBounds().width / 2.f)), 30);
}


void Help::initButton()
{
	buttonsFont.loadFromFile("Buttons_Font.otf");

	back.setString("BACK");
	back.setFont(buttonsFont);
	back.setFillColor(sf::Color::Red);
	back.setOutlineColor(sf::Color::White);
	back.setCharacterSize(80);
	back.setPosition((m_windowWidth - 290), (m_windowHeight - 140));
}

void Help::initInstructions()
{
	buttonsFont.loadFromFile("Buttons_Font.otf");

	row1.setString("MOVEMENT: keyboard arrows or A, D, W, S (space to stop)");
	row1.setFont(buttonsFont);
	row1.setFillColor(sf::Color::White);
	row1.setPosition(90.f, 350.f);
	row1.setCharacterSize(35);

	row2.setString("GOAL: Eat all the cookies before the time runs out and move to next stage");
	row2.setFont(buttonsFont);
	row2.setFillColor(sf::Color::White);
	row2.setPosition(90.f, 430.f);
	row2.setCharacterSize(35);

	row3.setString("Pacman has 3 lives, once caught by a demon he loses a life");
	row3.setFont(buttonsFont);
	row3.setFillColor(sf::Color::White);
	row3.setPosition(90.f, 510.f);
	row3.setCharacterSize(35);

	row4.setString("SUPER PACMAN: In this state, Pacman can eat the demons (Obtained from gifts)");
	row4.setFont(buttonsFont);
	row4.setFillColor(sf::Color::White);
	row4.setPosition(90.f, 590.f);
	row4.setCharacterSize(35);

	row5.setString("DOORS: Opened by a obtaining a key");
	row5.setFont(buttonsFont);
	row5.setFillColor(sf::Color::White);
	row5.setPosition(90.f, 670.f);
	row5.setCharacterSize(35);
}
