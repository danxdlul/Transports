#ifndef TRANSPSTRUCT_H_INCLUDED
#define TRANSPSTRUCT_H_INCLUDED
#include <stdio.h>
 /*
 transpstruct.h
 Az e fájlban található függvények együttes funkciója azon transzport struktúra definiálása, melyet az összes többi forrásfájl használ, valamint a szintén nagy tartományban használatos műveletek, mint a fájl tartamának kiírása, fájl sorainak megszámlálásának lehetővé tétele
 A készítő neve: Kása Dániel Zoltán
 Utolsó módosítás dátuma: 2016.11.27, ver 4.20
 */
void listazas(char* str);
int countlines(char *fajlnev);

typedef struct transport //transport struktúra definiálása Transzport néven, 3 karaktertömbbel és 2 integer változóval
{
    char kiindulas[30];
    char cel[30];
    int szallitas;
    int aruertek;
    char kezbesites[15];
} Transzport;


#endif // TRANSPSTRUCT_H_INCLUDED
