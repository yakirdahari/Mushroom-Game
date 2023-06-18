#include "Portal.h"

constexpr auto AnimationSpeed = 0.0f;

Portal::Portal(const sf::Vector2f& position, const int& destination)
	: animatedObject(position, Resources::Portal),
	  m_destination(destination), m_exitPortal(0)
{
	m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height / 1.08f));
}

Portal::Portal(const sf::Vector2f& position, const int& destination, const int& exitPortal)
	: animatedObject(position, Resources::Portal),
	  m_destination(destination), m_exitPortal(exitPortal)
{
	m_sp.setOrigin(sf::Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height / 1.08f));
}

void Portal::update(const sf::Time delta)
{
	m_animationTime.restart();
	m_animation.update(delta);
}

int Portal::destination()
{
	return m_destination;
}

int Portal::exitPortal()
{
	return m_exitPortal;
}

void Portal::handleCollision(gameObject& gameObject)
{
	// ignore self collision
	if (&gameObject == this) return;

	// use double dispatch to find which object
	gameObject.handleCollision(*this);
}

void Portal::handleCollision(Player& player)
{
	player.handleCollision(*this);
}