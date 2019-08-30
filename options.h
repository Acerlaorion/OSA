#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

bool options(RenderWindow & window, int* VolumeMusic, Music* music)
{
    Event event;
    Texture optionsBackground, laudio, raudio;
    optionsBackground.loadFromFile("images/background1.jpg");
    laudio.loadFromFile("images/laudio.png");
    raudio.loadFromFile("images/raudio.png");
    Sprite optionsBg(optionsBackground), rlaudio(laudio), rraudio(raudio);
    Font font;
    font.loadFromFile("9393.ttf");
    Text volume("", font, 160);
    Text back_("BACK", font, 128);
    Text left("", font, 70);
    Text right("", font, 70);
    Text v0("", font, 170);
    volume.setStyle(sf::Text::Bold);
    v0.setStyle(sf::Text::Bold);
    back_.setStyle(sf::Text::Bold);
    volume.setColor(Color::Yellow);
    back_.setColor(Color::Yellow);
    volume.setString("Volume: ");
    left.setString("<-");
    right.setString("->");
    v0.setString("0");
    optionsBg.setPosition(0, 0);
    volume.setPosition(350 , 180 ); //800 830 // 350 250
    rlaudio.setPosition(-600 , -650 ); //-200 -70 //
    rraudio.setPosition(-450, -650); // -50 -70 //
    v0.setPosition(970, 180); //1370 815 // 970 235
    back_.setPosition(832, 800);
    bool back_to_menu = false;
    while (!Keyboard::isKeyPressed(Keyboard::Escape)&&(!back_to_menu))
    {
        while (window.pollEvent(event))
               {
                   v0.setColor(Color::White);
                   back_.setRotation(0); // вращение кнопки Back
                   if (IntRect(970, 200, 150, 150).contains(Mouse::getPosition(window))) { v0.setColor(Color::Yellow); }
                   if (IntRect(830, 820, 215, 90).contains(Mouse::getPosition(window))) { back_.setRotation(2); }
                   window.clear(Color(129, 181, 221));
                   window.pushGLStates(); // OpenGL
                   std::ostringstream ss; // записываем значение громкости
                   ss << *VolumeMusic;// ложим значение громкости из буфера
                   v0.setString(ss.str()); //ss.str() конвертирует строку из буфера в строку
                   Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window));
                   if (event.type == Event::Closed)
                   window.close();
                   if(event.type== Event::MouseButtonPressed)
                   if (event.mouseButton.button == Mouse::Left)
                   {
                        if(((mouse_world.x>=830)&&(mouse_world.x<=900))&&((mouse_world.y>=245)&&(mouse_world.y<=365)))
                        {
                            if(*VolumeMusic > 0) // проверка значения громкости
                            {
                                *VolumeMusic -= 10; // уменьшаем громоксть
                                music->setVolume(*VolumeMusic); // задаём функцию громкости со значением
                            }
                        }
                        if (((mouse_world.x>=1195)&&(mouse_world.x<=1255)&&(mouse_world.y>=245)&&(mouse_world.y<=365)))
                        {
                            if(*VolumeMusic < 100)
                            {
                                *VolumeMusic += 10;
                                music->setVolume(*VolumeMusic);
                            }
                        }
                        if (((mouse_world.x>=830)&&(mouse_world.x<=1045)&&(mouse_world.y>=820)&&(mouse_world.y<=910)))
                        {
                            back_to_menu = true; // активируется кнопка Back
                        }
                   }
                   if(event.type == Event::MouseWheelMoved) // задействуем колесико мышки
                    if(event.mouseWheel.delta == 1) // если колёсико крутим вверх
                    {
                        if (((mouse_world.x>=950)&&(mouse_world.x<=1150))&&((mouse_world.y>=245)&&(mouse_world.y<=365)))
                        {
                            if(*VolumeMusic < 100)
                            {
                                *VolumeMusic += 10;
                                music->setVolume(*VolumeMusic);
                            }
                        }
                    }
                    if(event.mouseWheel.delta == -1) // колесико мышки вниз
                    {
                        if (((mouse_world.x>=950)&&(mouse_world.x<=1150))&&((mouse_world.y>=245)&&(mouse_world.y<=365)))
                        {
                            if(*VolumeMusic > 0)
                            {
                                *VolumeMusic -= 10;
                                music->setVolume(*VolumeMusic);
                            }
                        }
                    }
                   window.draw(optionsBg); // отрисовка
                   window.draw(volume);
                   window.draw(rlaudio);
                   window.draw(rraudio);
                   window.draw(v0);
                   window.draw(back_);
                   window.popGLStates();
                   window.display();
               }
    }
    return true; // возвращаем в меню истину, чтобы меню стало активно
}

#endif // OPTIONS_H_INCLUDED
