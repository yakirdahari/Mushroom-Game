#include "Menu.h"

// Constractor
Menu::Menu()
	: m_window(sf::VideoMode(WindowWidth, WindowHeight), "Mushroom Game", sf::Style::Fullscreen),
	  m_menuSprite(Resources::instance().texture(Resources::MenuBackground))
{
	m_menuSprite.setScale(0.72f, 0.72f);
	initTitle();
	initButtons();
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

void Menu::draw()
{
	m_window.clear(sf::Color::Black);

	// Draw the screen
	m_window.draw(m_menuSprite);
	m_window.draw(title1);
	m_window.draw(title2);
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
			start.setCharacterSize(77);
			start.setPosition(510 - 15, 370 - 10);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
				auto c = Controller();
				c.run();
			}
		}
		else
		{
			start.setCharacterSize(67);
			start.setPosition(510, 370);
		}
		if (help.getGlobalBounds().contains(mousePos))
		{
			help.setCharacterSize(77);
			help.setPosition(550 - 10, 470 - 10);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
				auto h = HelpScreen(WindowWidth, WindowHeight);
				h.run();
			}
		}
		else
		{
			help.setCharacterSize(67);
			help.setPosition(550, 470);
		}

		if (exit.getGlobalBounds().contains(mousePos))
		{
			exit.setCharacterSize(77);
			exit.setPosition(550 - 10, 570 - 10);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_window.close();
			}
		}
		else
		{
			exit.setCharacterSize(67);
			exit.setPosition(550, 570);
		}
	}
}

void Menu::initTitle()
{
	titleFont.loadFromFile("Blueberry.ttf");

	title1.setString("MUSHROOM");
	title1.setFont(titleFont);
	title1.setCharacterSize(130);
	title1.setFillColor(sf::Color::Black);
	title1.setPosition(80, 30);

	title2.setString("GAME");
	title2.setFont(titleFont);
	title2.setCharacterSize(130);
	title2.setFillColor(sf::Color::Black);
	title2.setPosition((((title1.getGlobalBounds().width + 80) / 2.f) - (title2.getGlobalBounds().width / 2.f)), 180);
}

void Menu::initButtons()
{
	buttonsFont.loadFromFile("Blueberry.ttf");

	// start
	start.setString("START");
	start.setFont(buttonsFont);
	start.setFillColor(sf::Color::Black);
	start.setCharacterSize(67);
	start.setPosition(510, 370);

	// help
	help.setString("HELP");
	help.setFont(buttonsFont);
	help.setFillColor(sf::Color::Black);
	help.setCharacterSize(67);
	help.setPosition(550, 470);

	// exit
	exit.setString("EXIT");
	exit.setFont(buttonsFont);
	exit.setFillColor(sf::Color::Black);
	exit.setCharacterSize(67);
	exit.setPosition(550, 570);
}

