#include "ReviveGUI.h"
#include "Resources.h"

ReviveGUI::ReviveGUI()
	: GUI(Resources::instance().texture(Resources::Revive), sf::Vector2f(450.f, 200.f),
		  sf::Vector2f(1.f, 1.f)), 
	  OK_Button(sf::Vector2f(m_GUI.getPosition() + sf::Vector2f(120.f, 115.f)))
{
}

void ReviveGUI::draw(sf::RenderWindow& window) const
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
