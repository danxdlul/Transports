#ifndef FAJLIO_H_INCLUDED
#define FAJLIO_H_INCLUDED
#include "transpstruct.h"
 /*
 fajlIO.h
 Az e fájlban található függvények együttes funkciója a fájlműveletek végrehajtásához szükséges menürendszer létrehozása, adatok olvasása és összegzése
 A készítő neve: Kása Dániel Zoltán
 Utolsó módosítás dátuma: 2016.11.27, ver 4.20
 */
void choosefile();

void olvas(char* fajlnev);
void osszegzes(char* fajlnev);
int lepeget(char c,int valaszt,int sorok);

#endif // FAJLIO_H_INCLUDED
