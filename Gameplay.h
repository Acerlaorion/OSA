#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Audio.hpp>
#include "hp.h"
#include <iostream>
using namespace sf;

const int W = 1900;
const int H = 1070;
int hp =100000;
int *HP = &hp;
float DEGTORAD = 0.017453f;

class Animation
{
public:
	float Frame;
	Sprite sprite;
    std::vector<IntRect> frames;
	Animation(){}
    Animation (Texture &t, int x, int y, int w, int h, int count)
	{
	    Frame = 0;
		for (int i=0;i<count;i++)
         frames.push_back( IntRect(x+i*w, y, w, h)  );
		sprite.setTexture(t);
		sprite.setOrigin(w/2,h/2);
        sprite.setTextureRect(frames[0]);
	}
	void update()
	{

		int n = frames.size();
		if (Frame >= n) Frame -= n;
		if (n>0) sprite.setTextureRect( frames[int(Frame)] );
	}

	bool isEnd()
	{
	  return Frame>=frames.size();
	}

};

class Entity
{
    public:
    float x,y,R;
    bool life;
    std::string name;
    Animation anim;

    Entity()
    {
      life=1;
    }

    void settings(Animation &a,int X,int Y,int radius=1)
    {
      anim = a;
      x=X; y=Y;
      R = radius;
    }

    virtual void update(){};

    void draw(RenderWindow &app)
    {
      anim.sprite.setPosition(x,y);
      app.draw(anim.sprite);
      CircleShape circle(R);
      circle.setFillColor(Color(255,0,0,170));
      circle.setPosition(x,y);
      circle.setOrigin(R,R);
      //app.draw(circle);
    }

    virtual ~Entity(){};
};


class asteroid: public Entity
{
public:
  asteroid()
  {
    //dx=rand()%8-4;
   // dy=rand()%8-4;
    name="asteroid";
  }
void  update()
  {
      if (x>W) x=10;  if (x<0) x=100;
   if (y>H) y=10;  if (y<0) y=100;
  }

};
void Spawner(RenderWindow &app,asteroid *a,Animation sRock)
{
    a->settings(sRock, rand()%W, rand()%H, 25);
    app.pushGLStates();
    a->draw(app);
    app.popGLStates();
}
void Gameplay()
{

    Clock clock;
    int sc =0;
    int *score = &sc;
   // Music music;//создаем объект музыки
  //  music.openFromFile("1.flac");//загружаем файл
  //  music.play();//воспроизводим музыку
    Time timer=milliseconds(205000);
    float t = timer.asMilliseconds();
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "OSA");
    app.setFramerateLimit(10);
    Texture t2,t4,t5,t6,t7;
    t2.loadFromFile("images/background.jpg");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_blue.png");
    t6.loadFromFile("images/rock_small.png");
    t2.setSmooth(true);
    Sprite background(t2);

    Animation sRock(t4, 0,0,64,64, 16 );
    Animation sRock_small(t6, 0,0,64,64, 16 );
    Animation sExplosion_ship(t7, 0,0,192,192, 64);

  //  std::vector<Entity*> entities;


      asteroid *a = new asteroid();
      a->settings(sRock, rand()%W, rand()%H, 25);

      //entities.push_back(a);


    int st=0;
    /////main loop/////

    while (app.isOpen())
    {
        while((t>0))
        {
             float cloker = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
             clock.restart(); //перезагружает время
            Event event;
            float x=0;
            x+=cloker;
            std::ostringstream playerScoreString;
            Vector2f mouse_world =  app.mapPixelToCoords(Mouse::getPosition( app ) );
            Font font;//шрифт
            font.loadFromFile("ALGER.TTF");//передаем нашему шрифту файл шрифта
            Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
            text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
            text.setStyle(Text::Bold);//жирный текст.
            //////draw//////
            if(x>10)
            {

                x=0;
            }

            if(st==500)
            {
                app.pushGLStates();
                Spawner(app,a,sRock);
                app.popGLStates();
                hpdrainmiss(HP);
                app.display();
                a->~Entity();
            }
            if(st==5000)
            {
                const Color &  	color = Color(0, 0, 0, 255);
                app.clear(color);
                st=0;
                app.pushGLStates();
                app.draw(background);
                app.popGLStates();

                text.setString("SCORE:");//задаем строку тексту и вызываем сформированную выше строку методом .str()
            text.setPosition(1750,0);//задаем позицию текста, отступая от центра камеры
            app.pushGLStates();
            app.draw(text);//рисую этот текст
            app.popGLStates();
            Text text2("", font, 20);
            playerScoreString <<*score ;
            text2.setString(playerScoreString.str());
            text2.setPosition(1825,0);//задаем позицию текста, отступая от центра камеры
            app.pushGLStates();
            app.draw(text2);//рисую этот текст
            app.popGLStates();
            Text text3("", font, 20);
            std::ostringstream HPstring;
            HPstring <<*HP ;
            text3.setString(HPstring.str());
            text3.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
            text3.setPosition(0,0);//задаем позицию текста, отступая от центра камеры
            app.pushGLStates();
            app.draw(text3);//рисую этот текст
            app.popGLStates();
            t--;
            st++;
            hpdraintime(HP);

                app.display();
            }
            while (app.pollEvent(event))
                {
                    if (event.type == Event::Closed)
                        app.close();
                       // if((event.type== Event::MouseButtonPressed)
                            if ((event.mouseButton.button == Mouse::Left)||(Keyboard::isKeyPressed(Keyboard::Z))||(Keyboard::isKeyPressed(Keyboard::X))||(Keyboard::isKeyPressed(Keyboard::Left))||(Keyboard::isKeyPressed(Keyboard::Down)))
                            {
                                if(((mouse_world.x>=(a->x)-40)&&(mouse_world.x<=(a->x)+40))&&((mouse_world.y>=(a->y)-40)&&(mouse_world.y<=(a->y)+40)))
                                {
                                    sc+=10000;
                                    hplife(HP);
                                }
                            }
                }
           /* text.setString("SCORE:");//задаем строку тексту и вызываем сформированную выше строку методом .str()
            text.setPosition(1750,0);//задаем позицию текста, отступая от центра камеры
            app.draw(text);//рисую этот текст
            Text text2("", font, 20);
            playerScoreString <<*score ;
            text2.setString(playerScoreString.str());
            text2.setPosition(1825,0);//задаем позицию текста, отступая от центра камеры
            app.draw(text2);//рисую этот текст
            Text text3("", font, 20);
            std::ostringstream HPstring;
            HPstring <<*HP ;
            text3.setString(HPstring.str());
            text3.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
            text3.setPosition(0,0);//задаем позицию текста, отступая от центра камеры
            app.draw(text3);//рисую этот текст
            t--;
            st++;
            hpdraintime(HP);*/
t--;
            st++;


        }

    }
}

