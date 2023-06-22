#include "Info.h"
#include "Controller.h"
#include "Resources.h"

Info::Info()
	:panel(Resources::instance().texture(Resources::Panel))
{
	infoFont.loadFromFile("Buttons_Font.otf");
	panel.setPosition(sf::Vector2f(0, Controller::WindowHeight - 38.f));
	init(level, 20, { 48,  Controller::WindowHeight - 31.f });
	init(job,   12, { 85,  Controller::WindowHeight - 33.f });
	init(HP,    11, { 218, Controller::WindowHeight - 33.f });
	init(MP,    11, { 329, Controller::WindowHeight - 33.f });
	init(EXP,   11, { 447, Controller::WindowHeight - 33.f });
	init(HPbar,  sf::Color::Red,    { 198, Controller::WindowHeight - 18.f }, { 105.f, 14.f });
	init(MPbar,  sf::Color::Blue,   { 306, Controller::WindowHeight - 18.f }, { 105.f, 14.f });
	init(EXPbar, sf::Color::Yellow, { 419, Controller::WindowHeight - 18.f }, { 115.f, 14.f });
	init(background1, sf::Color(189.f, 189.f, 189.f), { 198, Controller::WindowHeight - 18.f }, { 105.f, 14.f });
	init(background2, sf::Color(189.f, 189.f, 189.f), { 306, Controller::WindowHeight - 18.f }, { 105.f, 14.f });
	init(background3, sf::Color(189.f, 189.f, 189.f), { 419, Controller::WindowHeight - 18.f }, { 115.f, 14.f });
}

void Info::init(sf::Text& text, const int& size, const sf::Vector2f& position)
{
	text.setFont(infoFont);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(size);
	text.setPosition(position);
}

void Info::init(sf::RectangleShape& bar, const sf::Color& color,
	            const sf::Vector2f& position, const sf::Vector2f& size)
{
	bar.setFillColor(color);
	bar.setPosition(position);
	bar.setSize(size);
}

void Info::draw(sf::RenderWindow& window)
{
	window.draw(background1);
	window.draw(background2);
	window.draw(background3);	
	window.draw(HPbar);
	window.draw(MPbar);
	window.draw(EXPbar);
	window.draw(panel);
	window.draw(level);
	window.draw(HP);
	window.draw(MP);
	window.draw(EXP);
	window.draw(job);

	for (const auto& damage : damageInfo)
		damage->draw(window);

	for (auto& monster : Map::instance().monsters())
		if (monster->getData().wasHit)
			monster->drawInfo(window);
}

void Info::update(const Data& data)
{
	level.setString(std::to_string(data.level));
	HP.setString('(' + std::to_string(data.HP) + "/" + std::to_string(data.MaxHP) + ')');
	MP.setString('(' + std::to_string(data.MP) + "/" + std::to_string(data.MaxMP) + ')');
	EXP.setString(std::to_string(data.EXP) + '(' + std::to_string((data.EXP / static_cast<float>(data.MaxEXP) * 100.f)).substr(0,5) + "%)");
	job.setString(data.job);
	HPbar.setSize(sf::Vector2f(105.f * (data.HP / static_cast<float>(data.MaxHP)), 14.f));
	MPbar.setSize(sf::Vector2f(105.f * (data.MP / static_cast<float>(data.MaxMP)), 14.f));
	EXPbar.setSize(sf::Vector2f(115.f * (data.EXP / static_cast<float>(data.MaxEXP)), 14.f));

	for (auto damage = damageInfo.begin(); damage != damageInfo.end(); )
	{
		(*damage)->update();

		if ((*damage)->deletion())
			damage = damageInfo.erase(damage)	;
		else
			++damage;
	}
}

void Info::showDamage(const std::string& type, const int& amount, const sf::Vector2f& location)
{
	// add damage to be shown on screen
	damageInfo.push_back(std::make_unique<Damage>(type, amount, location));
}

Info& Info::instance()
{
	static Info instance;
	return instance;
}
