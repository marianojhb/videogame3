#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <cstdlib>
#include <ctime>
#include "../include/Personaje.h"
#include "../include/Item.h"
#include "../include/Power.h"

int main()
{
    // Plantamos la semilla random
    std::srand((unsigned)std::time(0));

    // Inicialización de la ventana
    sf::RenderWindow window (sf::VideoMode(800,600), "Mi primer Videojuego xD");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("assets/fonts/MONOCOQUE.ttf");

    sf::Text text;
    text.setFont(font);

    sf::Text puntos;
    puntos.setFont(font);

    sf::Text velocidad;
    velocidad.setFont(font);

    sf::Text timer_txt;
    timer_txt.setFont(font);

    Personaje sonic;
    Item ring;
    ring.respawn();

    Power power;
    power.respawn();

    int timer = 60*5;

    int sumarPuntos = 0;


    sf::Sprite fondo;
    sf::Texture fondo_texture;
    fondo_texture.loadFromFile("assets/sprites/fondo.jpg");
    fondo.setTexture(fondo_texture);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/sounds/title-theme-101soundboards.mp3");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    sf::SoundBuffer ring_collect;
    ring_collect.loadFromFile("assets/sounds/ring-collect-101soundboards.mp3");
    sf::Sound ring_collect_sound;
    ring_collect_sound.setBuffer(ring_collect);

    sf::SoundBuffer emerald_collect;
    emerald_collect.loadFromFile("assets/sounds/emerald-101soundboards.mp3");
    sf::Sound emerald_collect_sound;
    emerald_collect_sound.setBuffer(emerald_collect);



    // Game Loop (update del juego)
    while (window.isOpen())
    {

        // Read input: actualiza los buffers donde tiene la info del mouse etc.
        // Actualiza los estados de entrada (o sea de los periféricos)
        // Llamar al pool event: la cola de los mensajes.
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // CMD (Leer los comandos que se presionaron)

        if (timer > 0)
        {
            timer--;
        }

        if(sonic.isCollision(ring))
        {
            ring.respawn();
            ring_collect_sound.play();
            sumarPuntos++;
        }

        if(timer == 0 && sonic.isCollision(power))
        {
            emerald_collect_sound.play();
            sonic.addVelocity(2);
            timer = 60*5;
            power.respawn();
        }

        puntos.setPosition(360, 20);
        puntos.setCharacterSize(26);
        puntos.setString("SCORE " + std::to_string(sumarPuntos));

        velocidad.setString(std::to_string(sonic.getVelocity().x));

        timer_txt.setString(std::to_string(timer));
        timer_txt.setPosition(timer_txt.getPosition().x, 50);

        // Update (actualiza los estados del juego o de los personajes)

        sonic.update();
        ring.update();
//        power.update();

        window.clear(); // Antes de dibujar se limpia la pantalla. Para evitar que se superpongan

        // Draw
        window.draw(fondo);
        window.draw(sonic);
        window.draw(ring);
        window.draw(text);
        window.draw(puntos);
        window.draw(velocidad);
        window.draw(timer_txt);

        if (timer ==0)
        {
            window.draw(power);
        }

        // Display - Flip
        window.display();
    }

    // Liberación del Juego
    return 0;
}
