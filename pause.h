//пауза на карте
#include <SFML/Graphics.hpp>
#include <sftools/Chronometer.hpp>
#include <iostream>
#include "hp.h"
int appalive =10000000;
int *appaliv = &appalive;//переменная для выхода из карты в паузе
void pausing(RenderWindow& app, sftools::Chronometer &clock4,Music* music)
{

    Event event;
    Texture t1;
    t1.loadFromFile("images/BG.jpg");//загрузка картинки из файла
    Sprite background(t1);
    while(true)
    {
        app.clear();
        app.draw(background);
            Vector2f mouse_world =  app.mapPixelToCoords(Mouse::getPosition(app));
           if ((sf::Keyboard::isKeyPressed(Keyboard::Space))||(sf::Mouse::isButtonPressed(sf::Mouse::Left))||(sf::Mouse::isButtonPressed(sf::Mouse::Right))) break;
           if (sf::Keyboard::isKeyPressed(Keyboard::Escape)) {appalive=0; break;}
        app.display();

    }
    clock4.reset(true);
    app.setActive(false);


}
