#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <list>
#include <string>
#include <sstream>
#include "options.h"
#include "selectLevel.h"
using namespace sf;

void menu(RenderWindow & window)
{
    Font font;//�����
    font.loadFromFile("STALKERItalic.ttf");//�������� ������ ������ ���� ������
    Text namegame("", font, 70);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
    namegame.setColor(Color::White);//��������� ����� � �����.
    namegame.setStyle(sf::Text::Bold);//������ �����. �� ��������� �� "�����":)) � �� ������������
    Texture menuTexture1, menuTexture2, menuTexture3, menuBackground, menuLogo, menuIcon1, menuIcon2, menuIcon3,
    menuIcon1Big, menuIcon2Big, menuIcon3Big, volon, voloff; // ������ ���������� ��������
    Image iconwindow;
    iconwindow.loadFromFile("images/iconwindow.png");
    menuTexture1.loadFromFile("images/start_game4.png");
    menuTexture2.loadFromFile("images/options4.png");
    menuTexture3.loadFromFile("images/exit_game4.png");
    menuBackground.loadFromFile("images/background1.jpg");
    menuIcon1.loadFromFile("images/icon1.png");
    menuIcon2.loadFromFile("images/icon2.png");
    menuIcon3.loadFromFile("images/icon3.png");
    menuIcon1Big.loadFromFile("images/icon1big.png");
    menuIcon2Big.loadFromFile("images/icon2big.png");
    menuIcon3Big.loadFromFile("images/icon3big.png");
    menuLogo.loadFromFile("images/logo3.png");
    volon.loadFromFile("images/auon.png");
    voloff.loadFromFile("images/auoff.png"); // ��������� �������� �� �����
    Music music;//������� ������ ������
    music.openFromFile("1.ogg");//��������� ������
    music.play();//������������� ������
    int VolumeMusic = 10; // ���������� ��������� ������
    music.setVolume(10); // ������������� �������� �� 10 ���������
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground), menuLg(menuLogo),
    icon1(menuIcon1), icon2(menuIcon2), icon3(menuIcon3), icon1Big(menuIcon1Big), icon2Big(menuIcon2Big), icon3Big(menuIcon3Big),
    von(volon), voff(voloff); // ������ �� ������� �������
    bool isMenu = 1; // ���������� ���������� ����
    int menuNum = 0; // ���������� �� ���� �� ������ ���� �� �������, ��� ��������
    menu1.setPosition(-70, 1);
    icon1.setPosition(-100, 1);
    icon1Big.setPosition(-100.1, 1);
    menu2.setPosition(-70, 2);
    icon2.setPosition(-80, 2);
    icon2Big.setPosition(-80.1, 2);
    menu3.setPosition(-70, 3);
    icon3.setPosition(-100, 3);
    icon3Big.setPosition(-100.1, 3);
    menuBg.setPosition(0, 0);
    menuLg.setPosition(-70, 0);
    von.setPosition(300, -410);
    voff.setPosition(330, -410); // ������ ������� ��������
    namegame.setPosition(400 , 50 );//������ ������� ������, ����� ������
    namegame.setString("OSA");//������ ������ ������
    window.setIcon(32, 32, iconwindow.getPixelsPtr()); // ������ ����������
    bool icon1_Big, icon2_Big, icon3_Big; // ���������� ��� ���������� ������ ��� ��������� ������ �� ������� � ����
    Color colorArray[7] = {Color::White, Color::Red, Color::Green, Color::Blue, Color::Magenta, Color::Cyan, Color::Yellow}; // ������ ������
