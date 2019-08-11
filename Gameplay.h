#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <sstream>
#include "hp.h"
#include "life.h"
#include <iostream>
using namespace sf;
Clock clock1;

int hp =10000000;
int *HP = &hp;

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
float x,y,t=2000000;;
bool life;
std::string name;
Animation anim;
CircleShape circle1;

Entity()
{
  life=1;
  t=2000000;
}

void settings(Animation &a,int X,int Y)
{
  anim = a;
  x=X; y=Y;
}


void update(RenderWindow &app,float r,float X1,float Y1)
  {
    circle1.setFillColor(sf::Color::Transparent);
    circle1.setOutlineThickness(2);
    circle1.setOutlineColor(sf::Color(255, 255, 255));
    circle1.setPointCount(100);
    int MinRadius = 23;

        circle1.setRadius(r);
        circle1.setPosition(X1, Y1);

    if(r>MinRadius)
    app.draw(circle1);

  }

void draw(RenderWindow &app)
{

  anim.sprite.setPosition(x,y);
  app.draw(anim.sprite);

  /*CircleShape circle(24);

  circle.setFillColor(Color(255,0,0,255));
  circle.setPosition(x,y);
  circle.setOrigin(24,24);

  circle1.setPosition(x,y);
  circle1.setOrigin(24,24);
  circle1.setFillColor(Color(0,0,0,0));
  circle1.setOutlineColor(Color(0,0,255,255));
  circle1.setOutlineThickness(5);
  app.draw(circle);
  app.draw(circle1);*/
}
~Entity(){std::cout << "F" << this->x <<std::endl;};
};

