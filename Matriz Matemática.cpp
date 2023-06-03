#include <windows.h>
#include <iostream>
#include <direct.h>
#include <stdlib.h>
#include <ctime>
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
    gotoxy(91, 2);
    cout << "<- META";
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
int resultado;
void nums(int xnums, int ynums)
{
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int num3 = rand() % 10 + 1;
    int num4 = rand() % 10 + 1;
    int num5 = rand() % 10 + 1;
    int num6 = rand() % 10 + 1; 
    int num7 = rand() % 10 + 1;
    int num8 = rand() % 10 + 1;

    if((xnums == 30) || (ynums == 1))
    {
        num1 = 0;
    }
    else
    {
        gotoxy(xnums - 7, ynums - 3);
        cout << num1;
    }
    if(ynums == 1)
    {
        num2 = 0;
    }
    else
    {  
        gotoxy(xnums + 5, ynums - 3);
        cout << num2;        
    }
    if((xnums == 78) || (ynums == 1))
    {
        num3 = 0;
    }
    else
    {
        gotoxy(xnums + 17, ynums - 3);
        cout << num3; 
    }
    if(xnums == 30)
    {
        num4 = 0;
    }
    else
    {
        gotoxy(xnums - 7, ynums + 2);
        cout << num4;
    }
        
    if(xnums == 78)
    {
        num5 = 0;
    }
    else
    {
        gotoxy(xnums + 17, ynums + 2);
        cout << num5;  
    }
    if((xnums == 30) || (ynums == 21))
    {
        num6 = 0;
    }
    else
    {
        gotoxy(xnums - 7, ynums + 7);
        cout << num6;
    } 
    if(ynums == 21)
    {
        num7 = 0;
    }
    else
    {
        gotoxy(xnums + 5, ynums + 7);
        cout << num7;
    } 
    if((xnums == 78) || (ynums == 21))
    {
        num8 = 0;
    }
    else
    {
        gotoxy(xnums + 17, ynums + 7);
        cout << num8;
    } 
    resultado = ((num1 + num2 + num3) * num5) - ((num6 + num7 + num8) * num4);
}

int main()
{
    system("Color B");
    int x = 30;
    int y = 21;
    int preX = 30;
    int preY = 21;
    char movimiento;
    int cont = 0;
    int fallos = 0;
    bool win = false;
    while ((fallos < 8) && (!win))
    {
        if(cont == 0)
        {
            preX = x;
            preY = y;
        }
        system("cls");
        dibujo(x, y);
        dibujarmatriz();
        recuadro();
        cout << endl << "Fallos restantes: " << 8 - fallos << endl;
        cout << "Movimientos: " << 2 - cont << endl; 
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
        if(cont == 2)
        {
            if((x == 78) && (y == 1))
            {
                win = true;
            } 
            int valor = 0;
            if(!win)
            {
                system("cls");
                nums(x, y);
                dibujo(x, y);
                dibujarmatriz();
                recuadro(); 
                cout << endl << "Fallos restantes: " << 8 - fallos << endl;
                cout << "Ingrese el valor: ";
                cin >> valor;
                if(valor == resultado)
                {
                    cout << "Correcto!" << endl;
                    cont = 0;
                }
                else
                {
                    cout << "fallaste :(" << endl;
                    fallos += 1;
                    cont = 0;
                    x = preX;
                    y = preY;
                }
                system("pause");
            }  
        }   
    }
    bool Restart;
    int Rep;
    if(win)
    {
        system("cls");
        dibujo(x, y);
        dibujarmatriz();
        recuadro(); 
        cout << endl << " Ganaste! " << endl;
        system("pause");
    }  
    if(!win)
    {
        system("cls");
        dibujo(x, y);
        dibujarmatriz();
        recuadro(); 
        cout << endl << " Perdiste :( " << endl;
        system("pause");
    }
    Restart = false;
    do
    {
        system("cls");
        cout << "---------------------------" << endl;
        cout << "1. Volver a jugar" << endl; 
        cout << "0. Salir" << endl;
        cout << "---------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> Rep;
        system("cls");
        switch (Rep)
        {
            case 1: 
                main();
            break;
            case 0: 
                exit(0);
            break;
            default:
                Restart = true;
            break;
        }
    } while(Restart);    
}