//////////////////////////////����///////////////////
    while (isMenu) // ���� ����
    {
        Event event;
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221)); // ������� ����
        icon1_Big = false; icon2_Big = false; icon3_Big = false; // ���������� �������������, ��� ������� ������ �� �������
        if (IntRect(900, 225, 575, 125).contains(Mouse::getPosition(window))) // ���� ����� �������� �� ����������� ������� ���������
            {
                icon1_Big = true; // �� ������� ������ ���������� ��������
                menu1.setColor(Color::Yellow); // ������� ������ �������� � ����� ����
                menuNum = 1; // ������� 1 ������� � ���� - "������"
            }
        if (IntRect(1000, 438, 508, 125).contains(Mouse::getPosition(window))) // ���������� � 1-�� ��������; 2 ������� - �����
            {
                icon2_Big = true;
                 menu2.setColor(Color::Yellow);
                 menuNum = 2;
            }
        if (IntRect(900, 658, 590, 120).contains(Mouse::getPosition(window))) // ���������� � 1-�� ��������; 3 ������� - �����
            {
                icon3_Big = true;
                menu3.setColor(Color::Yellow);
                menuNum = 3;
            }
        Vector2f mouse_world =  window.mapPixelToCoords(Mouse::getPosition(window)); // ������� ���������� � �����
            while (window.pollEvent(event))
            {
                if(event.type == Event::Closed) // ���� ������� ����
                    window.close(); // ���� ��������� :)
                    if(event.type== Event::MouseButtonPressed) // ������� ������� �� �����
                        if(event.mouseButton.button == Mouse::Left) // ���� ������ ���
                        {
                            if(((mouse_world.x>=900)&&(mouse_world.x<=1475))&&((mouse_world.y>=225)&&(mouse_world.y<=350))) // �������� �� 1 ������� ������ �� �������� �����������
                            {
                                isMenu = false; // ���� ���������� ���������
                                if (selectLevel(window,&music) == 1) // ������� ��������� ������� � ������� �������, � ��� ���� ��� �� ����������. ������� � �� ���� � ��������� �� ������
                                    isMenu = true; // ������� ������ ������ ���������. ���������� ������� ����
                            }
                            if(((mouse_world.x>=950)&&(mouse_world.x<=1475))&&((mouse_world.y>=435)&&(mouse_world.y<=560))) // ���������� ��� 2 �������
                            {
                                isMenu = false;
                               if(options(window, &VolumeMusic, &music) == 1) // ������� ������� � ����������� � ����� ���
                                    isMenu = true;
                            }

                            if(((mouse_world.x>=1000)&&(mouse_world.x<=1658))&&((mouse_world.y>=658)&&(mouse_world.y<=778))) // ������� ������
                            {
                                isMenu = false; // ���� ���������
                                window.close(); // ���� �����������
                            }
                            if(((mouse_world.x>=1287)&&(mouse_world.x<=1403))&&((mouse_world.y>=93)&&(mouse_world.y<=182)))
                            {
                                music.play(); // ����� / ������ ������
                            }
                            if(((mouse_world.x>=1461)&&(mouse_world.x<=1584))&&((mouse_world.y>=93)&&(mouse_world.y<=182)))
                            {
                                music.pause(); // ��������� ������
                            }
                            if(((mouse_world.x>=345)&&(mouse_world.x<=885))&&((mouse_world.y>=350)&&(mouse_world.y<=655)))
                            {
                                menuLg.setColor(colorArray[rand()%7]); // "��������", ���� ����� �� ������� � ����, �� �� ����� ������� � ��������� ���� :D
                            }
                        }
            }
    window.draw(menuBg); // ��������� ������� ����
    window.draw(menu1); // ���� ������� ��������� ���� ��������
    if (!icon1_Big) // ���� ������� ������ �� �������, �� ������������ ���������
        window.draw(icon1);
    if (icon1_Big) // ���� ������� ������ �������, �� ����������� �, ���������� ������������ � ������� �������� ����
        window.draw(icon1Big);
    window.draw(menu2);
    if (!icon2_Big)
        window.draw(icon2);
    if (icon2_Big)
        window.draw(icon2Big);
    window.draw(menu3);
    if (!icon3_Big)
        window.draw(icon3);
    if (icon3_Big)
        window.draw(icon3Big);
    window.draw(menuLg); // ��������� ��������
    window.draw(von); // ��������� ������ ������
    window.draw(voff); // ��������� ����������� ������
    window.draw(namegame); // ��������� �������� ����
    window.display(); // ���������� ������
    }
}
