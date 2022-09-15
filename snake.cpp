//created by neer,meet,neel
//edited by neel
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

bool gameOver;
const int width =20;
const int height=20;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100];
int ntail;


enum eDirection{ STOP = 0,LEFT,RIGHT,UP,DOWN };
eDirection dir;

void setup()
{
    gameOver=false;

    dir = STOP;
    x=width/2;
    y=height/2;
    fruitx= rand() %width;
    fruity = rand() %height;
    score=0;
    ntail=0;
}

void Draw()
{
    system("cls");

    for (int i = 0; i < width+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;


    for (int i = 0; i < height; i++)
    {
        /* code */
        for (int j = 0;  j < width; j++)
        {
            /* code */
            if(j==0)
                cout<<"#";
            if(i==y && j==x)
            {

                cout<<"0";
            }

            else if(i==fruity && j==fruitx)
                cout<<"F";
            else
            {
                 bool print=false;
                for(int k=0;k<ntail;k++)
                {

                    if(tailx[k]==j && taily[k]==i)
                    {
                        cout<<"0";
                        print=true;

                    }
                }

                if(!print)
                {
                    cout<<" ";
                }
            }




            if(j==width-1)
                cout<<"#";
        }


        cout<<endl;


    }


    for (int i = 0; i < width+2; i++)
    {
        /* code */
        cout<<"#";
    }

    cout<<endl;
    cout<<"               score="<<score<<endl;

}

void Logic()
{
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;

    for(int i=1;i<ntail;i++)
    {
            prev2x=tailx[i];
            prev2y=taily[i];
            tailx[i]=prevx;
            taily[i]=prevy;
            prevx=prev2x;
            prevy=prev2y;

    }

    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }

    if(x<0 || x>width || y<0 || y>height)
    {
        gameOver=true;
    }


    for(int i=0;i<ntail;i++)
    {
        if(tailx[i]==x && taily[i]==y)
            gameOver=true;
    }

    if(x==fruitx && y==fruity)
    {
        score+=10;
        ntail++;
        fruitx= rand() %width;
        fruity = rand() %height;
    }
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir=LEFT;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'w':
            dir=UP;
            break;

        case 'x':
            gameOver=true;
            break;
        }
    }
}



int main()
{

    setup();

    while(!gameOver)
    {

        Draw();
        Input();
        Logic();
        Sleep(90);

    }

    cout<<"PRESS X for exit";

    return 0;
}
