#include<bits/stdc++.h>
#include<graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<fstream>
#include <conio.h>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

#define mnTop 0
#define mxTop 639
#define mnBottom 0
#define mxBottom 479

int x = mxTop/2,  y = mxBottom;  //   car position (x, y) when game is starting
int score = 0;

void description()
{
    setfillstyle(SOLID_FILL, GREEN);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(6, 0, 36);
    outtextxy(515, 50, "Car Game");
    settextstyle(6, 0, 33);

    outtextxy(500, 200, "High Score : 101");
    string s = to_string(score);
    char sc[80];
    sprintf(sc, "Score : %d", score);
    outtextxy(500, 230, sc);

    outtextxy(500, 430, "Click Esc key to quit game");

}
void drawFrame()
{
    bar(mnTop, mnBottom, 50, mxBottom);
    bar(mxTop-250, mnBottom, mxTop, mxBottom);
    setbkcolor(6);
    description();

}

void drawenemy(int x, int y)
{

    setfillstyle(SOLID_FILL, RED);

    bar(x-20, y, x+20, y+20);
    bar(x-10, y+20, x+10, y+40);
    bar(x-20, y+40, x+20, y+60);
    bar(x-10, y+60, x+10, y+80);
}

void moveenemy(int x, int i)
{
    drawenemy(x, i);

}

void moveCar()
{
    setfillstyle(SOLID_FILL, YELLOW);


    bar(x-20, y-20, x+20, y);
    bar(x-10, y-40, x+10, y-20);
    bar(x-20, y-60, x+20, y-40);
    bar(x-10, y-80, x+10, y-60);
}

bool isCollision(int x1, int y1)
{
    if((x1-20)<= (x-20) && ((x1+20)>=(x-20)))
    {
        if(y1<=(y-80) && (y1+80)>=(y-80))
        {
            return true;
        }
    }
    if((x+20)>=(x1-20) && (x+20)<=x1+20)
    {
        if(y1<=(y-80) && (y1+80)>=(y-80))
        {
            return true;
        }
    }
    return false;
}

void gameOver()
{
  int a;
  ofstream("input.txt");
  input >> a;


    cleardevice();
    settextstyle(6, 0, 25);
    setbkcolor(12);
    char msg[101];
    sprintf(msg, "High Score : 1020");
    outtextxy(mxTop/2+5, mxBottom/2-25, msg);
    sprintf(msg, "Your Score is: %d", score);
    outtextxy(mxTop/2, mxBottom/2, msg);

}

int main()
{
    int driver = DETECT, mode;
    initgraph(&driver, &mode, "");

    int i = -100, j = 100;
    int k = -250, l = 200;
    int m = -400, n = 70;

    int pp = 1;
jump:
    while(pp%5<100)
    {
        pp++;
        setfillstyle(SOLID_FILL, GREEN);
        drawFrame();

        moveCar();
        delay(100);
        if(GetAsyncKeyState(VK_LEFT))
            x -= 15;
        else if(GetAsyncKeyState(VK_RIGHT))
            x += 15;
        else if(GetAsyncKeyState(VK_UP))
            y -= 15;
        else if(GetAsyncKeyState(VK_DOWN))
            y += 15;
        else if(GetAsyncKeyState(VK_ESCAPE))
            break;

        cleardevice();
        //setbkcolor(YELLOW);
        //description();


        if(x+20 > mxTop-250)
            x = mxTop-250 - 20;
        else if(x-20 < 50)
            x = 70;
        if(y>mxBottom)
            y = mxBottom;
        else if(y-80 < 0)
            y = 80;

        moveCar();
        moveenemy(j, i);
        moveenemy(l, k);
        moveenemy(n, m);
        if(isCollision(j, i) || isCollision(l, k) || isCollision(n, m))
        {
            break;
        }
        i+=20;
        k+=20;
        m+= 20;
        if(i>479)
        {
            score++;
            i = -100;
            j = 70 + rand()%299;
        }
        if(k>479)
        {
            score++;
            k = -250;
            l = 70 + rand()%299;

        }
        if(m>479)
        {
            score++;
            m = -400;
            n = 70 + rand()%299;
        }
        description();


    }
    gameOver();
    delay(100000);

    //cleardevice();
    //x = mxTop/2,  y = mxBottom;
    // goto jump;

    getch();
    //closegraph();

    return 0;
}

