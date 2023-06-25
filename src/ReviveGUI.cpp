#include "ReviveGUI.h"
#include "Resources.h"

ReviveGUI::ReviveGUI()
	: GUI(Resources::instance().texture(Resources::Revive), sf::Vector2f(700.f, 300.f),
		  sf::Vector2f(1.f, 1.f)), 
	  OK_Button(sf::Vector2f(m_GUI.getPosition() + sf::Vector2f(110.f, 60.f)))
{
}

void ReviveGUI::draw(sf::RenderWindow& window)
{
	window.draw(m_GUI);
	OK_Button.draw(window);
}

void ReviveGUI::handleEvents(sf::RenderWindow& window)
{
	// detect click
	if (OK_Button.wasClicked(window))
	{
		Map::instance().player()->respawn(true);
		m_closed = true;
	}
}
