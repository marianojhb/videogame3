#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "../include/Personaje.h"
#include "../include/Item.h"

int main()
{
    // Plantamos la semilla random
    std::srand((unsigned)std::time(0));

    // Inicialización de la ventana
    sf::RenderWindow window (sf::VideoMode(800,600), "Mi primer Videojuego xD");
    window.setFramerateLimit(60);

    Personaje sonic;
    Item ring;
    ring.respawn();


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

        sonic.update();

        if(sonic.isCollision(ring))
        {
            ring.respawn();
        }

        ring.update();




        // Update (actualiza los estados del juego o de los personajes)


        window.clear(); // Antes de dibujar se limpia la pantalla. Para evitar que se superpongan

        // Draw
        window.draw(sonic);
        window.draw(ring);

        // Display - Flip
        window.display();
    }

    // Liberación del Juego
    return 0;
}
