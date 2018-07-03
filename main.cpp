#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Kwadrat.h"


using namespace sf;
using namespace std;

int main()
{
    //OKNA APLIKACJI:
    RenderWindow oknoGry( VideoMode( 1920, 1080, 32 ), "Skakanie", Style::Fullscreen );
    oknoGry.setFramerateLimit(60);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Kwadrat k(sf::Vector2f(100,100),sf::Vector2f(100,100));
    while(oknoGry.isOpen())
    {

        Event zdarzenie;
        while( oknoGry.pollEvent( zdarzenie ) )
        {
            if( Keyboard::isKeyPressed(Keyboard::Enter) )
            {

            }
            if( Keyboard::isKeyPressed(Keyboard::Q) )
            {

            }
            if( Keyboard::isKeyPressed(Keyboard::Escape) )
            {
                oknoGry.close();
            }
        }
        k.pozycja();
        oknoGry.clear();
        oknoGry.draw(k);
        oknoGry.display();
    }
    return 0;
}
