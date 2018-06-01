#ifndef SZURESEK_H_INCLUDED
#define SZURESEK_H_INCLUDED
#include "transpstruct.h"
 /*
 szuresek.h
 Az e fájlban található függvények együttes funkciója a fájlban szereplő rekordok adattaigjaira való szűréshez szükséges menü létrehozása
 A készítő neve: Kása Dániel Zoltán
 Utolsó módosítás dátuma: 2016.11.27, ver 4.20
 */
void szures(char* fajlnev);
void szuresszam(int szam,FILE *fp,int nmbr);
void szureskarakter(char szoveg[],FILE *fp,int nmbr);


#endif // SZURESEK_H_INCLUDED
