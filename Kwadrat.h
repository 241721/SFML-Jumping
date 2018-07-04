#ifndef KWADRAT_H
#define KWADRAT_H
#include <SFML/Graphics.hpp>

class Kwadrat: public sf::Drawable
{
private:
    sf::Vector2f grawitacja;
    sf::Vector2f predkosc;
    sf::Vector2f skok;
    sf::RectangleShape ksztalt;
    sf::RectangleShape podloze;
    public:
        Kwadrat(sf::Vector2f poz, sf::Vector2f roz);
        void pozycja();
        void bieg();
        bool kolizja();
        void sciany();
        void ruch();
        void opory();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // KWADRAT_H
