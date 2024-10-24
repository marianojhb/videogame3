#include "../include/Personaje.h"
#include <string>

Personaje::Personaje()
{
   _velocity = {4,4};
   _texture.loadFromFile("assets/sprites/sonic.png"); // Creo el primer personaje
   _sprite.setTexture(_texture);
   _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
}

void Personaje::update()
{
    _velocity = {0,0 };

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y= -4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity.y = 4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 4;

    }

    _sprite.move(_velocity);

    if(_velocity.x < 0) {
        _sprite.setScale(-1,1);
    } else if (_velocity.x > 0) {
        _sprite.setScale(1,1);
    }


    // vemos en que posicion se quedo luego de cada movimiento
    // para que no se vaya de la pantalla
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }

    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - _sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600);
    }



}

void Personaje::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
