#include "Kwadrat.h"

Kwadrat::Kwadrat(sf::Vector2f poz, sf::Vector2f roz)
{
    ksztalt.setPosition(poz);
    ksztalt.setSize(roz);
    predkosc.x=0;
    predkosc.y=0;
    skok.x=0;
    skok.y=0;
    grawitacja.x=0;
    grawitacja.y=10;
    podloze.setPosition(sf::Vector2f(0,800));
    podloze.setSize(sf::Vector2f(1920,280));
    podloze.setFillColor(sf::Color::Green);
}
void Kwadrat::draw(sf::RenderTarget& target, sf::RenderStates states) const
 {
     target.draw(ksztalt,states);
     target.draw(podloze,states);
 }
void Kwadrat::pozycja()
{
    kolizja();
    sciany();
    ruch();
    opory();
    ksztalt.move(grawitacja);
    ksztalt.move(predkosc);
    ksztalt.move(skok);
}
bool Kwadrat::kolizja()
{
    if (ksztalt.getPosition().y+ksztalt.getSize().y>=800) {grawitacja.y=0; skok.y=0; return true;}
    else {grawitacja.y=10;  return false;}

}
void Kwadrat::sciany()
{
    if (ksztalt.getPosition().x<0) {ksztalt.setPosition(sf::Vector2f(0,ksztalt.getPosition().y));}
    else if(ksztalt.getPosition().x+ksztalt.getSize().x>1920) {ksztalt.setPosition(sf::Vector2f(1920-ksztalt.getSize().x,ksztalt.getPosition().y));}
}
void Kwadrat::ruch()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&kolizja()==true) {predkosc.x+=1; if(predkosc.x==5) predkosc.x=5;}
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&kolizja()==true) {predkosc.x+=-1; if(predkosc.x==-5) predkosc.x=-5;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&kolizja()==true) {skok.y=-40; skok.x=predkosc.x;}
}
void Kwadrat::opory()
{
    predkosc.x=predkosc.x/1.05;
    skok.x=skok.x/1.05;
    skok.y/=1.05;
}


