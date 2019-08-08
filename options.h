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
    Text left("", font, 70);
    Text right("", font, 70);
    Text v0("", font, 170);
    volume.setStyle(sf::Text::Bold);
    v0.setStyle(sf::Text::Bold);
    volume.setColor(Color::Yellow);
    volume.setString("Volume: ");
    left.setString("<-");
    right.setString("->");
    v0.setString("0");
    optionsBg.setPosition(0, 0);
    volume.setPosition(350 , 180 ); //800 830 // 350 250
    rlaudio.setPosition(-600 , -650 ); //-200 -70 //
    rraudio.setPosition(-450, -650); // -50 -70 //
    v0.setPosition(970, 180); //1370 815 // 970 235
    while (!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        while (window.pollEvent(event))
               {
                   v0.setColor(Color::White);
                   if (IntRect(970, 200, 150, 150).contains(Mouse::getPosition(window))) { v0.setColor(Color::Yellow); }
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
                        if(((mouse_world.x>=830)&&(mouse_world.x<=900))&&((mouse_world.y>=245)&&(mouse_world.y<=365)))
                        {
                            if(*VolumeMusic > 0)
                            {
                                *VolumeMusic -= 10;
                                music->setVolume(*VolumeMusic);
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
                   }
                   if(event.type == Event::MouseWheelMoved)
                    if(event.mouseWheel.delta == 1)
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
                    if(event.mouseWheel.delta == -1)
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
