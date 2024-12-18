#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Personaje: public sf::Drawable, public Colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
public:
    Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
    void addVelocity(float velocity);
    sf::Vector2f getVelocity();
};