bool Gameplay(RenderWindow & app, Music* music)
{
    clock1.restart();
    *HP = 100000;
    int sc =0;
    int *score = &sc;
    int cb=1;
    int *combo=&cb;
    app.setFramerateLimit(60);
    music->openFromFile("audio.ogg");

    Texture t1,t2,t4,t3,t5;
    t2.loadFromFile("images/BG.jpg");
    t1.loadFromFile("images/hit300.png");
    t3.loadFromFile("images/hit100.png");
    t5.loadFromFile("images/hit50.png");
    t4.loadFromFile("images/rock.png");
    //t3.loadFromFile("images/cursor.png");
    app.setMouseCursorVisible(true);
    Sprite background(t2);
    Sprite hit300(t1);
    Sprite hit100(t3);
    Sprite hit50(t5);
    Animation sRock(t4,0,0,64,64,16);
    int x0=388;
    int y0=150;

    float Coef= 1.5;
     Entity *o2 =new Entity();
        o2->settings(sRock,(236+x0)*Coef,(92+y0)*Coef);
    Entity *o3 =new Entity();
        o3->settings(sRock,(40+x0)*Coef,(172+y0)*Coef);
    Entity *o4 = new Entity();
        o4->settings(sRock, (56+x0)*Coef,( 260+y0)*Coef);
    Entity *o5 = new Entity();
        o5->settings(sRock, (466+x0)*Coef,( 217+y0)*Coef);
    Entity *o6 = new Entity();
        o6->settings(sRock, (236+x0)*Coef,( 244+y0)*Coef);
    Entity *o7 = new Entity();
        o7->settings(sRock, (316+x0)*Coef,( 284+y0)*Coef);
    Entity *o8 = new Entity();
        o8->settings(sRock, (466+x0)*Coef,( 217+y0)*Coef);
    Entity *o9 = new Entity();
        o9->settings(sRock, (401+x0)*Coef,( 65+y0)*Coef);
    Entity *o10 = new Entity();
        o10->settings(sRock, (247+x0)*Coef,( 128+y0)*Coef);
    Entity *o11 = new Entity();
        o11->settings(sRock, (332+x0)*Coef,( 244+y0)*Coef);
    Entity *o12 = new Entity();
        o12->settings(sRock, (264+x0)*Coef,( 304+y0)*Coef);
    Entity *o13 = new Entity();
        o13->settings(sRock, (340+x0)*Coef,( 352+y0)*Coef);
    Entity *o14 = new Entity();
        o14->settings(sRock, (460+x0)*Coef,( 264+y0)*Coef);
    Entity *o15 =new Entity();
        o15->settings(sRock, (404+x0)*Coef,(104+y0)*Coef);
    Entity *o16 =new Entity();
        o16->settings(sRock, (68+x0)*Coef,(124+y0)*Coef);
    Entity *o17 = new Entity();
        o17->settings(sRock, (132+x0)*Coef,( 276+y0)*Coef);
    Entity *o18 = new Entity();
        o18->settings(sRock, (300+x0)*Coef,( 236+y0)*Coef);
    Entity *o19 = new Entity();
        o19->settings(sRock, (244+x0)*Coef,( 188+y0)*Coef);
    Entity *o20 = new Entity();
        o20->settings(sRock, (144+x0)*Coef,( 144+y0)*Coef);
    Entity *o21 = new Entity();
        o21->settings(sRock, (220+x0)*Coef,( 92+y0)*Coef);
    Entity *o22 = new Entity();
        o22->settings(sRock, (376+x0)*Coef,( 24+y0)*Coef);
    Entity *o23 = new Entity();
        o23->settings(sRock, (309+x0)*Coef,( 88+y0)*Coef);
    Entity *o24 = new Entity();
        o24->settings(sRock, (308+x0)*Coef,( 176+y0)*Coef);
    Entity *o25 = new Entity();
        o25->settings(sRock, (140+x0)*Coef,( 220+y0)*Coef);
    Entity *o26 = new Entity();
        o26->settings(sRock, (216+x0)*Coef,( 84+y0)*Coef);
    Entity *o27 = new Entity();
        o27->settings(sRock, (218+x0)*Coef,( 176+y0)*Coef);
    Entity *o28 =new Entity();
        o28->settings(sRock,(276+x0)*Coef,(244+y0)*Coef);
    Entity *o29 = new Entity();
        o29->settings(sRock, (436+x0)*Coef,( 184+y0)*Coef);
    Entity *o30 = new Entity();
        o30->settings(sRock, (380+x0)*Coef,( 60+y0)*Coef);
    Entity *o31 = new Entity();
        o31->settings(sRock, (164+x0)*Coef,( 104+y0)*Coef);
    Entity *o32 = new Entity();
        o32->settings(sRock, (236+x0)*Coef,( 220+y0)*Coef);
    Entity *o33 = new Entity();
        o33->settings(sRock, (448+x0)*Coef,( 264+y0)*Coef);
    Entity *o34 = new Entity();
        o34->settings(sRock, (344+x0)*Coef,( 348+y0)*Coef);
    Entity *o35 = new Entity();
        o35->settings(sRock, (136+x0)*Coef,( 300+y0)*Coef);
    Entity *o36 = new Entity();
        o36->settings(sRock, (92+x0)*Coef,( 128+y0)*Coef);
    Entity *o37 = new Entity();
        o37->settings(sRock, (256+x0)*Coef,( (192+y0)*Coef));
    Clock clock2;

    std::ostringstream playerScoreString;
        Font font;
        font.loadFromFile("ALGER.TTF");
        Text text("", font, 20);
        text.setColor(Color::Red);
        text.setStyle(Text::Bold);
        text.setString("SCORE:");
        text.setPosition(1750,0);
        Text text2("", font, 20);
            playerScoreString <<*score ;
        text2.setString(playerScoreString.str());
        text2.setPosition(1825,0);
        std::ostringstream combostr;
        Font font1;
            font.loadFromFile("font.ttf");
            Text text3("", font, 40);
            combostr <<*combo ;
            Color clr(100,200,255,100);
            text3.setColor(clr);
            text3.setStyle(Text::Bold);
            text3.setString(combostr.str());
            text3.setPosition(20,1030);
    int i =0;
    float X2=o2->x-43;
    float Y2=o2->y-50;
    float X3=o3->x-43;
    float Y3=o3->y-50;
    float X4=o4->x-43;
    float Y4=o4->y-50;
    float X5=o5->x-43;
    float Y5=o5->y-50;
    float X6=o6->x-43;
    float Y6=o6->y-50;
    float X7=o7->x-43;
    float Y7=o7->y-50;
    float X8=o8->x-43;
    float Y8=o8->y-50;
    float X9=o9->x-43;
    float Y9=o9->y-50;
    float X10=o10->x-43;
    float Y10=o10->y-50;
    float X11=o11->x-43;
    float Y11=o11->y-50;
    float X12=o12->x-43;
    float Y12=o12->y-50;
    float X13=o13->x-43;
    float Y13=o13->y-50;
    float X14=o14->x-43;
    float Y14=o14->y-50;
    float X15=o15->x-43;
    float Y15=o15->y-50;
    float X16=o16->x-43;
    float Y16=o16->y-50;
    float X17=o17->x-43;
    float Y17=o17->y-50;
    float X18=o18->x-43;
    float Y18=o18->y-50;
    float X19=o19->x-43;
    float Y19=o19->y-50;
    float X20=o20->x-43;
    float Y20=o20->y-50;
    float X21=o21->x-43;
    float Y21=o21->y-50;
    float X22=o22->x-43;
    float Y22=o22->y-50;
    float X23=o23->x-43;
    float Y23=o23->y-50;
    float X24=o24->x-43;
    float Y24=o24->y-50;
    float X25=o25->x-43;
    float Y25=o25->y-50;
    float X26=o26->x-43;
    float Y26=o26->y-50;
    float X27=o27->x-43;
    float Y27=o27->y-50;
    float X28=o28->x-43;
    float Y28=o28->y-50;
    float X29=o29->x-43;
    float Y29=o29->y-50;
    float X30=o30->x-43;
    float Y30=o30->y-50;
    float X31=o31->x-43;
    float Y31=o31->y-50;
    float X32=o32->x-43;
    float Y32=o32->y-50;
    float X33=o33->x-43;
    float Y33=o33->y-50;
    float X34=o34->x-43;
    float Y34=o34->y-50;
    float X35=o35->x-43;
    float Y35=o35->y-50;
    float X36=o36->x-43;
    float Y36=o36->y-50;
    float X37=o37->x-43;
    float Y37=o37->y-50;
    float r2 = 49;
    float r3 = 49;
    float r4 = 49;
    float r5 = 49;
    float r6 = 49;
    float r7 = 49;
    float r8 = 49;
    float r9 = 49;
    float r10 = 49;
    float r11 = 49;
    float r12 = 49;
    float r13 = 49;
    float r14 = 49;
    float r15 = 49;
    float r16 = 49;
    float r17 = 49;
    float r18 = 49;
    float r19 = 49;
    float r20 = 49;
    float r21 = 49;
    float r22 = 49;
    float r23 = 49;
    float r24 = 49;
    float r25 = 49;
    float r26 = 49;
    float r27 = 49;
    float r28 = 49;
    float r29 = 49;
    float r30 = 49;
    float r31 = 49;
    float r32 = 49;
    float r33 = 49;
    float r34 = 49;
    float r35 = 49;
    float r36 = 49;
    float r37 = 49;
    while (app.isOpen())
    {
         if(clock2.getElapsedTime().asMilliseconds()<3000)
                {
                    app.clear();
                    LifeBar lifeBarPlayer;
                    app.draw(background);
                    std::ostringstream playerScoreString;
                    Font font;
                    font.loadFromFile("ALGER.TTF");
                    Text text("", font, 20);
                    text.setColor(Color::Red);
                    text.setStyle(Text::Bold);
                    text.setString("SCORE:");
                    text.setPosition(1750,0);
                    app.draw(text);
                    Text text2("", font, 20);
                    playerScoreString <<*score ;
                    text2.setString(playerScoreString.str());
                    text2.setPosition(1825,0);
                    app.draw(text2);
                    std::ostringstream combostr;
                    Font font1;
                    font.loadFromFile("font.ttf");
                    Text text3("", font, 40);
                    combostr <<*combo ;
                    Color clr(100,200,255,100);
                    text3.setColor(clr);
                    text3.setStyle(Text::Bold);
                    text3.setString(combostr.str());
                    text3.setPosition(20,1030);
                    app.draw(text3);//рисую этот текст
                    hpdraintime(HP);
                    lifeBarPlayer.update(*HP);
                    lifeBarPlayer.draw(app);
                    app.display();

                }
                else {i=1;clock1.restart();music->play();}
        while((*HP>0)&&i>0)
        {
        Vector2f mouse_world =  app.mapPixelToCoords(Mouse::getPosition( app ) );
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
                if(event.type== Event::MouseButtonPressed)
                        if((event.mouseButton.button == Mouse::Left)||(event.mouseButton.button == Mouse::Right))
                        {
                            if(o2!=nullptr&&(((mouse_world.x>=(o2->x)-24)&&(mouse_world.x<=(o2->x)+24))&&((mouse_world.y>=(o2->y)-24)&&(mouse_world.y<=(o2->y)+24))))

                            if(((clock1.getElapsedTime().asMilliseconds()>=285-62)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62))&&o2!=nullptr)//300
                            {
                                hit300.setPosition(X3,Y3);
                                o2=nullptr;
                                delete o2;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=285-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=285-62))&&o2!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=285+62)&&(clock1.getElapsedTime().asMilliseconds()<=285+62+54))&&o2!=nullptr))//100
                            {
                                hit100.setPosition(X3,Y3);
                                o2=nullptr;
                                delete o2;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1342-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=285-62-54))&&o2!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=285+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=285+62+54+54))&&o2!=nullptr))//50
                            {
                                hit50.setPosition(X3,Y3);
                                o2=nullptr;
                                delete o2;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }

                            if(o3!=nullptr&&(((mouse_world.x>=(o3->x)-24)&&(mouse_world.x<=(o3->x)+24))&&((mouse_world.y>=(o3->y)-24)&&(mouse_world.y<=(o3->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=1342-62)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62))&&o3!=nullptr)//300
                            {
                                hit300.setPosition(X3,Y3);
                                o3=nullptr;
                                delete o3;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1342-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=1342-62))&&o3!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1342+62)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62+54))&&o3!=nullptr))//100
                            {
                                hit100.setPosition(X3,Y3);
                                o3=nullptr;
                                delete o3;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1342-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=1342-62-54))&&o3!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1342+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62+54+54))&&o3!=nullptr))//50
                            {
                                hit50.setPosition(X3,Y3);
                                o3=nullptr;
                                delete o3;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o4!=nullptr&&(((mouse_world.x>=(o4->x)-24)&&(mouse_world.x<=(o4->x)+24))&&((mouse_world.y>=(o4->y)-24)&&(mouse_world.y<=(o4->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=1764-62)&&(clock1.getElapsedTime().asMilliseconds()<=1764+62))&&o4!=nullptr)//300
                            {
                                hit300.setPosition(X4,Y4);
                                o4=nullptr;
                                delete o4;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1764-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=1764-62))&&o4!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1764+62)&&(clock1.getElapsedTime().asMilliseconds()<=1764+62+54))&&o4!=nullptr))//100
                            {
                                hit100.setPosition(X4,Y4);
                                o4=nullptr;
                                delete o4;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1764-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=1764-62-54))&&o4!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1764+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=1764+62+54+54))&&o4!=nullptr))//50
                            {
                                hit50.setPosition(X4,Y4);
                                o4=nullptr;
                                delete o4;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o5!=nullptr&&(((mouse_world.x>=(o5->x)-24)&&(mouse_world.x<=(o5->x)+24))&&((mouse_world.y>=(o5->y)-24)&&(mouse_world.y<=(o5->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=2609-62)&&(clock1.getElapsedTime().asMilliseconds()<=2609+62))&&o5!=nullptr)//300
                            {
                                hit300.setPosition(X5,Y5);
                                o5=nullptr;
                                delete o5;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=2609-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=2609-62))&&o5!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=2609+62)&&(clock1.getElapsedTime().asMilliseconds()<=2609+62+54))&&o5!=nullptr))//100
                            {
                                hit100.setPosition(X5,Y5);
                                o5=nullptr;
                                delete o5;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=2609-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=2609-62-54))&&o5!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=2609+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=2609+62+54+54))&&o5!=nullptr))//50
                            {
                                hit50.setPosition(X5,Y5);
                                o5=nullptr;
                                delete o5;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o6!=nullptr&&(((mouse_world.x>=(o6->x)-24)&&(mouse_world.x<=(o6->x)+24))&&((mouse_world.y>=(o6->y)-24)&&(mouse_world.y<=(o6->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=3032-62)&&(clock1.getElapsedTime().asMilliseconds()<=3032+62))&&o6!=nullptr)//300
                            {
                                hit300.setPosition(X6,Y6);
                                o6=nullptr;
                                delete o6;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3032-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=3032-62))&&o6!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3032+62)&&(clock1.getElapsedTime().asMilliseconds()<=3032+62+54))&&o6!=nullptr))//100
                            {
                                hit100.setPosition(X6,Y6);
                                o6=nullptr;
                                delete o6;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3032-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=3032-62-54))&&o6!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3032+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=3032+62+54+54))&&o6!=nullptr))//50
                            {
                                hit50.setPosition(X6,Y6);
                                o6=nullptr;
                                delete o6;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o7!=nullptr&&(((mouse_world.x>=(o7->x)-24)&&(mouse_world.x<=(o7->x)+24))&&((mouse_world.y>=(o7->y)-24)&&(mouse_world.y<=(o7->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=3877-62)&&(clock1.getElapsedTime().asMilliseconds()<=3877+62))&&o7!=nullptr)//300
                            {
                                hit300.setPosition(X7,Y7);
                                o7=nullptr;
                                delete o7;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3877-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=3877-62))&&o7!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3877+62)&&(clock1.getElapsedTime().asMilliseconds()<=3877+62+54))&&o7!=nullptr))//100
                            {
                                hit100.setPosition(X7,Y7);
                                o7=nullptr;
                                delete o7;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3877-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=3877-62-54))&&o7!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3877+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=3877+62+54+54))&&o7!=nullptr))//50
                            {
                                hit50.setPosition(X7,Y7);
                                o7=nullptr;
                                delete o7;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o8!=nullptr&&(((mouse_world.x>=(o8->x)-24)&&(mouse_world.x<=(o8->x)+24))&&((mouse_world.y>=(o8->y)-24)&&(mouse_world.y<=(o8->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=4722-62)&&(clock1.getElapsedTime().asMilliseconds()<=4722+62))&&o8!=nullptr)//300
                            {
                                hit300.setPosition(X8,Y8);
                                o8=nullptr;
                                delete o8;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=4722-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=4722-62))&&o8!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=4722+62)&&(clock1.getElapsedTime().asMilliseconds()<=4722+62+54))&&o8!=nullptr))//100
                            {
                                hit100.setPosition(X8,Y8);
                                o8=nullptr;
                                delete o8;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=4722-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=4722-62-54))&&o8!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=4722+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=4722+62+54+54))&&o8!=nullptr))//50
                            {
                                hit50.setPosition(X8,Y8);
                                o8=nullptr;
                                delete o8;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o9!=nullptr&&(((mouse_world.x>=(o9->x)-24)&&(mouse_world.x<=(o9->x)+24))&&((mouse_world.y>=(o9->y)-24)&&(mouse_world.y<=(o9->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=5567-62)&&(clock1.getElapsedTime().asMilliseconds()<=5567+62))&&o9!=nullptr)//300
                            {
                                hit300.setPosition(X9,Y9);
                                o9=nullptr;
                                delete o9;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=5567-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=5567-62))&&o9!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=5567+62)&&(clock1.getElapsedTime().asMilliseconds()<=5567+62+54))&&o9!=nullptr))//100
                            {
                                hit100.setPosition(X9,Y9);
                                o9=nullptr;
                                delete o9;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=5567-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=5567-62-54))&&o9!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=5567+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=5567+62+54+54))&&o9!=nullptr))//50
                            {
                                hit50.setPosition(X9,Y9);
                                o9=nullptr;
                                delete o9;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o10!=nullptr&&(((mouse_world.x>=(o10->x)-24)&&(mouse_world.x<=(o10->x)+24))&&((mouse_world.y>=(o10->y)-24)&&(mouse_world.y<=(o10->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=6412-62)&&(clock1.getElapsedTime().asMilliseconds()<=6412+62))&&o10!=nullptr)//300
                            {
                                hit300.setPosition(X10,Y10);
                                o10=nullptr;
                                delete o10;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=6412-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=6412-62))&&o10!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=6412+62)&&(clock1.getElapsedTime().asMilliseconds()<=6412+62+54))&&o10!=nullptr))//100
                            {
                                hit100.setPosition(X10,Y10);
                                o10=nullptr;
                                delete o10;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=6412-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=6412-62-54))&&o10!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=6412+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=6412+62+54+54))&&o10!=nullptr))//50
                            {
                                hit50.setPosition(X10,Y10);
                                o10=nullptr;
                                delete o10;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o11!=nullptr&&(((mouse_world.x>=(o11->x)-24)&&(mouse_world.x<=(o11->x)+24))&&((mouse_world.y>=(o11->y)-24)&&(mouse_world.y<=(o11->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=7680-62)&&(clock1.getElapsedTime().asMilliseconds()<=7680+62))&&o11!=nullptr)//300
                            {
                                hit300.setPosition(X11,Y11);
                                o11=nullptr;
                                delete o11;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=7680-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=7680-62))&&o11!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=7680+62)&&(clock1.getElapsedTime().asMilliseconds()<=7680+62+54))&&o11!=nullptr))//100
                            {
                                hit100.setPosition(X11,Y11);
                                o11=nullptr;
                                delete o11;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=7680-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=7680-62-54))&&o11!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=7680+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=7680+62+54+54))&&o11!=nullptr))//50
                            {
                                hit50.setPosition(X11,Y11);
                                o11=nullptr;
                                delete o11;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o12!=nullptr&&(((mouse_world.x>=(o12->x)-24)&&(mouse_world.x<=(o12->x)+24))&&((mouse_world.y>=(o12->y)-24)&&(mouse_world.y<=(o12->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=8102-62)&&(clock1.getElapsedTime().asMilliseconds()<=8102+62))&&o12!=nullptr)//300
                            {
                                hit300.setPosition(X12,Y12);
                                o12=nullptr;
                                delete o12;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8102-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=8102-62))&&o12!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8102+62)&&(clock1.getElapsedTime().asMilliseconds()<=8102+62+54))&&o12!=nullptr))//100
                            {
                                hit100.setPosition(X12,Y12);
                                o12=nullptr;
                                delete o12;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8102-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=8102-62-54))&&o12!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8102+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=8102+62+54+54))&&o12!=nullptr))//50
                            {
                                hit50.setPosition(X12,Y12);
                                o12=nullptr;
                                delete o12;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o13!=nullptr&&(((mouse_world.x>=(o13->x)-24)&&(mouse_world.x<=(o13->x)+24))&&((mouse_world.y>=(o13->y)-24)&&(mouse_world.y<=(o13->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=8947-62)&&(clock1.getElapsedTime().asMilliseconds()<=8947+62))&&o13!=nullptr)//300
                            {
                                hit300.setPosition(X13,Y13);
                                o13=nullptr;
                                delete o13;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8947-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=8947-62))&&o13!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8947+62)&&(clock1.getElapsedTime().asMilliseconds()<=8947+62+54))&&o13!=nullptr))//100
                            {
                                hit100.setPosition(X13,Y13);
                                o13=nullptr;
                                delete o13;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8947-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=8947-62-54))&&o13!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8947+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=8947+62+54+54))&&o13!=nullptr))//50
                            {
                                hit50.setPosition(X13,Y13);
                                o13=nullptr;
                                delete o13;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o14!=nullptr&&(((mouse_world.x>=(o14->x)-24)&&(mouse_world.x<=(o14->x)+24))&&((mouse_world.y>=(o14->y)-24)&&(mouse_world.y<=(o14->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=9792-62)&&(clock1.getElapsedTime().asMilliseconds()<=9792+62))&&o14!=nullptr)//300
                            {
                                hit300.setPosition(X14,Y14);
                                o14=nullptr;
                                delete o14;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=9792-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=9792-62))&&o14!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=9792+62)&&(clock1.getElapsedTime().asMilliseconds()<=9792+62+54))&&o14!=nullptr))//100
                            {
                                hit100.setPosition(X14,Y14);
                                o14=nullptr;
                                delete o14;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=9792-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=9792-62-54))&&o14!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=9792+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=9792+62+54+54))&&o14!=nullptr))//50
                            {
                                hit50.setPosition(X14,Y14);
                                o14=nullptr;
                                delete o14;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o15!=nullptr&&(((mouse_world.x>=(o15->x)-24)&&(mouse_world.x<=(o15->x)+24))&&((mouse_world.y>=(o15->y)-24)&&(mouse_world.y<=(o15->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=10637-62)&&(clock1.getElapsedTime().asMilliseconds()<=10637+62))&&o15!=nullptr)//300
                            {
                                hit300.setPosition(X15,Y15);
                                o15=nullptr;
                                delete o15;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=10637-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=10637-62))&&o15!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=10637+62)&&(clock1.getElapsedTime().asMilliseconds()<=10637+62+54))&&o15!=nullptr))//100
                            {
                                hit100.setPosition(X15,Y15);
                                o15=nullptr;
                                delete o15;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=10637-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=10637-62-54))&&o15!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=10637+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=10637+62+54+54))&&o15!=nullptr))//50
                            {
                                hit50.setPosition(X15,Y15);
                                o15=nullptr;
                                delete o15;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o16!=nullptr&&(((mouse_world.x>=(o16->x)-24)&&(mouse_world.x<=(o16->x)+24))&&((mouse_world.y>=(o16->y)-24)&&(mouse_world.y<=(o16->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=11482-62)&&(clock1.getElapsedTime().asMilliseconds()<=11482+62))&&o16!=nullptr)//300
                            {
                                hit300.setPosition(X16,Y16);
                                o16=nullptr;
                                delete o16;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=11482-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=11482-62))&&o16!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=11482+62)&&(clock1.getElapsedTime().asMilliseconds()<=11482+62+54))&&o16!=nullptr))//100
                            {
                                hit100.setPosition(X16,Y16);
                                o16=nullptr;
                                delete o16;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=11482-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=11482-62-54))&&o16!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=11482+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=11482+62+54+54))&&o16!=nullptr))//50
                            {
                                hit50.setPosition(X16,Y16);
                                o16=nullptr;
                                delete o16;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o17!=nullptr&&(((mouse_world.x>=(o17->x)-24)&&(mouse_world.x<=(o17->x)+24))&&((mouse_world.y>=(o17->y)-24)&&(mouse_world.y<=(o17->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=12328-62)&&(clock1.getElapsedTime().asMilliseconds()<=12328+62))&&o17!=nullptr)//300
                            {
                                hit300.setPosition(X17,Y17);
                                o17=nullptr;
                                delete o17;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=12328-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=12328-62))&&o17!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=12328+62)&&(clock1.getElapsedTime().asMilliseconds()<=12328+62+54))&&o17!=nullptr))//100
                            {
                                hit100.setPosition(X17,Y17);
                                o17=nullptr;
                                delete o17;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=12328-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=12328-62-54))&&o17!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=12328+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=12328+62+54+54))&&o17!=nullptr))//50
                            {
                                hit50.setPosition(X17,Y17);
                                o17=nullptr;
                                delete o17;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o18!=nullptr&&(((mouse_world.x>=(o18->x)-24)&&(mouse_world.x<=(o18->x)+24))&&((mouse_world.y>=(o18->y)-24)&&(mouse_world.y<=(o18->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=13173-62)&&(clock1.getElapsedTime().asMilliseconds()<=13173+62))&&o18!=nullptr)//300
                            {
                                hit300.setPosition(X18,Y18);
                                o18=nullptr;
                                delete o18;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=13173-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=13173-62))&&o18!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=13173+62)&&(clock1.getElapsedTime().asMilliseconds()<=13173+62+54))&&o18!=nullptr))//100
                            {
                                hit100.setPosition(X18,Y18);
                                o18=nullptr;
                                delete o18;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=13173-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=13173-62-54))&&o18!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=13173+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=13173+62+54+54))&&o18!=nullptr))//50
                            {
                                hit50.setPosition(X18,Y18);
                                o18=nullptr;
                                delete o18;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o19!=nullptr&&(((mouse_world.x>=(o19->x)-24)&&(mouse_world.x<=(o19->x)+24))&&((mouse_world.y>=(o19->y)-24)&&(mouse_world.y<=(o19->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=14440-62)&&(clock1.getElapsedTime().asMilliseconds()<=14440+62))&&o19!=nullptr)//300
                            {
                                hit300.setPosition(X19,Y19);
                                o19=nullptr;
                                delete o19;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14440-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=14440-62))&&o19!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14440+62)&&(clock1.getElapsedTime().asMilliseconds()<=14440+62+54))&&o19!=nullptr))//100
                            {
                                hit100.setPosition(X19,Y19);
                                o19=nullptr;
                                delete o19;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14440-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=14440-62-54))&&o19!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14440+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=14440+62+54+54))&&o19!=nullptr))//50
                            {
                                hit50.setPosition(X19,Y19);
                                o19=nullptr;
                                delete o19;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o20!=nullptr&&(((mouse_world.x>=(o20->x)-24)&&(mouse_world.x<=(o20->x)+24))&&((mouse_world.y>=(o20->y)-24)&&(mouse_world.y<=(o20->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=14863-62)&&(clock1.getElapsedTime().asMilliseconds()<=14863+62))&&o20!=nullptr)//300
                            {
                                hit300.setPosition(X20,Y20);
                                o20=nullptr;
                                delete o20;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14863-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=14863-62))&&o20!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14863+62)&&(clock1.getElapsedTime().asMilliseconds()<=14863+62+54))&&o20!=nullptr))//100
                            {
                                hit100.setPosition(X20,Y20);
                                o20=nullptr;
                                delete o20;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14863-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=14863-62-54))&&o20!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14863+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=14863+62+54+54))&&o20!=nullptr))//50
                            {
                                hit50.setPosition(X20,Y20);
                                o20=nullptr;
                                delete o20;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o21!=nullptr&&(((mouse_world.x>=(o21->x)-24)&&(mouse_world.x<=(o21->x)+24))&&((mouse_world.y>=(o21->y)-24)&&(mouse_world.y<=(o21->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=15708-62)&&(clock1.getElapsedTime().asMilliseconds()<=15708+62))&&o21!=nullptr)//300
                            {
                                hit300.setPosition(X21,Y21);
                                o21=nullptr;
                                delete o21;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=15708-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=15708-62))&&o21!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=15708+62)&&(clock1.getElapsedTime().asMilliseconds()<=15708+62+54))&&o21!=nullptr))//100
                            {
                                hit100.setPosition(X21,Y21);
                                o21=nullptr;
                                delete o21;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=15708-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=15708-62-54))&&o21!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=15708+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=15708+62+54+54))&&o21!=nullptr))//50
                            {
                                hit50.setPosition(X21,Y21);
                                o21=nullptr;
                                delete o21;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o22!=nullptr&&(((mouse_world.x>=(o22->x)-24)&&(mouse_world.x<=(o22->x)+24))&&((mouse_world.y>=(o22->y)-24)&&(mouse_world.y<=(o22->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=16553-62)&&(clock1.getElapsedTime().asMilliseconds()<=16553+62))&&o22!=nullptr)//300
                            {
                                hit300.setPosition(X22,Y22);
                                o22=nullptr;
                                delete o22;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=16553-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=16553-62))&&o22!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=16553+62)&&(clock1.getElapsedTime().asMilliseconds()<=16553+62+54))&&o22!=nullptr))//100
                            {
                                hit100.setPosition(X22,Y22);
                                o22=nullptr;
                                delete o22;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=16553-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=16553-62-54))&&o22!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=16553+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=16553+62+54+54))&&o22!=nullptr))//50
                            {
                                hit50.setPosition(X22,Y22);
                                o22=nullptr;
                                delete o22;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o23!=nullptr&&(((mouse_world.x>=(o23->x)-24)&&(mouse_world.x<=(o23->x)+24))&&((mouse_world.y>=(o23->y)-24)&&(mouse_world.y<=(o23->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=17821-62)&&(clock1.getElapsedTime().asMilliseconds()<=17821+62))&&o23!=nullptr)//300
                            {
                                hit300.setPosition(X23,Y23);
                                o23=nullptr;
                                delete o23;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=17821-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=17821-62))&&o23!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=17821+62)&&(clock1.getElapsedTime().asMilliseconds()<=17821+62+54))&&o23!=nullptr))//100
                            {
                                hit100.setPosition(X23,Y23);
                                o23=nullptr;
                                delete o23;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=17821-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=17821-62-54))&&o23!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=17821+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=17821+62+54+54))&&o23!=nullptr))//50
                            {
                                hit50.setPosition(X23,Y23);
                                o23=nullptr;
                                delete o23;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o24!=nullptr&&(((mouse_world.x>=(o24->x)-24)&&(mouse_world.x<=(o24->x)+24))&&((mouse_world.y>=(o24->y)-24)&&(mouse_world.y<=(o24->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=18243-62)&&(clock1.getElapsedTime().asMilliseconds()<=18243+62))&&o24!=nullptr)//300
                            {
                                hit300.setPosition(X24,Y24);
                                o24=nullptr;
                                delete o24;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=18243-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=18243-62))&&o24!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=18243+62)&&(clock1.getElapsedTime().asMilliseconds()<=18243+62+54))&&o24!=nullptr))//100
                            {
                                hit100.setPosition(X24,Y24);
                                o24=nullptr;
                                delete o24;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=18243-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=18243-62-54))&&o24!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=18243+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=18243+62+54+54))&&o24!=nullptr))//50
                            {
                                hit50.setPosition(X24,Y24);
                                o24=nullptr;
                                delete o24;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o25!=nullptr&&(((mouse_world.x>=(o25->x)-24)&&(mouse_world.x<=(o25->x)+24))&&((mouse_world.y>=(o25->y)-24)&&(mouse_world.y<=(o25->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=19088-62)&&(clock1.getElapsedTime().asMilliseconds()<=19088+62))&&o25!=nullptr)//300
                            {
                                hit300.setPosition(X25,Y25);
                                o25=nullptr;
                                delete o25;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19088-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=19088-62))&&o25!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19088+62)&&(clock1.getElapsedTime().asMilliseconds()<=19088+62+54))&&o25!=nullptr))//100
                            {
                                hit100.setPosition(X25,Y25);
                                o25=nullptr;
                                delete o25;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19088-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=19088-62-54))&&o25!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19088+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=19088+62+54+54))&&o25!=nullptr))//50
                            {
                                hit50.setPosition(X25,Y25);
                                o25=nullptr;
                                delete o25;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o26!=nullptr&&(((mouse_world.x>=(o26->x)-24)&&(mouse_world.x<=(o26->x)+24))&&((mouse_world.y>=(o26->y)-24)&&(mouse_world.y<=(o26->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=19933-62)&&(clock1.getElapsedTime().asMilliseconds()<=19933+62))&&o26!=nullptr)//300
                            {
                                hit300.setPosition(X26,Y26);
                                o26=nullptr;
                                delete o26;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19933-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=19933-62))&&o26!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19933+62)&&(clock1.getElapsedTime().asMilliseconds()<=19933+62+54))&&o26!=nullptr))//100
                            {
                                hit100.setPosition(X26,Y26);
                                o26=nullptr;
                                delete o26;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19933-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=19933-62-54))&&o26!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19933+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=19933+62+54+54))&&o26!=nullptr))//50
                            {
                                hit50.setPosition(X26,Y26);
                                o26=nullptr;
                                delete o26;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o27!=nullptr&&(((mouse_world.x>=(o27->x)-24)&&(mouse_world.x<=(o27->x)+24))&&((mouse_world.y>=(o27->y)-24)&&(mouse_world.y<=(o27->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=21201-62)&&(clock1.getElapsedTime().asMilliseconds()<=21201+62))&&o27!=nullptr)//300
                            {
                                hit300.setPosition(X27,Y27);
                                o27=nullptr;
                                delete o27;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21201-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=21201-62))&&o27!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21201+62)&&(clock1.getElapsedTime().asMilliseconds()<=21201+62+54))&&o27!=nullptr))//100
                            {
                                hit100.setPosition(X27,Y27);
                                o27=nullptr;
                                delete o27;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21201-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=21201-62-54))&&o27!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21201+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=21201+62+54+54))&&o27!=nullptr))//50
                            {
                                hit50.setPosition(X27,Y27);
                                o27=nullptr;
                                delete o27;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o28!=nullptr&&(((mouse_world.x>=(o28->x)-24)&&(mouse_world.x<=(o28->x)+24))&&((mouse_world.y>=(o28->y)-24)&&(mouse_world.y<=(o28->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=21623-62)&&(clock1.getElapsedTime().asMilliseconds()<=21623+62))&&o28!=nullptr)//300
                            {
                                hit300.setPosition(X28,Y28);
                                o28=nullptr;
                                delete o28;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21623-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=21623-62))&&o28!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21623+62)&&(clock1.getElapsedTime().asMilliseconds()<=21623+62+54))&&o28!=nullptr))//100
                            {
                                hit100.setPosition(X28,Y28);
                                o28=nullptr;
                                delete o28;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21623-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=21623-62-54))&&o28!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21623+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=21623+62+54+54))&&o28!=nullptr))//50
                            {
                                hit50.setPosition(X28,Y28);
                                o28=nullptr;
                                delete o28;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o29!=nullptr&&(((mouse_world.x>=(o29->x)-24)&&(mouse_world.x<=(o29->x)+24))&&((mouse_world.y>=(o29->y)-24)&&(mouse_world.y<=(o29->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=22468-62)&&(clock1.getElapsedTime().asMilliseconds()<=22468+62))&&o29!=nullptr)//300
                            {
                                hit300.setPosition(X29,Y29);
                                o29=nullptr;
                                delete o29;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=22468-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=22468-62))&&o29!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=22468+62)&&(clock1.getElapsedTime().asMilliseconds()<=22468+62+54))&&o29!=nullptr))//100
                            {
                                hit100.setPosition(X29,Y29);
                                o29=nullptr;
                                delete o29;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=22468-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=22468-62-54))&&o29!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=22468+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=22468+62+54+54))&&o29!=nullptr))//50
                            {
                                hit50.setPosition(X29,Y29);
                                o29=nullptr;
                                delete o29;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o30!=nullptr&&(((mouse_world.x>=(o30->x)-24)&&(mouse_world.x<=(o30->x)+24))&&((mouse_world.y>=(o30->y)-24)&&(mouse_world.y<=(o30->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=23102-62)&&(clock1.getElapsedTime().asMilliseconds()<=23102+62))&&o30!=nullptr)//300
                            {
                                hit300.setPosition(X30,Y30);
                                o30=nullptr;
                                delete o30;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=23102-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=23102-62))&&o30!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=23102+62)&&(clock1.getElapsedTime().asMilliseconds()<=23102+62+54))&&o30!=nullptr))//100
                            {
                                hit100.setPosition(X30,Y30);
                                o30=nullptr;
                                delete o30;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=23102-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=23102-62-54))&&o30!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=23102+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=23102+62+54+54))&&o30!=nullptr))//50
                            {
                                hit50.setPosition(X30,Y30);
                                o30=nullptr;
                                delete o30;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o31!=nullptr&&(((mouse_world.x>=(o31->x)-24)&&(mouse_world.x<=(o31->x)+24))&&((mouse_world.y>=(o31->y)-24)&&(mouse_world.y<=(o31->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=24159-62)&&(clock1.getElapsedTime().asMilliseconds()<=24159+62))&&o31!=nullptr)//300
                            {
                                hit300.setPosition(X31,Y31);
                                o31=nullptr;
                                delete o31;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24159-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=24159-62))&&o31!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24159+62)&&(clock1.getElapsedTime().asMilliseconds()<=24159+62+54))&&o31!=nullptr))//100
                            {
                                hit100.setPosition(X31,Y31);
                                o31=nullptr;
                                delete o31;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24159-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=24159-62-54))&&o31!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24159+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=24159+62+54+54))&&o31!=nullptr))//50
                            {
                                hit50.setPosition(X31,Y31);
                                o31=nullptr;
                                delete o31;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o32!=nullptr&&(((mouse_world.x>=(o32->x)-24)&&(mouse_world.x<=(o32->x)+24))&&((mouse_world.y>=(o32->y)-24)&&(mouse_world.y<=(o32->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=24792-62)&&(clock1.getElapsedTime().asMilliseconds()<=24792+62))&&o32!=nullptr)//300
                            {
                                hit300.setPosition(X32,Y32);
                                o32=nullptr;
                                delete o32;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24792-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=24792-62))&&o32!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24792+62)&&(clock1.getElapsedTime().asMilliseconds()<=24792+62+54))&&o32!=nullptr))//100
                            {
                                hit100.setPosition(X32,Y32);
                                o32=nullptr;
                                delete o32;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24792-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=24792-62-54))&&o32!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24792+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=24792+62+54+54))&&o32!=nullptr))//50
                            {
                                hit50.setPosition(X32,Y32);
                                o32=nullptr;
                                delete o32;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o33!=nullptr&&(((mouse_world.x>=(o33->x)-24)&&(mouse_world.x<=(o33->x)+24))&&((mouse_world.y>=(o33->y)-24)&&(mouse_world.y<=(o33->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=25849-62)&&(clock1.getElapsedTime().asMilliseconds()<=25849+62))&&o33!=nullptr)//300
                            {
                                hit300.setPosition(X33,Y33);
                                o33=nullptr;
                                delete o33;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=25849-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=25849-62))&&o33!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=25849+62)&&(clock1.getElapsedTime().asMilliseconds()<=25849+62+54))&&o33!=nullptr))//100
                            {
                                hit100.setPosition(X33,Y33);
                                o33=nullptr;
                                delete o33;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=25849-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=25849-62-54))&&o33!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=25849+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=25849+62+54+54))&&o33!=nullptr))//50
                            {
                                hit50.setPosition(X33,Y33);
                                o33=nullptr;
                                delete o33;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o34!=nullptr&&(((mouse_world.x>=(o34->x)-24)&&(mouse_world.x<=(o34->x)+24))&&((mouse_world.y>=(o34->y)-24)&&(mouse_world.y<=(o34->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=26482-62)&&(clock1.getElapsedTime().asMilliseconds()<=26482+62))&&o34!=nullptr)//300
                            {
                                hit300.setPosition(X34,Y34);
                                o34=nullptr;
                                delete o34;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=26482-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=26482-62))&&o34!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=26482+62)&&(clock1.getElapsedTime().asMilliseconds()<=26482+62+54))&&o34!=nullptr))//100
                            {
                                hit100.setPosition(X34,Y34);
                                o34=nullptr;
                                delete o34;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=26482-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=26482-62-54))&&o34!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=26482+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=26482+62+54+54))&&o34!=nullptr))//50
                            {
                                hit50.setPosition(X34,Y34);
                                o34=nullptr;
                                delete o34;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o35!=nullptr&&(((mouse_world.x>=(o35->x)-24)&&(mouse_world.x<=(o35->x)+24))&&((mouse_world.y>=(o35->y)-24)&&(mouse_world.y<=(o35->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=27539-62)&&(clock1.getElapsedTime().asMilliseconds()<=27539+62))&&o35!=nullptr)//300
                            {
                                hit300.setPosition(X35,Y35);
                                o35=nullptr;
                                delete o35;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=27539-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=27539-62))&&o35!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=27539+62)&&(clock1.getElapsedTime().asMilliseconds()<=27539+62+54))&&o35!=nullptr))//100
                            {
                                hit100.setPosition(X35,Y35);
                                o35=nullptr;
                                delete o35;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=27539-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=27539-62-54))&&o35!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=27539+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=27539+62+54+54))&&o35!=nullptr))//50
                            {
                                hit50.setPosition(X35,Y35);
                                o35=nullptr;
                                delete o35;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o36!=nullptr&&(((mouse_world.x>=(o36->x)-24)&&(mouse_world.x<=(o36->x)+24))&&((mouse_world.y>=(o36->y)-24)&&(mouse_world.y<=(o36->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=28384-62)&&(clock1.getElapsedTime().asMilliseconds()<=28384+62))&&o36!=nullptr)//300
                            {
                                hit300.setPosition(X36,Y36);
                                o36=nullptr;
                                delete o36;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28384-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=28384-62))&&o36!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28384+62)&&(clock1.getElapsedTime().asMilliseconds()<=28384+62+54))&&o36!=nullptr))//100
                            {
                                hit100.setPosition(X36,Y36);
                                o36=nullptr;
                                delete o36;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28384-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=28384-62-54))&&o36!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28384+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=28384+62+54+54))&&o36!=nullptr))//50
                            {
                                hit50.setPosition(X36,Y36);
                                o36=nullptr;
                                delete o36;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o37!=nullptr&&(((mouse_world.x>=(o37->x)-24)&&(mouse_world.x<=(o37->x)+24))&&((mouse_world.y>=(o37->y)-24)&&(mouse_world.y<=(o37->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=28490-62)&&(clock1.getElapsedTime().asMilliseconds()<=28490+62))&&o37!=nullptr)//300
                            {
                                hit300.setPosition(X37,Y37);
                                o37=nullptr;
                                delete o37;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28490-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=28490-62))&&o37!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28490+62)&&(clock1.getElapsedTime().asMilliseconds()<=28490+62+54))&&o37!=nullptr))//100
                            {
                                hit100.setPosition(X37,Y37);
                                o37=nullptr;
                                delete o37;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28490-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=28490-62-54))&&o37!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28490+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=28490+62+54+54))&&o37!=nullptr))//50
                            {
                                hit50.setPosition(X37,Y37);
                                o37=nullptr;
                                delete o37;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                        }

            if (event.type == sf::Event::KeyReleased)
            if (event.key.code == Keyboard::Escape) return true;
            if (event.key.code == sf::Keyboard::R) Gameplay(app,music);//Рестарт
            else if ((event.key.code == sf::Keyboard::Z)||(event.key.code == sf::Keyboard::X)||(event.key.code == sf::Keyboard::Left)||(event.key.code == sf::Keyboard::Down))
                        {
                            if(o2!=nullptr&&(((mouse_world.x>=(o2->x)-24)&&(mouse_world.x<=(o2->x)+24))&&((mouse_world.y>=(o2->y)-24)&&(mouse_world.y<=(o2->y)+24))))

                            if(((clock1.getElapsedTime().asMilliseconds()>=285-62)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62))&&o2!=nullptr)//300
                            {
                                hit300.setPosition(X3,Y3);
                                o2=nullptr;
                                delete o2;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=285-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=285-62))&&o2!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=285+62)&&(clock1.getElapsedTime().asMilliseconds()<=285+62+54))&&o2!=nullptr))//100
                            {
                                hit100.setPosition(X3,Y3);
                                o2=nullptr;
                                delete o2;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1342-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=285-62-54))&&o2!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=285+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=285+62+54+54))&&o2!=nullptr))//50
                            {
                                hit50.setPosition(X3,Y3);
                                o2=nullptr;
                                delete o2;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }

                            if(o3!=nullptr&&(((mouse_world.x>=(o3->x)-24)&&(mouse_world.x<=(o3->x)+24))&&((mouse_world.y>=(o3->y)-24)&&(mouse_world.y<=(o3->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=1342-62)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62))&&o3!=nullptr)//300
                            {
                                hit300.setPosition(X3,Y3);
                                o3=nullptr;
                                delete o3;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1342-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=1342-62))&&o3!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1342+62)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62+54))&&o3!=nullptr))//100
                            {
                                hit100.setPosition(X3,Y3);
                                o3=nullptr;
                                delete o3;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1342-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=1342-62-54))&&o3!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1342+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=1342+62+54+54))&&o3!=nullptr))//50
                            {
                                hit50.setPosition(X3,Y3);
                                o3=nullptr;
                                delete o3;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o4!=nullptr&&(((mouse_world.x>=(o4->x)-24)&&(mouse_world.x<=(o4->x)+24))&&((mouse_world.y>=(o4->y)-24)&&(mouse_world.y<=(o4->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=1764-62)&&(clock1.getElapsedTime().asMilliseconds()<=1764+62))&&o4!=nullptr)//300
                            {
                                hit300.setPosition(X4,Y4);
                                o4=nullptr;
                                delete o4;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1764-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=1764-62))&&o4!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1764+62)&&(clock1.getElapsedTime().asMilliseconds()<=1764+62+54))&&o4!=nullptr))//100
                            {
                                hit100.setPosition(X4,Y4);
                                o4=nullptr;
                                delete o4;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=1764-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=1764-62-54))&&o4!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=1764+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=1764+62+54+54))&&o4!=nullptr))//50
                            {
                                hit50.setPosition(X4,Y4);
                                o4=nullptr;
                                delete o4;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o5!=nullptr&&(((mouse_world.x>=(o5->x)-24)&&(mouse_world.x<=(o5->x)+24))&&((mouse_world.y>=(o5->y)-24)&&(mouse_world.y<=(o5->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=2609-62)&&(clock1.getElapsedTime().asMilliseconds()<=2609+62))&&o5!=nullptr)//300
                            {
                                hit300.setPosition(X5,Y5);
                                o5=nullptr;
                                delete o5;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=2609-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=2609-62))&&o5!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=2609+62)&&(clock1.getElapsedTime().asMilliseconds()<=2609+62+54))&&o5!=nullptr))//100
                            {
                                hit100.setPosition(X5,Y5);
                                o5=nullptr;
                                delete o5;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=2609-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=2609-62-54))&&o5!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=2609+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=2609+62+54+54))&&o5!=nullptr))//50
                            {
                                hit50.setPosition(X5,Y5);
                                o5=nullptr;
                                delete o5;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o6!=nullptr&&(((mouse_world.x>=(o6->x)-24)&&(mouse_world.x<=(o6->x)+24))&&((mouse_world.y>=(o6->y)-24)&&(mouse_world.y<=(o6->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=3032-62)&&(clock1.getElapsedTime().asMilliseconds()<=3032+62))&&o6!=nullptr)//300
                            {
                                hit300.setPosition(X6,Y6);
                                o6=nullptr;
                                delete o6;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3032-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=3032-62))&&o6!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3032+62)&&(clock1.getElapsedTime().asMilliseconds()<=3032+62+54))&&o6!=nullptr))//100
                            {
                                hit100.setPosition(X6,Y6);
                                o6=nullptr;
                                delete o6;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3032-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=3032-62-54))&&o6!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3032+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=3032+62+54+54))&&o6!=nullptr))//50
                            {
                                hit50.setPosition(X6,Y6);
                                o6=nullptr;
                                delete o6;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o7!=nullptr&&(((mouse_world.x>=(o7->x)-24)&&(mouse_world.x<=(o7->x)+24))&&((mouse_world.y>=(o7->y)-24)&&(mouse_world.y<=(o7->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=3877-62)&&(clock1.getElapsedTime().asMilliseconds()<=3877+62))&&o7!=nullptr)//300
                            {
                                hit300.setPosition(X7,Y7);
                                o7=nullptr;
                                delete o7;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3877-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=3877-62))&&o7!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3877+62)&&(clock1.getElapsedTime().asMilliseconds()<=3877+62+54))&&o7!=nullptr))//100
                            {
                                hit100.setPosition(X7,Y7);
                                o7=nullptr;
                                delete o7;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=3877-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=3877-62-54))&&o7!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=3877+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=3877+62+54+54))&&o7!=nullptr))//50
                            {
                                hit50.setPosition(X7,Y7);
                                o7=nullptr;
                                delete o7;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o8!=nullptr&&(((mouse_world.x>=(o8->x)-24)&&(mouse_world.x<=(o8->x)+24))&&((mouse_world.y>=(o8->y)-24)&&(mouse_world.y<=(o8->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=4722-62)&&(clock1.getElapsedTime().asMilliseconds()<=4722+62))&&o8!=nullptr)//300
                            {
                                hit300.setPosition(X8,Y8);
                                o8=nullptr;
                                delete o8;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;

                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=4722-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=4722-62))&&o8!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=4722+62)&&(clock1.getElapsedTime().asMilliseconds()<=4722+62+54))&&o8!=nullptr))//100
                            {
                                hit100.setPosition(X8,Y8);
                                o8=nullptr;
                                delete o8;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=4722-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=4722-62-54))&&o8!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=4722+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=4722+62+54+54))&&o8!=nullptr))//50
                            {
                                hit50.setPosition(X8,Y8);
                                o8=nullptr;
                                delete o8;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o9!=nullptr&&(((mouse_world.x>=(o9->x)-24)&&(mouse_world.x<=(o9->x)+24))&&((mouse_world.y>=(o9->y)-24)&&(mouse_world.y<=(o9->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=5567-62)&&(clock1.getElapsedTime().asMilliseconds()<=5567+62))&&o9!=nullptr)//300
                            {
                                hit300.setPosition(X9,Y9);
                                o9=nullptr;
                                delete o9;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=5567-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=5567-62))&&o9!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=5567+62)&&(clock1.getElapsedTime().asMilliseconds()<=5567+62+54))&&o9!=nullptr))//100
                            {
                                hit100.setPosition(X9,Y9);
                                o9=nullptr;
                                delete o9;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=5567-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=5567-62-54))&&o9!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=5567+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=5567+62+54+54))&&o9!=nullptr))//50
                            {
                                hit50.setPosition(X9,Y9);
                                o9=nullptr;
                                delete o9;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o10!=nullptr&&(((mouse_world.x>=(o10->x)-24)&&(mouse_world.x<=(o10->x)+24))&&((mouse_world.y>=(o10->y)-24)&&(mouse_world.y<=(o10->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=6412-62)&&(clock1.getElapsedTime().asMilliseconds()<=6412+62))&&o10!=nullptr)//300
                            {
                                hit300.setPosition(X10,Y10);
                                o10=nullptr;
                                delete o10;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=6412-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=6412-62))&&o10!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=6412+62)&&(clock1.getElapsedTime().asMilliseconds()<=6412+62+54))&&o10!=nullptr))//100
                            {
                                hit100.setPosition(X10,Y10);
                                o10=nullptr;
                                delete o10;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=6412-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=6412-62-54))&&o10!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=6412+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=6412+62+54+54))&&o10!=nullptr))//50
                            {
                                hit50.setPosition(X10,Y10);
                                o10=nullptr;
                                delete o10;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o11!=nullptr&&(((mouse_world.x>=(o11->x)-24)&&(mouse_world.x<=(o11->x)+24))&&((mouse_world.y>=(o11->y)-24)&&(mouse_world.y<=(o11->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=7680-62)&&(clock1.getElapsedTime().asMilliseconds()<=7680+62))&&o11!=nullptr)//300
                            {
                                hit300.setPosition(X11,Y11);
                                o11=nullptr;
                                delete o11;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=7680-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=7680-62))&&o11!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=7680+62)&&(clock1.getElapsedTime().asMilliseconds()<=7680+62+54))&&o11!=nullptr))//100
                            {
                                hit100.setPosition(X11,Y11);
                                o11=nullptr;
                                delete o11;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=7680-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=7680-62-54))&&o11!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=7680+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=7680+62+54+54))&&o11!=nullptr))//50
                            {
                                hit50.setPosition(X11,Y11);
                                o11=nullptr;
                                delete o11;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o12!=nullptr&&(((mouse_world.x>=(o12->x)-24)&&(mouse_world.x<=(o12->x)+24))&&((mouse_world.y>=(o12->y)-24)&&(mouse_world.y<=(o12->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=8102-62)&&(clock1.getElapsedTime().asMilliseconds()<=8102+62))&&o12!=nullptr)//300
                            {
                                hit300.setPosition(X12,Y12);
                                o12=nullptr;
                                delete o12;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8102-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=8102-62))&&o12!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8102+62)&&(clock1.getElapsedTime().asMilliseconds()<=8102+62+54))&&o12!=nullptr))//100
                            {
                                hit100.setPosition(X12,Y12);
                                o12=nullptr;
                                delete o12;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8102-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=8102-62-54))&&o12!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8102+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=8102+62+54+54))&&o12!=nullptr))//50
                            {
                                hit50.setPosition(X12,Y12);
                                o12=nullptr;
                                delete o12;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o13!=nullptr&&(((mouse_world.x>=(o13->x)-24)&&(mouse_world.x<=(o13->x)+24))&&((mouse_world.y>=(o13->y)-24)&&(mouse_world.y<=(o13->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=8947-62)&&(clock1.getElapsedTime().asMilliseconds()<=8947+62))&&o13!=nullptr)//300
                            {
                                hit300.setPosition(X13,Y13);
                                o13=nullptr;
                                delete o13;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8947-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=8947-62))&&o13!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8947+62)&&(clock1.getElapsedTime().asMilliseconds()<=8947+62+54))&&o13!=nullptr))//100
                            {
                                hit100.setPosition(X13,Y13);
                                o13=nullptr;
                                delete o13;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=8947-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=8947-62-54))&&o13!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=8947+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=8947+62+54+54))&&o13!=nullptr))//50
                            {
                                hit50.setPosition(X13,Y13);
                                o13=nullptr;
                                delete o13;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o14!=nullptr&&(((mouse_world.x>=(o14->x)-24)&&(mouse_world.x<=(o14->x)+24))&&((mouse_world.y>=(o14->y)-24)&&(mouse_world.y<=(o14->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=9792-62)&&(clock1.getElapsedTime().asMilliseconds()<=9792+62))&&o14!=nullptr)//300
                            {
                                hit300.setPosition(X14,Y14);
                                o14=nullptr;
                                delete o14;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=9792-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=9792-62))&&o14!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=9792+62)&&(clock1.getElapsedTime().asMilliseconds()<=9792+62+54))&&o14!=nullptr))//100
                            {
                                hit100.setPosition(X14,Y14);
                                o14=nullptr;
                                delete o14;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=9792-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=9792-62-54))&&o14!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=9792+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=9792+62+54+54))&&o14!=nullptr))//50
                            {
                                hit50.setPosition(X14,Y14);
                                o14=nullptr;
                                delete o14;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o15!=nullptr&&(((mouse_world.x>=(o15->x)-24)&&(mouse_world.x<=(o15->x)+24))&&((mouse_world.y>=(o15->y)-24)&&(mouse_world.y<=(o15->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=10637-62)&&(clock1.getElapsedTime().asMilliseconds()<=10637+62))&&o15!=nullptr)//300
                            {
                                hit300.setPosition(X15,Y15);
                                o15=nullptr;
                                delete o15;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=10637-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=10637-62))&&o15!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=10637+62)&&(clock1.getElapsedTime().asMilliseconds()<=10637+62+54))&&o15!=nullptr))//100
                            {
                                hit100.setPosition(X15,Y15);
                                o15=nullptr;
                                delete o15;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=10637-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=10637-62-54))&&o15!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=10637+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=10637+62+54+54))&&o15!=nullptr))//50
                            {
                                hit50.setPosition(X15,Y15);
                                o15=nullptr;
                                delete o15;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o16!=nullptr&&(((mouse_world.x>=(o16->x)-24)&&(mouse_world.x<=(o16->x)+24))&&((mouse_world.y>=(o16->y)-24)&&(mouse_world.y<=(o16->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=11482-62)&&(clock1.getElapsedTime().asMilliseconds()<=11482+62))&&o16!=nullptr)//300
                            {
                                hit300.setPosition(X16,Y16);
                                o16=nullptr;
                                delete o16;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=11482-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=11482-62))&&o16!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=11482+62)&&(clock1.getElapsedTime().asMilliseconds()<=11482+62+54))&&o16!=nullptr))//100
                            {
                                hit100.setPosition(X16,Y16);
                                o16=nullptr;
                                delete o16;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=11482-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=11482-62-54))&&o16!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=11482+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=11482+62+54+54))&&o16!=nullptr))//50
                            {
                                hit50.setPosition(X16,Y16);
                                o16=nullptr;
                                delete o16;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o17!=nullptr&&(((mouse_world.x>=(o17->x)-24)&&(mouse_world.x<=(o17->x)+24))&&((mouse_world.y>=(o17->y)-24)&&(mouse_world.y<=(o17->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=12328-62)&&(clock1.getElapsedTime().asMilliseconds()<=12328+62))&&o17!=nullptr)//300
                            {
                                hit300.setPosition(X17,Y17);
                                o17=nullptr;
                                delete o17;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=12328-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=12328-62))&&o17!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=12328+62)&&(clock1.getElapsedTime().asMilliseconds()<=12328+62+54))&&o17!=nullptr))//100
                            {
                                hit100.setPosition(X17,Y17);
                                o17=nullptr;
                                delete o17;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=12328-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=12328-62-54))&&o17!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=12328+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=12328+62+54+54))&&o17!=nullptr))//50
                            {
                                hit50.setPosition(X17,Y17);
                                o17=nullptr;
                                delete o17;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o18!=nullptr&&(((mouse_world.x>=(o18->x)-24)&&(mouse_world.x<=(o18->x)+24))&&((mouse_world.y>=(o18->y)-24)&&(mouse_world.y<=(o18->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=13173-62)&&(clock1.getElapsedTime().asMilliseconds()<=13173+62))&&o18!=nullptr)//300
                            {
                                hit300.setPosition(X18,Y18);
                                o18=nullptr;
                                delete o18;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=13173-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=13173-62))&&o18!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=13173+62)&&(clock1.getElapsedTime().asMilliseconds()<=13173+62+54))&&o18!=nullptr))//100
                            {
                                hit100.setPosition(X18,Y18);
                                o18=nullptr;
                                delete o18;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=13173-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=13173-62-54))&&o18!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=13173+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=13173+62+54+54))&&o18!=nullptr))//50
                            {
                                hit50.setPosition(X18,Y18);
                                o18=nullptr;
                                delete o18;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o19!=nullptr&&(((mouse_world.x>=(o19->x)-24)&&(mouse_world.x<=(o19->x)+24))&&((mouse_world.y>=(o19->y)-24)&&(mouse_world.y<=(o19->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=14440-62)&&(clock1.getElapsedTime().asMilliseconds()<=14440+62))&&o19!=nullptr)//300
                            {
                                hit300.setPosition(X19,Y19);
                                o19=nullptr;
                                delete o19;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14440-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=14440-62))&&o19!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14440+62)&&(clock1.getElapsedTime().asMilliseconds()<=14440+62+54))&&o19!=nullptr))//100
                            {
                                hit100.setPosition(X19,Y19);
                                o19=nullptr;
                                delete o19;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14440-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=14440-62-54))&&o19!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14440+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=14440+62+54+54))&&o19!=nullptr))//50
                            {
                                hit50.setPosition(X19,Y19);
                                o19=nullptr;
                                delete o19;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o20!=nullptr&&(((mouse_world.x>=(o20->x)-24)&&(mouse_world.x<=(o20->x)+24))&&((mouse_world.y>=(o20->y)-24)&&(mouse_world.y<=(o20->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=14863-62)&&(clock1.getElapsedTime().asMilliseconds()<=14863+62))&&o20!=nullptr)//300
                            {
                                hit300.setPosition(X20,Y20);
                                o20=nullptr;
                                delete o20;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14863-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=14863-62))&&o20!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14863+62)&&(clock1.getElapsedTime().asMilliseconds()<=14863+62+54))&&o20!=nullptr))//100
                            {
                                hit100.setPosition(X20,Y20);
                                o20=nullptr;
                                delete o20;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=14863-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=14863-62-54))&&o20!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=14863+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=14863+62+54+54))&&o20!=nullptr))//50
                            {
                                hit50.setPosition(X20,Y20);
                                o20=nullptr;
                                delete o20;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o21!=nullptr&&(((mouse_world.x>=(o21->x)-24)&&(mouse_world.x<=(o21->x)+24))&&((mouse_world.y>=(o21->y)-24)&&(mouse_world.y<=(o21->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=15708-62)&&(clock1.getElapsedTime().asMilliseconds()<=15708+62))&&o21!=nullptr)//300
                            {
                                hit300.setPosition(X21,Y21);
                                o21=nullptr;
                                delete o21;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=15708-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=15708-62))&&o21!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=15708+62)&&(clock1.getElapsedTime().asMilliseconds()<=15708+62+54))&&o21!=nullptr))//100
                            {
                                hit100.setPosition(X21,Y21);
                                o21=nullptr;
                                delete o21;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=15708-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=15708-62-54))&&o21!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=15708+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=15708+62+54+54))&&o21!=nullptr))//50
                            {
                                hit50.setPosition(X21,Y21);
                                o21=nullptr;
                                delete o21;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o22!=nullptr&&(((mouse_world.x>=(o22->x)-24)&&(mouse_world.x<=(o22->x)+24))&&((mouse_world.y>=(o22->y)-24)&&(mouse_world.y<=(o22->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=16553-62)&&(clock1.getElapsedTime().asMilliseconds()<=16553+62))&&o22!=nullptr)//300
                            {
                                hit300.setPosition(X22,Y22);
                                o22=nullptr;
                                delete o22;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=16553-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=16553-62))&&o22!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=16553+62)&&(clock1.getElapsedTime().asMilliseconds()<=16553+62+54))&&o22!=nullptr))//100
                            {
                                hit100.setPosition(X22,Y22);
                                o22=nullptr;
                                delete o22;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=16553-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=16553-62-54))&&o22!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=16553+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=16553+62+54+54))&&o22!=nullptr))//50
                            {
                                hit50.setPosition(X22,Y22);
                                o22=nullptr;
                                delete o22;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o23!=nullptr&&(((mouse_world.x>=(o23->x)-24)&&(mouse_world.x<=(o23->x)+24))&&((mouse_world.y>=(o23->y)-24)&&(mouse_world.y<=(o23->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=17821-62)&&(clock1.getElapsedTime().asMilliseconds()<=17821+62))&&o23!=nullptr)//300
                            {
                                hit300.setPosition(X23,Y23);
                                o23=nullptr;
                                delete o23;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=17821-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=17821-62))&&o23!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=17821+62)&&(clock1.getElapsedTime().asMilliseconds()<=17821+62+54))&&o23!=nullptr))//100
                            {
                                hit100.setPosition(X23,Y23);
                                o23=nullptr;
                                delete o23;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=17821-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=17821-62-54))&&o23!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=17821+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=17821+62+54+54))&&o23!=nullptr))//50
                            {
                                hit50.setPosition(X23,Y23);
                                o23=nullptr;
                                delete o23;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o24!=nullptr&&(((mouse_world.x>=(o24->x)-24)&&(mouse_world.x<=(o24->x)+24))&&((mouse_world.y>=(o24->y)-24)&&(mouse_world.y<=(o24->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=18243-62)&&(clock1.getElapsedTime().asMilliseconds()<=18243+62))&&o24!=nullptr)//300
                            {
                                hit300.setPosition(X24,Y24);
                                o24=nullptr;
                                delete o24;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=18243-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=18243-62))&&o24!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=18243+62)&&(clock1.getElapsedTime().asMilliseconds()<=18243+62+54))&&o24!=nullptr))//100
                            {
                                hit100.setPosition(X24,Y24);
                                o24=nullptr;
                                delete o24;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=18243-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=18243-62-54))&&o24!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=18243+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=18243+62+54+54))&&o24!=nullptr))//50
                            {
                                hit50.setPosition(X24,Y24);
                                o24=nullptr;
                                delete o24;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o25!=nullptr&&(((mouse_world.x>=(o25->x)-24)&&(mouse_world.x<=(o25->x)+24))&&((mouse_world.y>=(o25->y)-24)&&(mouse_world.y<=(o25->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=19088-62)&&(clock1.getElapsedTime().asMilliseconds()<=19088+62))&&o25!=nullptr)//300
                            {
                                hit300.setPosition(X25,Y25);
                                o25=nullptr;
                                delete o25;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19088-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=19088-62))&&o25!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19088+62)&&(clock1.getElapsedTime().asMilliseconds()<=19088+62+54))&&o25!=nullptr))//100
                            {
                                hit100.setPosition(X25,Y25);
                                o25=nullptr;
                                delete o25;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19088-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=19088-62-54))&&o25!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19088+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=19088+62+54+54))&&o25!=nullptr))//50
                            {
                                hit50.setPosition(X25,Y25);
                                o25=nullptr;
                                delete o25;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o26!=nullptr&&(((mouse_world.x>=(o26->x)-24)&&(mouse_world.x<=(o26->x)+24))&&((mouse_world.y>=(o26->y)-24)&&(mouse_world.y<=(o26->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=19933-62)&&(clock1.getElapsedTime().asMilliseconds()<=19933+62))&&o26!=nullptr)//300
                            {
                                hit300.setPosition(X26,Y26);
                                o26=nullptr;
                                delete o26;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19933-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=19933-62))&&o26!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19933+62)&&(clock1.getElapsedTime().asMilliseconds()<=19933+62+54))&&o26!=nullptr))//100
                            {
                                hit100.setPosition(X26,Y26);
                                o26=nullptr;
                                delete o26;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=19933-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=19933-62-54))&&o26!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=19933+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=19933+62+54+54))&&o26!=nullptr))//50
                            {
                                hit50.setPosition(X26,Y26);
                                o26=nullptr;
                                delete o26;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o27!=nullptr&&(((mouse_world.x>=(o27->x)-24)&&(mouse_world.x<=(o27->x)+24))&&((mouse_world.y>=(o27->y)-24)&&(mouse_world.y<=(o27->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=21201-62)&&(clock1.getElapsedTime().asMilliseconds()<=21201+62))&&o27!=nullptr)//300
                            {
                                hit300.setPosition(X27,Y27);
                                o27=nullptr;
                                delete o27;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21201-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=21201-62))&&o27!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21201+62)&&(clock1.getElapsedTime().asMilliseconds()<=21201+62+54))&&o27!=nullptr))//100
                            {
                                hit100.setPosition(X27,Y27);
                                o27=nullptr;
                                delete o27;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21201-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=21201-62-54))&&o27!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21201+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=21201+62+54+54))&&o27!=nullptr))//50
                            {
                                hit50.setPosition(X27,Y27);
                                o27=nullptr;
                                delete o27;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o28!=nullptr&&(((mouse_world.x>=(o28->x)-24)&&(mouse_world.x<=(o28->x)+24))&&((mouse_world.y>=(o28->y)-24)&&(mouse_world.y<=(o28->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=21623-62)&&(clock1.getElapsedTime().asMilliseconds()<=21623+62))&&o28!=nullptr)//300
                            {
                                hit300.setPosition(X28,Y28);
                                o28=nullptr;
                                delete o28;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21623-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=21623-62))&&o28!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21623+62)&&(clock1.getElapsedTime().asMilliseconds()<=21623+62+54))&&o28!=nullptr))//100
                            {
                                hit100.setPosition(X28,Y28);
                                o28=nullptr;
                                delete o28;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=21623-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=21623-62-54))&&o28!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=21623+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=21623+62+54+54))&&o28!=nullptr))//50
                            {
                                hit50.setPosition(X28,Y28);
                                o28=nullptr;
                                delete o28;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o29!=nullptr&&(((mouse_world.x>=(o29->x)-24)&&(mouse_world.x<=(o29->x)+24))&&((mouse_world.y>=(o29->y)-24)&&(mouse_world.y<=(o29->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=22468-62)&&(clock1.getElapsedTime().asMilliseconds()<=22468+62))&&o29!=nullptr)//300
                            {
                                hit300.setPosition(X29,Y29);
                                o29=nullptr;
                                delete o29;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=22468-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=22468-62))&&o29!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=22468+62)&&(clock1.getElapsedTime().asMilliseconds()<=22468+62+54))&&o29!=nullptr))//100
                            {
                                hit100.setPosition(X29,Y29);
                                o29=nullptr;
                                delete o29;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=22468-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=22468-62-54))&&o29!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=22468+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=22468+62+54+54))&&o29!=nullptr))//50
                            {
                                hit50.setPosition(X29,Y29);
                                o29=nullptr;
                                delete o29;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o30!=nullptr&&(((mouse_world.x>=(o30->x)-24)&&(mouse_world.x<=(o30->x)+24))&&((mouse_world.y>=(o30->y)-24)&&(mouse_world.y<=(o30->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=23102-62)&&(clock1.getElapsedTime().asMilliseconds()<=23102+62))&&o30!=nullptr)//300
                            {
                                hit300.setPosition(X30,Y30);
                                o30=nullptr;
                                delete o30;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=23102-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=23102-62))&&o30!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=23102+62)&&(clock1.getElapsedTime().asMilliseconds()<=23102+62+54))&&o30!=nullptr))//100
                            {
                                hit100.setPosition(X30,Y30);
                                o30=nullptr;
                                delete o30;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=23102-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=23102-62-54))&&o30!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=23102+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=23102+62+54+54))&&o30!=nullptr))//50
                            {
                                hit50.setPosition(X30,Y30);
                                o30=nullptr;
                                delete o30;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o31!=nullptr&&(((mouse_world.x>=(o31->x)-24)&&(mouse_world.x<=(o31->x)+24))&&((mouse_world.y>=(o31->y)-24)&&(mouse_world.y<=(o31->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=24159-62)&&(clock1.getElapsedTime().asMilliseconds()<=24159+62))&&o31!=nullptr)//300
                            {
                                hit300.setPosition(X31,Y31);
                                o31=nullptr;
                                delete o31;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24159-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=24159-62))&&o31!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24159+62)&&(clock1.getElapsedTime().asMilliseconds()<=24159+62+54))&&o31!=nullptr))//100
                            {
                                hit100.setPosition(X31,Y31);
                                o31=nullptr;
                                delete o31;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24159-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=24159-62-54))&&o31!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24159+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=24159+62+54+54))&&o31!=nullptr))//50
                            {
                                hit50.setPosition(X31,Y31);
                                o31=nullptr;
                                delete o31;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o32!=nullptr&&(((mouse_world.x>=(o32->x)-24)&&(mouse_world.x<=(o32->x)+24))&&((mouse_world.y>=(o32->y)-24)&&(mouse_world.y<=(o32->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=24792-62)&&(clock1.getElapsedTime().asMilliseconds()<=24792+62))&&o32!=nullptr)//300
                            {
                                hit300.setPosition(X32,Y32);
                                o32=nullptr;
                                delete o32;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24792-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=24792-62))&&o32!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24792+62)&&(clock1.getElapsedTime().asMilliseconds()<=24792+62+54))&&o32!=nullptr))//100
                            {
                                hit100.setPosition(X32,Y32);
                                o32=nullptr;
                                delete o32;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=24792-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=24792-62-54))&&o32!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=24792+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=24792+62+54+54))&&o32!=nullptr))//50
                            {
                                hit50.setPosition(X32,Y32);
                                o32=nullptr;
                                delete o32;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o33!=nullptr&&(((mouse_world.x>=(o33->x)-24)&&(mouse_world.x<=(o33->x)+24))&&((mouse_world.y>=(o33->y)-24)&&(mouse_world.y<=(o33->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=25849-62)&&(clock1.getElapsedTime().asMilliseconds()<=25849+62))&&o33!=nullptr)//300
                            {
                                hit300.setPosition(X33,Y33);
                                o33=nullptr;
                                delete o33;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=25849-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=25849-62))&&o33!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=25849+62)&&(clock1.getElapsedTime().asMilliseconds()<=25849+62+54))&&o33!=nullptr))//100
                            {
                                hit100.setPosition(X33,Y33);
                                o33=nullptr;
                                delete o33;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=25849-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=25849-62-54))&&o33!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=25849+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=25849+62+54+54))&&o33!=nullptr))//50
                            {
                                hit50.setPosition(X33,Y33);
                                o33=nullptr;
                                delete o33;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o34!=nullptr&&(((mouse_world.x>=(o34->x)-24)&&(mouse_world.x<=(o34->x)+24))&&((mouse_world.y>=(o34->y)-24)&&(mouse_world.y<=(o34->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=26482-62)&&(clock1.getElapsedTime().asMilliseconds()<=26482+62))&&o34!=nullptr)//300
                            {
                                hit300.setPosition(X34,Y34);
                                o34=nullptr;
                                delete o34;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=26482-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=26482-62))&&o34!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=26482+62)&&(clock1.getElapsedTime().asMilliseconds()<=26482+62+54))&&o34!=nullptr))//100
                            {
                                hit100.setPosition(X34,Y34);
                                o34=nullptr;
                                delete o34;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=26482-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=26482-62-54))&&o34!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=26482+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=26482+62+54+54))&&o34!=nullptr))//50
                            {
                                hit50.setPosition(X34,Y34);
                                o34=nullptr;
                                delete o34;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o35!=nullptr&&(((mouse_world.x>=(o35->x)-24)&&(mouse_world.x<=(o35->x)+24))&&((mouse_world.y>=(o35->y)-24)&&(mouse_world.y<=(o35->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=27539-62)&&(clock1.getElapsedTime().asMilliseconds()<=27539+62))&&o35!=nullptr)//300
                            {
                                hit300.setPosition(X35,Y35);
                                o35=nullptr;
                                delete o35;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=27539-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=27539-62))&&o35!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=27539+62)&&(clock1.getElapsedTime().asMilliseconds()<=27539+62+54))&&o35!=nullptr))//100
                            {
                                hit100.setPosition(X35,Y35);
                                o35=nullptr;
                                delete o35;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=27539-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=27539-62-54))&&o35!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=27539+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=27539+62+54+54))&&o35!=nullptr))//50
                            {
                                hit50.setPosition(X35,Y35);
                                o35=nullptr;
                                delete o35;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o36!=nullptr&&(((mouse_world.x>=(o36->x)-24)&&(mouse_world.x<=(o36->x)+24))&&((mouse_world.y>=(o36->y)-24)&&(mouse_world.y<=(o36->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=28384-62)&&(clock1.getElapsedTime().asMilliseconds()<=28384+62))&&o36!=nullptr)//300
                            {
                                hit300.setPosition(X36,Y36);
                                o36=nullptr;
                                delete o36;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28384-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=28384-62))&&o36!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28384+62)&&(clock1.getElapsedTime().asMilliseconds()<=28384+62+54))&&o36!=nullptr))//100
                            {
                                hit100.setPosition(X36,Y36);
                                o36=nullptr;
                                delete o36;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28384-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=28384-62-54))&&o36!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28384+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=28384+62+54+54))&&o36!=nullptr))//50
                            {
                                hit50.setPosition(X36,Y36);
                                o36=nullptr;
                                delete o36;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                            if(o37!=nullptr&&(((mouse_world.x>=(o37->x)-24)&&(mouse_world.x<=(o37->x)+24))&&((mouse_world.y>=(o37->y)-24)&&(mouse_world.y<=(o37->y)+24))))
                            {
                            if(((clock1.getElapsedTime().asMilliseconds()>=28490-62)&&(clock1.getElapsedTime().asMilliseconds()<=28490+62))&&o37!=nullptr)//300
                            {
                                hit300.setPosition(X37,Y37);
                                o37=nullptr;
                                delete o37;
                                sc=sc+(300*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit300);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28490-62-54)&&(clock1.getElapsedTime().asMilliseconds()<=28490-62))&&o37!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28490+62)&&(clock1.getElapsedTime().asMilliseconds()<=28490+62+54))&&o37!=nullptr))//100
                            {
                                hit100.setPosition(X37,Y37);
                                o37=nullptr;
                                delete o37;
                                sc=sc+(100*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit100);
                                app.display();
                            }
                            else if((((clock1.getElapsedTime().asMilliseconds()>=28490-62-54-54)&&(clock1.getElapsedTime().asMilliseconds()<=28490-62-54))&&o37!=nullptr)
                            ||(((clock1.getElapsedTime().asMilliseconds()>=28490+62+54)&&(clock1.getElapsedTime().asMilliseconds()<=28490+62+54+54))&&o37!=nullptr))//50
                            {
                                hit50.setPosition(X37,Y37);
                                o37=nullptr;
                                delete o37;
                                sc=sc+(50*cb);
                                hplife(HP);
                                cb++;
                                app.draw(hit50);
                                app.display();
                            }
                            }
                        }
        }


        app.draw(background);
       // t2.loadFromFile("images/battle.jpg");
   //////draw//////

  // app.draw(background);
    LifeBar lifeBarPlayer;
   if(((clock1.getElapsedTime().asMilliseconds()>=285)&&(clock1.getElapsedTime().asMilliseconds()<=285))&&o2!=nullptr)
    {

        o2->t=clock1.getElapsedTime().asMilliseconds();
        o2->draw(app);
        X2+=0.293;Y2+=0.293;r2-=0.293;
        o2->update(app,r2,X2,Y2);

    }
    else if(((clock1.getElapsedTime().asMilliseconds()>285))&&o2!=nullptr) {delete o2; o2=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=1342-1440)&&(clock1.getElapsedTime().asMilliseconds()<=1342))&&o3!=nullptr)
    {
        o3->t=clock1.getElapsedTime().asMilliseconds();
        o3->draw(app);
        X3+=0.293;Y3+=0.293;r3-=0.293;
        o3->update(app,r3,X3,Y3);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>1342))&&o3!=nullptr) {delete o3; o3=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=1764-1440)&&(clock1.getElapsedTime().asMilliseconds()<=1764))&&o4!=nullptr)
    {
        o4->t=clock1.getElapsedTime().asMilliseconds();
        o4->draw(app);
        X4+=0.293;Y4+=0.293;r4-=0.293;
        o4->update(app,r4,X4,Y4);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>1764))&&o4!=nullptr) {delete o4; o4=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=2609-1440)&&(clock1.getElapsedTime().asMilliseconds()<=2609))&&o5!=nullptr)
    {
        o5->t=clock1.getElapsedTime().asMilliseconds();
        o5->draw(app);
        X5+=0.293;Y5+=0.293;r5-=0.293;
        o5->update(app,r5,X5,Y5);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>2609))&&o5!=nullptr) {delete o5; o5=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=3032-1440)&&(clock1.getElapsedTime().asMilliseconds()<=3032))&&o6!=nullptr)
    {
        o6->t=clock1.getElapsedTime().asMilliseconds();
        o6->draw(app);
        X6+=0.293;Y6+=0.293;r6-=0.293;
        o6->update(app,r6,X6,Y6);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>3032))&&o6!=nullptr) {delete o6; o6=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=3877-1440)&&(clock1.getElapsedTime().asMilliseconds()<=3877))&&o7!=nullptr)
    {
        o7->t=clock1.getElapsedTime().asMilliseconds();
        o7->draw(app);
        X7+=0.293;Y7+=0.293;r7-=0.293;
        o7->update(app,r7,X7,Y7);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>3877))&&o7!=nullptr) {delete o7; o7=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=4722-1440)&&(clock1.getElapsedTime().asMilliseconds()<=4722))&&o8!=nullptr)
    {
        o8->t=clock1.getElapsedTime().asMilliseconds();
        o8->draw(app);
        X8+=0.293;Y8+=0.293;r8-=0.293;
        o8->update(app,r8,X8,Y8);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>4722))&&o8!=nullptr) {delete o8; o8=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=5567-1440)&&(clock1.getElapsedTime().asMilliseconds()<=5567))&&o9!=nullptr)
    {
        o9->t=clock1.getElapsedTime().asMilliseconds();
        o9->draw(app);
        X9+=0.293;Y9+=0.293;r9-=0.293;
        o9->update(app,r9,X9,Y9);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>5567))&&o9!=nullptr) {delete o9; o9=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=6412-1440)&&(clock1.getElapsedTime().asMilliseconds()<=6412))&&o10!=nullptr)
    {
        o10->t=clock1.getElapsedTime().asMilliseconds();
        o10->draw(app);
        X10+=0.293;Y10+=0.293;r10-=0.293;
        o10->update(app,r10,X10,Y10);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>6412))&&o10!=nullptr) {delete o10; o10=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=7680-1440)&&(clock1.getElapsedTime().asMilliseconds()<=7680))&&o11!=nullptr)
    {
        o11->t=clock1.getElapsedTime().asMilliseconds();
        o11->draw(app);
        X11+=0.293;Y11+=0.293;r11-=0.293;
        o11->update(app,r11,X11,Y11);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>7680))&&o11!=nullptr) {delete o11; o11=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=8102-1440)&&(clock1.getElapsedTime().asMilliseconds()<=8102))&&o12!=nullptr)
    {
        o12->t=clock1.getElapsedTime().asMilliseconds();
        o12->draw(app);
        X12+=0.293;Y12+=0.293;r12-=0.293;
        o12->update(app,r12,X12,Y12);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>8102))&&o12!=nullptr) {delete o12; o12=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=8947-1440)&&(clock1.getElapsedTime().asMilliseconds()<=8947))&&o13!=nullptr)
    {
        o13->t=clock1.getElapsedTime().asMilliseconds();
        o13->draw(app);
        X13+=0.293;Y13+=0.293;r13-=0.293;
        o13->update(app,r13,X13,Y13);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>8947))&&o13!=nullptr) {delete o13; o13=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=9792-1440)&&(clock1.getElapsedTime().asMilliseconds()<=9792))&&o14!=nullptr)
    {
        o14->t=clock1.getElapsedTime().asMilliseconds();
        o14->draw(app);
        X14+=0.293;Y14+=0.293;r14-=0.293;
        o14->update(app,r14,X14,Y14);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>9792))&&o14!=nullptr) {delete o14; o14=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=10637-1440)&&(clock1.getElapsedTime().asMilliseconds()<=10637))&&o15!=nullptr)
    {
        o15->t=clock1.getElapsedTime().asMilliseconds();
        o15->draw(app);
        X15+=0.293;Y15+=0.293;r15-=0.293;
        o15->update(app,r15,X15,Y15);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>10637))&&o15!=nullptr) {delete o15; o15=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=11482-1440)&&(clock1.getElapsedTime().asMilliseconds()<=11482))&&o16!=nullptr)
    {
        o16->t=clock1.getElapsedTime().asMilliseconds();
        o16->draw(app);
        X16+=0.293;Y16+=0.293;r16-=0.293;
        o16->update(app,r16,X16,Y16);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>11482))&&o4!=nullptr) {delete o16; o16=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=12328-1440)&&(clock1.getElapsedTime().asMilliseconds()<=12328))&&o17!=nullptr)
    {
        o17->t=clock1.getElapsedTime().asMilliseconds();
        o17->draw(app);
        X17+=0.293;Y17+=0.293;r17-=0.293;
        o17->update(app,r17,X17,Y17);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>12328))&&o17!=nullptr) {delete o17; o17=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=13173-1440)&&(clock1.getElapsedTime().asMilliseconds()<=13173))&&o18!=nullptr)
    {
        o18->t=clock1.getElapsedTime().asMilliseconds();
        o18->draw(app);
        X18+=0.293;Y18+=0.293;r18-=0.293;
        o18->update(app,r18,X18,Y18);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>13173))&&o18!=nullptr) {delete o18; o18=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=14440-1440)&&(clock1.getElapsedTime().asMilliseconds()<=14440))&&o19!=nullptr)
    {
        o19->t=clock1.getElapsedTime().asMilliseconds();
        o19->draw(app);
        X19+=0.293;Y19+=0.293;r19-=0.293;
        o19->update(app,r19,X19,Y19);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>14440))&&o19!=nullptr) {delete o19; o19=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=14863-1440)&&(clock1.getElapsedTime().asMilliseconds()<=14863))&&o20!=nullptr)
    {
        o20->t=clock1.getElapsedTime().asMilliseconds();
        o20->draw(app);
        X20+=0.293;Y20+=0.293;r20-=0.293;
        o20->update(app,r20,X20,Y20);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>14863))&&o20!=nullptr) {delete o20; o20=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=15708-1440)&&(clock1.getElapsedTime().asMilliseconds()<=15708))&&o21!=nullptr)
    {
        o21->t=clock1.getElapsedTime().asMilliseconds();
        o21->draw(app);
        X21+=0.293;Y21+=0.293;r21-=0.293;
        o21->update(app,r21,X21,Y21);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>15708))&&o21!=nullptr) {delete o21; o21=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=16553-1440)&&(clock1.getElapsedTime().asMilliseconds()<=16553))&&o22!=nullptr)
    {
        o22->t=clock1.getElapsedTime().asMilliseconds();
        o22->draw(app);
        X22+=0.293;Y22+=0.293;r22-=0.293;
        o22->update(app,r22,X22,Y22);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>16553))&&o22!=nullptr) {delete o22; o22=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=17821-1440)&&(clock1.getElapsedTime().asMilliseconds()<=17821))&&o23!=nullptr)
    {
        o23->t=clock1.getElapsedTime().asMilliseconds();
        o23->draw(app);
        X23+=0.293;Y23+=0.293;r23-=0.293;
        o23->update(app,r23,X23,Y23);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>17821))&&o23!=nullptr) {delete o23; o23=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=18243-1440)&&(clock1.getElapsedTime().asMilliseconds()<=18243))&&o24!=nullptr)
    {
        o24->t=clock1.getElapsedTime().asMilliseconds();
        o24->draw(app);
        X24+=0.293;Y24+=0.293;r24-=0.293;
        o24->update(app,r24,X24,Y24);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>18243))&&o24!=nullptr) {delete o24; o24=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=19088-1440)&&(clock1.getElapsedTime().asMilliseconds()<=19088))&&o25!=nullptr)
    {
        o25->t=clock1.getElapsedTime().asMilliseconds();
        o25->draw(app);
        X25+=0.293;Y25+=0.293;r25-=0.293;
        o25->update(app,r25,X25,Y25);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>19088))&&o25!=nullptr) {delete o25; o25=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=19933-1440)&&(clock1.getElapsedTime().asMilliseconds()<=19933))&&o26!=nullptr)
    {
        o26->t=clock1.getElapsedTime().asMilliseconds();
        o26->draw(app);
        X26+=0.293;Y26+=0.293;r26-=0.293;
        o26->update(app,r26,X26,Y26);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>19933))&&o26!=nullptr) {delete o26; o26=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=21201-1440)&&(clock1.getElapsedTime().asMilliseconds()<=21201))&&o27!=nullptr)
    {
        o27->t=clock1.getElapsedTime().asMilliseconds();
        o27->draw(app);
        X27+=0.293;Y27+=0.293;r27-=0.293;
        o27->update(app,r27,X27,Y27);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>21201))&&o27!=nullptr) {delete o27; o27=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=21623-1440)&&(clock1.getElapsedTime().asMilliseconds()<=21623))&&o28!=nullptr)
    {
        o28->t=clock1.getElapsedTime().asMilliseconds();
        o28->draw(app);
        X28+=0.293;Y28+=0.293;r28-=0.293;
        o28->update(app,r28,X28,Y28);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>21623))&&o28!=nullptr) {delete o28; o28=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=22468-1440)&&(clock1.getElapsedTime().asMilliseconds()<=22468))&&o29!=nullptr)
    {
        o29->t=clock1.getElapsedTime().asMilliseconds();
        o29->draw(app);
        X29+=0.293;Y29+=0.293;r29-=0.293;
        o29->update(app,r29,X29,Y29);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>22468))&&o29!=nullptr) {delete o29; o29=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=23102-1440)&&(clock1.getElapsedTime().asMilliseconds()<=23102))&&o30!=nullptr)
    {
        o30->t=clock1.getElapsedTime().asMilliseconds();
        o30->draw(app);
        X30+=0.293;Y30+=0.293;r30-=0.293;
        o30->update(app,r30,X30,Y30);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>23102))&&o30!=nullptr) {delete o30; o30=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=24159-1440)&&(clock1.getElapsedTime().asMilliseconds()<=24159))&&o31!=nullptr)
    {
        o31->t=clock1.getElapsedTime().asMilliseconds();
        o31->draw(app);
        X31+=0.293;Y31+=0.293;r31-=0.293;
        o31->update(app,r31,X31,Y31);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>24159))&&o31!=nullptr) {delete o31; o31=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=24792-1440)&&(clock1.getElapsedTime().asMilliseconds()<=24792))&&o32!=nullptr)
    {
        o32->t=clock1.getElapsedTime().asMilliseconds();
        o32->draw(app);
        X32+=0.293;Y32+=0.293;r32-=0.293;
        o32->update(app,r32,X32,Y32);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>24792))&&o32!=nullptr) {delete o32; o32=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=25849-1440)&&(clock1.getElapsedTime().asMilliseconds()<=25849))&&o33!=nullptr)
    {
        o33->t=clock1.getElapsedTime().asMilliseconds();
        o33->draw(app);
        X33+=0.293;Y33+=0.293;r33-=0.293;
        o33->update(app,r33,X33,Y33);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>25849))&&o33!=nullptr) {delete o33; o33=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=26482-1440)&&(clock1.getElapsedTime().asMilliseconds()<=26482))&&o34!=nullptr)
    {
        o34->t=clock1.getElapsedTime().asMilliseconds();
        o34->draw(app);
        X34+=0.293;Y34+=0.293;r34-=0.293;
        o34->update(app,r34,X34,Y34);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>26482))&&o34!=nullptr) {delete o34; o34=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=27539-1440)&&(clock1.getElapsedTime().asMilliseconds()<=27539))&&o35!=nullptr) ///Проверь тайминиги
    {
        o35->t=clock1.getElapsedTime().asMilliseconds();
        o35->draw(app);
        X35+=0.293;Y35+=0.293;r35-=0.293;
        o35->update(app,r35,X35,Y35);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>27539))&&o35!=nullptr) {delete o35; o35=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=28384-1440)&&(clock1.getElapsedTime().asMilliseconds()<=28384))&&o36!=nullptr)
    {
        o36->t=clock1.getElapsedTime().asMilliseconds();
        o36->draw(app);
        X36+=0.293;Y36+=0.293;r36-=0.293;
        o36->update(app,r36,X36,Y36);
    }
    else if(((clock1.getElapsedTime().asMilliseconds()>28384))&&o36!=nullptr) {delete o36; o36=nullptr; hpdrainmiss(HP);}
    if(((clock1.getElapsedTime().asMilliseconds()>=28490-1440)&&(clock1.getElapsedTime().asMilliseconds()<=28490))&&o37!=nullptr)
    {
        o37->t=clock1.getElapsedTime().asMilliseconds();
        o37->draw(app);
        X37+=0.293;Y37+=0.293;r37-=0.293;
        o37->update(app,r37,X37,Y37);
    }
            std::ostringstream playerScoreString;
            Font font;
            font.loadFromFile("ALGER.TTF");
            Text text("", font, 20);
            text.setColor(Color::Red);
            text.setStyle(Text::Bold);
            text.setString("SCORE:");
            text.setPosition(1750,0);
            app.draw(text);
            Text text2("", font, 20);
            playerScoreString <<*score ;
            text2.setString(playerScoreString.str());
            text2.setPosition(1825,0);
            app.draw(text2);
            std::ostringstream combostr;
            Font font1;
            font.loadFromFile("font.ttf");
            Text text3("", font, 40);
            combostr <<*combo ;
            Color clr(100,200,255,100);
            text3.setColor(clr);
            text3.setStyle(Text::Bold);
            text3.setString(combostr.str());
            text3.setPosition(20,1030);
            app.draw(text3);
            hpdraintime(HP);
            lifeBarPlayer.update(*HP);
            lifeBarPlayer.draw(app);

            app.display();
    if(clock1.getElapsedTime().asMilliseconds()>32000)
    {
         while (!Keyboard::isKeyPressed(Keyboard::Escape))
        {
            app.clear();
            t2.loadFromFile("images/1.jpg");
             std::ostringstream playerScoreString;
             playerScoreString <<*score ;
             Text text2;
            text2.setString(playerScoreString.str());
            app.draw(background);
            app.pushGLStates();
            app.draw(text2);
            app.popGLStates();
            app.display();
        }
        return true;
    }

    }
    if(hp<0)
    {


    while (!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        app.clear();
        t2.loadFromFile("images/2.jpg");
        std::ostringstream playerScoreString;
        playerScoreString <<*score ;
        Text text2;
        text2.setString(playerScoreString.str());
        app.draw(background);
        app.pushGLStates();
        app.draw(text2);
        app.popGLStates();
        app.display();

    }
    return true;

    }
    }
}
