#include <stdio.h>
#include <stdlib.h>

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

void hidecursor();



void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //villogó kurzor eltüntetésére használt metódus
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}




int main()
{
    hidecursor();//meghívjuk a villogó kurzor eltüntetésére alkalmas hidecursor() fv-t, majd a program fõmenüjébe lépünk menu() fv-el
    menu();
    return 0;
}
