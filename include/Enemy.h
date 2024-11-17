#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"


class Enemy: public sf::Drawable, public Colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
public:
    Enemy();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn();
    sf::FloatRect getBounds() const override;
};
