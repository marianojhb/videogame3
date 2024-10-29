#include <cstdlib>
#include "../include/Power.h"


Power::Power()
{
    _velocity = {0,0};
    _texture.loadFromFile("assets/sprites/emerald2.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0,0,128,128});
    _sprite.setScale(1,1);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
    _sprite.setPosition(0+_sprite.getOrigin().x,300);
}

void Power::update()
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

void Power::respawn()
{
    _sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
}

void Power::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Power::getBounds() const
{
    return _sprite.getGlobalBounds();
}
