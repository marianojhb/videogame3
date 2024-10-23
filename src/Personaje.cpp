#include "../include/Personaje.h"
#include <string>

Personaje::Personaje()
{
   _texture.loadFromFile("assets/sprites/sonic.png"); // Creo el primer personaje
   _sprite.setTexture(_texture);
   _velocity = {4,4};
}

void Personaje::update()
{
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        _sprite.move(0,-_velocity);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        _sprite.move(-_velocity,0);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//        _sprite.move(0,_velocity);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        _sprite.move(_velocity,0);
//    }

    _sprite.move(_velocity);

    // vemos en que posicion se quedo luego de cada movimiento
    // para que no se vaya de la pantalla
    if(_sprite.getPosition().x < 0) {
//        _sprite.setPosition(0,_sprite.getPosition().y);
            _velocity.x = -_velocity.x * 1.01;
    }
    if(_sprite.getPosition().x > 800 - _sprite.getGlobalBounds().width) {
//        _sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
            _velocity.x = -_velocity.x * 1.01;
    }
    if(_sprite.getPosition().y > 600-_sprite.getGlobalBounds().height) {
//        _sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
        _velocity.y = -_velocity.y * 1.01;
    }
    if(_sprite.getPosition().y < 0) {
//        _sprite.setPosition(_sprite.getPosition().x, 0);
        _velocity.y = -_velocity.y * 1.01;
    }

}

void Personaje::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
