#include <windows.h>
#include <iostream>
#include <direct.h>
#include <stdlib.h>
#define ANCHO 59
#define ALTO 25
using namespace std;

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

