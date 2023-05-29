#include <windows.h>
#include <iostream>
#include <direct.h>
#include <stdlib.h>
#define ANCHO 59
#define ALTO 25
using namespace std;

void dibujo(char casilla)
{
    int x = 2;
    int y = 2;
    switch(casilla)
    {   
        case 'w':
            int cont = 0;
            while(cont < 5)
            switch (cont)
            {
                case 0:
                    gotoxy(x,y);
                    cout << ("  __      _") << endl;
                break;
                case 1:
                    gotoxy(x,y+1);
                    cout << ("o'')}____//") << endl;
                break;
                case 2:
                    gotoxy(x,y+2);
                    cout << (" `_/      )") << endl;
                break; 
                case 3:
                    gotoxy(x,y+3);
                    cout << (" (_(_/-(_/") << endl;
                break; 
            }           
        break;
        case 'a': 
            int cont = 0;
            while(cont < 5)
            switch (cont)
            {
                case 0:
                    gotoxy(x-10,y);
                    cout << ("  __      _") << endl;
                break;
                case 1:
                    gotoxy(x-10,y+1);
                    cout << ("o'')}____//") << endl;
                break;
                case 2:
                    gotoxy(x-10,y+2);
                    cout << (" `_/      )") << endl;
                break; 
                case 3:
                    gotoxy(x,y+3);
                    cout << (" (_(_/-(_/") << endl;
                break;  
            }         
        break;
        case 's':          
        break;
        case 'd':          
        break;
    }
}
void gotoxy(int x, int y)
{
HANDLE hCon;
hCon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X = x;
dwPos.Y = y;
SetConsoleCursorPosition(hCon, dwPos);
}
void recuadro() 
{
    for (int i = 8; i <= 75; i++) 
    {
    gotoxy(i, 0);
    cout << char(178);
    gotoxy(i, 29);
    cout << char(178);
    }

    for (int i = 0; i <= 29; i++) 
    {
    gotoxy(7, i);
    cout << char(178);
    gotoxy(76, i);
    cout << char(178);
    }
}
void dibujarmatriz ()
{
    for (int i = 8; i <= 75; i++)
    {
    gotoxy(i, 5.5);
    cout << char(178);
    gotoxy(i, 11.5);
    cout << char(178);
    gotoxy(i, 17.5);
    cout << char(178);
     gotoxy(i, 23.3);
    cout << char(178);
    }
    
    for (int i = 0; i <= 30; i++) 
    {
    gotoxy(21, i);
    cout << char(178);
    gotoxy(35, i);
    cout << char(178);
    gotoxy(49, i);
    cout << char(178);
    gotoxy(63, i);
    cout << char(178);
    }
   
}
int main ()
{
    
    system("Color B");
    dibujarmatriz();
    gotoxy(70,1);
    cout<<"META"<<endl;
    recuadro();
}

