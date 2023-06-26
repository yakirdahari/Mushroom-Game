#pragma once

#include "GUI.h"
#include "OkButton.h"

class ReviveGUI : public GUI
{
public:
	ReviveGUI();

	virtual void draw(sf::RenderWindow& window) const override;
	virtual void handleEvents(sf::RenderWindow& window) override;

private:
	OkButton OK_Button;
};