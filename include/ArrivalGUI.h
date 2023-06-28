#pragma once

#include "GUI.h"

class ArrivalGUI : public GUI
{
public:
	ArrivalGUI();

	virtual void draw(sf::RenderWindow& window) const override;
	virtual void handleEvents(sf::RenderWindow& window) override;

private:
	sf::Sound m_sound;
};