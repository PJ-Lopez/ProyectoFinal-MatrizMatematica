#include <windows.h>
#include <iostream>
#include <direct.h>
#include <stdlib.h>
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

void dibujo(int x, int y)
{
    gotoxy(x, y);
    cout << "  __      _" << endl;
    gotoxy(x, y + 1);
    cout << "o'')}____//" << endl;
    gotoxy(x, y + 2);
    cout << " `_/      )" << endl;
    gotoxy(x, y + 3);
    cout << " (_(_/-(_/" << endl;
}

void recuadro() 
{
    for (int i = 29; i <= 89; i++) 
    {
        gotoxy(i, 0);
        cout << char(178);
        gotoxy(i, 25);
        cout << char(178);
    }

    for (int i = 0; i <= 25; i++) 
    {
        gotoxy(29, i);
        cout << char(178);
        gotoxy(89, i);
        cout << char(178);
    }
}
void dibujarmatriz ()
{
    for (int i = 29; i <= 89; i++)
    {
        gotoxy(i, 5);
        cout << char(178);
        gotoxy(i, 10);
        cout << char(178);
        gotoxy(i, 15);
        cout << char(178);
        gotoxy(i, 20);
        cout << char(178);
    }
    
    for (int i = 0; i <= 25; i++) 
    {
        gotoxy(41, i);
        cout << char(178);
        gotoxy(53, i);
        cout << char(178);
        gotoxy(65, i);
        cout << char(178);
        gotoxy(77, i);
        cout << char(178);
    }   
}
int main ()
{
    
    system("Color B");
    int x = 30;
    int y = 21;
    char movimiento;
    int cont = 0;
    while (cont < 2)
    {
        system("cls");
        dibujo(x, y);
        dibujarmatriz();
        recuadro();
        cout << endl << "Movimientos: " << 2 - cont << endl; 
        cout << "Ingrese una tecla: ";
        cin >> movimiento;
        switch(movimiento)
        {   
            case 'w':
            {
                if(y > 5)
                {
                    y -= 5;
                    cont++;
                }   
            }           
            break;
            case 'a':
            {
                if(x > 30)
                {
                    x -= 12;
                    cont++;
                }         
            }         
            break;
            case 's':
            {
                if(y < 20)
                {
                    y += 5;
                    cont++;
                }    
            }          
            break;
            case 'd':  
            {
                if(x < 78)
                {
                    x += 12;
                    cont++;
                } 
            }        
            break;
        } 
    }
    system("cls");
    dibujo(x, y);
    dibujarmatriz();
    recuadro();     
}