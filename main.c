#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "fajlIO.h"
#include "iras.h"
#include "szuresek.h"
#include "transpstruct.h"
 /*
 main.c
 Az e fájlban található függvények együttes funkciója azon műveletek elvégzése, amely minden egyes futtatás esetével szükséges(kurzor elrejtése,főmenü megnyitása)
 A készítő neve: Kása Dániel Zoltán
 Utolsó módosítás dátuma: 2016.11.27, ver 4.20
 */
void menu();
void hidecursor();

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //villogó kurzor eltüntetésére használt metódus
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void menu()
{
    int valaszt = 0; //fõmenü metódus
    char c;
    do{
        system("cls");
        switch(valaszt)
        {
            case 0:
                printf(">Uj adat bevitele\n");
                printf(" Meglevo adat olvasasa\n");
                printf(" Kilepes");
                break;
            case 1:
                printf(" Uj adat bevitele\n");
                printf(">Meglevo adat olvasasa\n");
                printf(" Kilepes");
                break;
            case 2:
                printf(" Uj adat bevitele\n");
                printf(" Meglevo adat olvasasa\n");
                printf(">Kilepes");
                break;
            default:
                break;
        }
        c = getch();
        valaszt = lepeget(c,valaszt,3);
    }
    while(c != '\r');
    switch(valaszt) //enter lenyomása után annak megfelelõen hogy melyik menüpont volt kiválasztva(valaszt-nak mennyi volt az értéke)meghívódik egy metódus
    {
    case 0:
        iras();
        break;
    case 1:
        choosefile();
        break;
    case 2:
        exit(0);
    default:
        break;
    }
}


int main()
{
    hidecursor();//meghívjuk a villogó kurzor eltüntetésére alkalmas hidecursor() fv-t, majd a program fõmenüjébe lépünk menu() fv-el
    menu();
    return 0;
}
