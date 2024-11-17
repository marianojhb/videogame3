#include "../include/Enemy.h"
#include <cstdlib>
#include <iostream>
using namespace std;


Enemy::Enemy()
{
    _texture.loadFromFile("assets/sprites/eggman.gif");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
//    _sprite.setPosition(std::rand()%800,std::rand()%600);
    sf::Vector2f _velocity{2,2};
}

void Enemy::update()
{
//
    _sprite.move(_velocity.x,_velocity.y);
    if(_sprite.getGlobalBounds().left < 0)
    {
        _velocity.x = std::rand()%4;

    }
    if(_sprite.getGlobalBounds().top < 0)
    {
        _velocity.y = std::rand()%4;
    }
    if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800)
    {
        _velocity.x = -std::rand()%4;
    }
    if(_sprite.getGlobalBounds().top  + _sprite.getGlobalBounds().height > 600)
    {
        _velocity.y = -std::rand()%4;
    }

    // lo damos vuelta
    if(_velocity.x < 0) {
        _sprite.setScale(-0.9,0.9);
    } else if (_velocity.x > 0) {
        _sprite.setScale(0.9,0.9);
    }

//        cout << "_velocity.x " << _velocity.x << "      _velocity.y " << _velocity.y << endl;
        if(_sprite.getGlobalBounds().left < 0)
            cout << true << endl;
}


void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Enemy::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Enemy::respawn()
{
    _sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
}
