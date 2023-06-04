#pragma once

#include "gameObject.h"

gameObject::gameObject(const sf::Vector2f& position)
{
	m_sp.setPosition(position);
}

// Constructor
gameObject::gameObject(const sf::Vector2f& position, const sf::Vector2f& mapSize,
	                   const sf::Vector2f& resolution)
	: m_isDeleted(false), m_resolution(resolution)
{
	//m_sp.setOrigin(sf::Vector2f(150.f, 150.f));
	m_sp.setPosition(position);	
	//m_sp.scale(0.129f, 0.1285f);
}

void gameObject::setImage(const sf::Texture& texture)
{
	m_sp.setTexture(texture);
}

void gameObject::setPosition(sf::Vector2f position)
{
	m_sp.setPosition(position);
}

void gameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sp);
}

bool gameObject::collidesWith(const sf::FloatRect& other) const
{
	return m_sp.getGlobalBounds().intersects(other);
}

sf::FloatRect gameObject::getGlobalBounds() const
{
	return m_sp.getGlobalBounds();
}

bool gameObject::isDeleted() const
{
	return m_isDeleted;
}

void gameObject::remove()
{
	m_isDeleted = true;
}
