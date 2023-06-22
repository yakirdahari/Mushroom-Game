#include "MonsterInfo.h"

MonsterInfo::MonsterInfo(const Data& data)
{
	infoFont.loadFromFile("Buttons_Font.otf");

	init(name, 12);
	init(nameBackground, sf::Color(0.f, 0.f, 0.f, 199.f), sf::Vector2f(40.f, 7.f));

	init(level, 10);
	init(levelBackground, sf::Color(0.f, 0.f, 0.f, 199.f), sf::Vector2f(40.f, 5.f));

	init(HPbar,         sf::Color(67, 233, 22), sf::Vector2f(48.f, 5.f));
	init(HPbackground1, sf::Color::White, sf::Vector2f(50.f, 7.f));
	init(HPbackground2, sf::Color::Black, sf::Vector2f(48.f, 5.f));	
}

void MonsterInfo::update(const Data& data, const sf::Vector2f& location)
{
	HPbar.setSize(sf::Vector2f(48.f * (data.HP / static_cast<float>(data.MaxHP)), 5.f));
	HPbar.setPosition(location - sf::Vector2f(22.f, 50.f));
	HPbackground1.setPosition(location - sf::Vector2f(23.f, 51.f));
	HPbackground2.setPosition(location - sf::Vector2f(22.f, 50.f));
	name.setPosition(location + sf::Vector2f(-25.f, 32.f));
	nameBackground.setPosition(location + sf::Vector2f(-26.f, 31.f));
	level.setPosition(location + sf::Vector2f(-55.f, 32.f));
	levelBackground.setPosition(location + sf::Vector2f(-55.f, 33.f));
}

void MonsterInfo::draw(sf::RenderWindow& window)
{
	window.draw(nameBackground);
	window.draw(name);
	
	window.draw(levelBackground);
	window.draw(level);

	window.draw(HPbackground1);
	window.draw(HPbackground2);
	window.draw(HPbar);
}

void MonsterInfo::setName(const std::string& newName)
{
	name.setString(newName);
	nameBackground.setScale(name.getString().getSize() / 5.f, 2.f);
}

void MonsterInfo::setLevel(const int& newLevel)
{
	level.setString("Lv, " + std::to_string(newLevel));
	levelBackground.setScale(level.getString().getSize() / 7.f, 2.f);
}

void MonsterInfo::init(sf::Text& text, const int& size)
{
	text.setFont(infoFont);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(size);
}

void MonsterInfo::init(sf::RectangleShape& bar, const sf::Color& color, 
	            const sf::Vector2f& size)
{
	bar.setFillColor(color);
	bar.setSize(size);
}