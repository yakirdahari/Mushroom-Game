#include "NPC.h"

NPC::NPC(const sf::Vector2f& position, const Resources::Objects& object)
	: animatedObject(position, object)
{
	m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height / 1.08f));
}

void NPC::update(const sf::Time delta)
{
	auto animation = m_animation.update(delta);

	if (!animation)
		m_animation.resetAnimation();
}
