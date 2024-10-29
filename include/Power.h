#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Power : public sf::Drawable, public Colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity = {0,0};

public:
    Power();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn();
    sf::FloatRect getBounds() const override;
};
