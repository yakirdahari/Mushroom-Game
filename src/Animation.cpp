#include "Animation.h"

#include "Resources.h"

const auto AnimationTime = sf::seconds(0.2f);

Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite)
{
    m_sprite.setTexture(Resources::instance().texture());
    update();
}

void Animation::direction(Direction dir)
{
    if (m_dir == dir)
    {
        return;
    }

    m_dir = dir;
}

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;

    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        update();
    } 
}

void Animation::resetAnimation()
{
    m_index = -1;
}


void Animation::update()
{
    m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}
