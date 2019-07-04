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
    font.loadFromFile("font.ttf");
    Text volume("", font, 75);
    Text left("", font, 70);
    Text right("", font, 70);
    Text v0("", font, 100);
    volume.setStyle(sf::Text::Bold);
    v0.setStyle(sf::Text::Bold);
    volume.setColor(Color::Yellow);
    v0.setColor(Color::White);
    volume.setString("Volume: ");
    left.setString("<-");
    right.setString("->");
    v0.setString("0");
    optionsBg.setPosition(0, 0);
    volume.setPosition(800 , 830 );
    rlaudio.setPosition(-200 , -70 );
    rraudio.setPosition(-50, -70);
    v0.setPosition(1370, 815);
    if (IntRect(800, 100, 450, 100).contains(Mouse::getPosition(window))) { left.setColor(Color::White); }
    while (!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        while (window.pollEvent(event))
               {
                   window.clear(Color(129, 181, 221));
                   window.pushGLStates();
                   std::ostringstream ss;
                   ss << *VolumeMusic;// put float into string buffer
                   //set up text properties
                   v0.setString(ss.str()); //ss.str() converts the string buffer into a regular string
                   Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window));
                   if (event.type == Event::Closed)
                   window.close();
                   if(event.type== Event::MouseButtonPressed)
                   if (event.mouseButton.button == Mouse::Left)
                   {
                        std::cout << mouse_world.x << std::endl;
                        std::cout << mouse_world.y << std::endl;
                        if(((mouse_world.x>=1200)&&(mouse_world.x<=1300))&&((mouse_world.y>=825)&&(mouse_world.y<=940)))
                        {
                            if(*VolumeMusic > 0)
                            {
                                *VolumeMusic = *VolumeMusic - 10;
                                music->setVolume(*VolumeMusic);
                            }
                        }
                        if (((mouse_world.x>=1600)&&(mouse_world.x<=1700)&&(mouse_world.y>=825)&&(mouse_world.y<=940)))
                        {
                            if(*VolumeMusic < 100)
                            {
                                *VolumeMusic = *VolumeMusic + 10;
                                music->setVolume(*VolumeMusic);
                            }
                        }
                   }
                   if(event.type == Event::MouseWheelMoved)
                    if(event.mouseWheel.delta == 1)
                    {
                        if (((mouse_world.x>=1300)&&(mouse_world.x<=1600))&&((mouse_world.y>=845)&&(mouse_world.y<=910)))
                        {
                            if(*VolumeMusic < 100)
                            {
                                *VolumeMusic = *VolumeMusic + 10;
                                music->setVolume(*VolumeMusic);
                            }
                        }
                    }
                    if(event.mouseWheel.delta == -1)
                    {
                        if (((mouse_world.x>=1300)&&(mouse_world.x<=1600))&&((mouse_world.y>=845)&&(mouse_world.y<=910)))
                        {
                            if(*VolumeMusic > 0)
                            {
                                *VolumeMusic = *VolumeMusic - 10;
                                music->setVolume(*VolumeMusic);
                            }
                        }
                    }
                   window.draw(optionsBg);
                   window.draw(volume);
                   window.draw(rlaudio);
                   window.draw(rraudio);
                   window.draw(v0);
                   window.popGLStates();
                   window.display();
               }
    }
    return true;
}

#endif // OPTIONS_H_INCLUDED
