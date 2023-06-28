#include "ArrivalGUI.h"
#include "Resources.h"

ArrivalGUI::ArrivalGUI()
	: GUI(Resources::instance().texture(Resources::Arrival_Texture), sf::Vector2f(185.f, 250.f),
		sf::Vector2f(1.1f, 1.1f)), m_sound(Resources::instance().sound(Resources::Arrival))
{
	m_sound.play();
}

void ArrivalGUI::draw(sf::RenderWindow& window) const
{
	window.draw(m_GUI);
}

void ArrivalGUI::handleEvents(sf::RenderWindow& window)
{
}
