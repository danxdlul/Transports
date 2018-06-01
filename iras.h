#ifndef IRAS_H_INCLUDED
#define IRAS_H_INCLUDED
#include "transpstruct.h"
#include <time.h>
 /*
 iras.h
 Az e fájlban található függvények együttes funkciója egy olyan menürendszer létrehozása, mellyel új fájlt hozhatunk létre, vagy meglévő fájlba vihetünk be új adatokat. Minden esetben ellenőrzött bevitel történik
 A készítő neve: Kása Dániel Zoltán
 Utolsó módosítás dátuma: 2016.11.27, ver 4.20
 */
int isnum(char strung[],int valid);
void datum();
void iras();
void ujfajl();
void appendalas();
void menu();


#endif // IRAS_H_INCLUDED
