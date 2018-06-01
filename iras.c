#include "iras.h"
#include "fajlIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>

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
int isnum(char strung[],int valid) //egy strung nevű karaktertömb elemeit vizsgálja, ha minden eleme egy egész szám, 1-es értékkel, ellenkező esetben hibát ír ki és 0-ás értékkel tér vissza(ár és szállítási költség ellenőrzött beviteléhez szükséges)
{
            int i,hossz;
            hossz = strlen(strung);
            for (i=0;i<hossz; i++)
                {
                    if (!isdigit(strung[i]))
                        {
                            valid = 0;
                        }
                    else
                        {
                            valid = 1;
                        }
                    if(valid==0)
                        {
                            printf("A bemenet csak numerikus karaktereket tartalmazhat!");
                            break;
                        }
                }
                return valid;

}
void datum(char* outstring)//kézbesítés idejének ellenőrzött beviteléhez szükséges fv. ha a dátum hibás, vagy jövőbeli dátum, vagy 1900 előtti dátum, hibát ír ki
{
   time_t timeval;
   struct tm *tp;
   char sztring[15];
   time (&timeval);
   tp = gmtime(&timeval);
   char buffer[15];
   int n,h,e;
   int hanynapos[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   int valos = 0;
do
{
   hanynapos[1]=28;
   printf("\nKezbesites datuma (EEEE/HH/NN): \n");
   scanf("%i/%i/%i",&e,&h,&n);

   // szökőév esetén február értékét átírja 29-re
   if(e % 400 == 0 || (e % 100 != 0 && e % 4 == 0))
   {
    hanynapos[1]=29;
   }
   // megnézi hogy 0 és 12 közé esik e a hónap, valamint az év az idei évnél kisebb-e és 1900-nál nagyobb-e, valamint hogy az adott hónap esetén létezhet-e a megadott nap, valamint a megadott nap nagyobb-e mint 0
   if (h<13 && h>0 && e<=(tp->tm_year+1900) && e >=1900 && n <=hanynapos[h-1] && n>0)
   {
        valos = 1;
   }

   if (valos==1)
   {
      strcat(sztring,itoa(e,buffer,10));
      strcat(sztring,"/");
      strcat(sztring,itoa(h,buffer,10));
      strcat(sztring,"/");
      strcat(sztring,itoa(n,buffer,10));
   }
   else
   {
      printf("Nem valos datum!\n");
   }
}while(!valos);
strcpy(outstring,sztring);
}
void iras()
{
    int valaszt = 0; //írás esetén egy, az elõzõhöz hasonló menün keresztül lehet választani fájl létrehozása, vagy meglévõ fájlba írás között(vagy visszalépés)
    char c;
    do{
        system("cls");
        switch(valaszt)
        {
            case 0:
                printf(">Uj fajl letrehozasa\n");
                printf(" Meglevo fajlba iras\n");
                printf(" Vissza");
                break;
            case 1:
                printf(" Uj fajl letrehozasa\n");
                printf(">Meglevo fajlba iras\n");
                printf(" Vissza");
                break;
            case 2:
                printf(" Uj fajl letrehozasa\n");
                printf(" Meglevo fajlba iras\n");
                printf(">Vissza");
                break;
            default:
                break;
        }
        c = getch();
        valaszt = lepeget(c,valaszt,3);
    }
    while(c != '\r');
    switch(valaszt)
    {
    case 0:
        ujfajl();
    case 1:
        appendalas();
        break;
    case 2:
        menu();
        break;
    default:
        break;
    }
}
void ujfajl()
{
    system("cls");
    printf("Adja meg a fajl nevet(max 252 karakter)(0 - visszalepes)\n"); //az utolsó 4 karakter a .txt nek szükséges
    char fajlnev[256];
    if(strlen(fajlnev)>252) //hibakezelés túl hosszú név esetén
        {
            printf(" Fajlnev tul hosszu!\n");
            printf(">OK");
            getch();
            iras();
        }
    scanf("%s",fajlnev);
    if(strcmp(fajlnev,"0")==0) //nulla esetén visszalép
        {
            iras();
        }
    FILE *fp;
    FILE *fp2;
    strcat(fajlnev,".txt");
    fp = fopen(fajlnev,"r");
    int valaszt = 0;
    if (fp != NULL)
        {
            char c;
            do{
                system("cls");
                printf("Ilyen neven mar letezik fajl. Felulirja?\n"); //ha az fp pointer nem NULLra mutat, akkor létezik a fájl, a felhasználó eldöntheti hogy felülírja vagy nem
        switch(valaszt)
        {
            case 0:
                printf(">Igen\n");
                printf(" Nem");
                break;
            case 1:
                printf(" Igen\n");
                printf(">Nem");
                break;
            default:
                break;
        }
        c = getch();
        valaszt = lepeget(c,valaszt,2);
        }
        while(c != '\r');
        if (valaszt==1)
            {
                ujfajl();
            }
        else
            {
                valaszt = 1;
            }
        }
    fp = fopen(fajlnev,"w");
    fp2 = fopen("count.txt","r"); //a count.txt tartalmazza az összes létrehozott fájlt, és a létrehozás sorrendjében a fájlok sorszámát
    if (valaszt == 1)
        {
            iras();
        }
    if(fp2 == NULL) //ha count.txt még nem létezik(tehát ez az elsõ fájl)létrehozza, majd 1-es sorszámmal feljegyzi a létrehozott fájlt
        {
            fp2 = fopen("count.txt","w");
            fprintf(fp2,"%d - %s\n",1,fajlnev);
        }
    else
        {
            int counter = countlines("count.txt")+1; //ellenkezõ esetben új sorban az elõzõ sorszám+1 után feljegyzi a fájl nevét
            //int ch;
            fp2 = fopen("count.txt","a");
            fprintf(fp2,"%d - %s\n",counter,fajlnev);
        }
    fclose(fp2);
    fclose(fp);
    iras();
}
void appendalas()//meglévő fájlba írunk új adatot
{
    system("cls");
    FILE *fp2 = fopen("count.txt","r"); //count.txt-bõl megpróbálja beolvasni a fájlok listáját
    if(fp2 == NULL)
        {
            printf(" Meg nem letezik egyetlen fajl sem!\n"); //ha nincs egy sem, tehát count.txt nem létezik, akkor errõl tájékoztat, majd visszaléphetünk
            printf(">OK");
            getch();
            iras();
        }
    int sorszam, curr, valaszt = 0;
    char carac;
    char fajlnev[256];
    printf("Hanyas sorszamu fajlba akar irni?(0 a visszalepeshez)\n");
    listazas("count.txt"); //a listazas nevû metódus kiírja count.txt összes karakterét(azaz a fájlok listáját), majd a scanf sorszámot vár a felhasználótól
    scanf("%d",&sorszam);
    if(sorszam == 0) //0 esetén visszalépés
        {
            iras();
        }
    FILE *fp;
    if(sorszam <= countlines("count.txt")){ //ha a sorszám kisebb vagy egyenlõ a count.txt sorainak számával, addig vizsgáljuk count.txt sorait, amig el nem jutunk a kívánt sorszámig, majkd a hozzá tartozó fájlnevet tároljuk
    fp = fopen("count.txt","r");
    do
        {
            fscanf(fp,"%d - %s",&curr,fajlnev);
        }
        while(curr != sorszam);
        fclose(fp);
        }
    else
        {
            printf("\n Nincs ilyen fajl!"); //ha a sorszám nagyobb mint count.txt legnagyobb sorszáma, tájékoztatjuk a felhasználót hogy nincs ilyen fájl, majd visszaléphetünk
            printf("\n>OK");
            getch();
            appendalas();
        }
        do{
    fp = fopen(fajlnev,"a+");
    Transzport *c =(Transzport*)malloc(sizeof(Transzport)); //memóriát allokálunk egy transzport (lokális)struktúrának
    if(c==NULL)
        {
            printf("Nincs eleg memoria!!");
            exit(-1);
        }
    char be[11];
    char *pos;
    int valid = 0;
    system("cls");//egyesével bekérjük az adatokat a struktúrába
    printf("Aru kiindulasi pontja: \n");
    scanf("%s",c->kiindulas);
    printf("\nAru celpontja: \n");
    scanf("%s",c->cel);
    do
       {
            printf("\nSzallitasi koltseg ft-ban: \n");
            fflush(stdin);
            fgets(be,11,stdin);
            if ((pos=strchr(be, '\n')) != NULL)
                {
                    *pos = '\0';
                    valid = isnum(be,valid);
                }
            else
                {
                    printf("A bemenet tul hosszu!");
                }
       }
        while(!valid);
    c->szallitas = atoi(be);
    valid = 0;
    do
        {
            printf("\nAruertek ft-ban: \n");
            fflush(stdin);
            fgets(be,11,stdin);
            if ((pos=strchr(be, '\n')) != NULL)
                {
                    *pos = '\0';
                    valid = isnum(be,valid);
                }
            else
                {
                    printf("A bemenet tul hosszu!");
                }
        }
    while(!valid);
    c->aruertek = atoi(be);
    datum(c->kezbesites);
    //fprintf-el kiírjuk a struktúra adatait a fájl egy sorában, majd új sor kezdete(fontos)
    fprintf(fp, "%-30s %-30s %-19d %-10d %-15s\n", c->kiindulas, c->cel,c->aruertek,c->szallitas,c->kezbesites);
    free(c);
    do
        {
            system("cls");
            printf("Megegy adat bevitele?\n");//megkérdezzük a felhasználót hogy akar-e mégegy adatot bevinni, ha igen, a ciklus folytatódik a memóriaallokálásnál
            switch(valaszt)
            {
            case 0:
                printf(">Igen\n");
                printf(" Nem");
                break;
            case 1:
                printf(" Igen\n");
                printf(">Nem");
                break;
            default:
                break;
            }
            carac = getch();
            valaszt = lepeget(carac,valaszt,2);
        }
        while(carac != '\r');
        fclose(fp);
    }
    while(valaszt != 1);//nem esetén az iras nevû metódusba lépünk vissza
    iras();
}

