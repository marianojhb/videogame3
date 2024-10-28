#include <cstdlib>
#include "../include/Item.h"


Item::Item()
{
    _velocity = {0,0};
    _texture.loadFromFile("assets/sprites/anillo.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0,0,65,65});
    _sprite.setScale(0.5,0.5);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
    _sprite.setPosition(0+_sprite.getOrigin().x,300);
}

void Item::update()
{
    _sprite.move(_velocity);

    for(int y = 0; y < 260; y+=65)
    {
        for (int x = 0; x < 260; x+=65)
        {
            _sprite.setTextureRect({x ,y,65,65});
        }
    }

}

void Item::respawn()
{
    _sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Item::getBounds() const
{
    return _sprite.getGlobalBounds();
}
