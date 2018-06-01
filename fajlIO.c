#include "fajlIO.h"

int lepeget(char c,int valaszt,int sorok)//a menü léptetésére használt metódus, ugyanis nyilbillentyűknél a getch() 2 értékkel tér vissza a buferről
{
        if(c == -32){   //az első érték minden nyilbillentyű esetén -32
                c= getch();
        if(c == 72 && valaszt > 0) //a második felfelé nyil esetében 72, lefele nyílnál 80
            {
                valaszt--;
            }
            else if(c == 80 && valaszt < sorok-1) //a valaszt értéke nem lépi tul a menü sorainak számát
                {
                    valaszt++;
                }
        }
        return valaszt;
}
void choosefile()
{
    system("cls");
    FILE *fp2 = fopen("count.txt","r"); //count.txt bõl kiolvassuk a fájlok listáját, ha count.txt nem létezik, tájékoztatjuk a felhasználót hogy nincsenek fájlok, majd visszaléphetünk
    if(fp2 == NULL)
        {
            printf(" Meg nem letezik egyetlen fajl sem!\n");
            printf(">OK");
            getch();
            menu();
        }
    int sorszam, curr, valaszt = 0;
    char carac;
    char fajlnev[256];
    printf("Hanyas sorszamu fajlt akarja megnyitni?(0 - visszalepes)\n");
    listazas("count.txt"); //listazas metódussal kiírjuk count.txt összes karakterét, majd egy sorszámra várunk a felhasználótól
    scanf("%d",&sorszam);
    if(sorszam == 0) //0 esetén vissza a menübe
        {
            menu();
        }
    FILE *fp;
    if (sorszam <= countlines("count.txt")) //ha kisebb,egyenlõ a megadott sorszám mint ahány sora van count.txt-nek akkor létezik a fájl, megnyitjuk
        {
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
            printf(" Nincs ilyen fajl!\n"); //ha nem létezik, tájékoztatjuk a felhasználót, majd újra meghívódik a metódus
            printf(">OK");
            getch();
            choosefile();
        }
olvas(fajlnev); //sikeres beolvasás esetén olvas metódust hívjuk meg a 'fajlnev' argumentummal
}
void olvas(char* fajlnev)
{
    //az olvas metódus lényegében csak egy menü, amivel a különbözõ mûveletek között választhatunk
 int valaszt = 0;
    char c;
    do{
        system("cls");
        switch(valaszt)
        {
            case 0:
                printf(">Szures kulonbozo adatokra\n");
                printf(" Koltsegek osszege\n");
                printf(" Vissza\n");
                break;
            case 1:
                printf(" Szures kulonbozo adatokra\n");
                printf(">Koltsegek osszege\n");
                printf(" Vissza\n");
                break;
            case 2:
                printf(" Szures kulonbozo adatokra\n");
                printf(" Koltsegek osszege\n");
                printf(">Vissza\n");
                break;
            default:
                break;
        }
        printf("\n%-30s %-30s %-19s %-10s %-15s\n","Kiindulasi hely","Celpont","Szallitasi koltseg","Aru erteke","Kezbesites datuma");
        listazas(fajlnev);
        c = getch();
        valaszt = lepeget(c,valaszt,3);
    }
    while(c != '\r');
    switch(valaszt)
    {
    case 0:
        szures(fajlnev);
        break;
    case 1:
        osszegzes(fajlnev);
        break;
    case 2:
        menu();
        break;
    default:
        break;
    }
}
void osszegzes(char* fajlnev)//a költségek összegét írja ki
{
    int osszeg = 0;
    FILE *fp;
    char c;
    Transzport *tran=(Transzport*)malloc(sizeof(Transzport));//memória allokálása lokális transzport struktúrának
    if(tran==NULL)//hibakezelés
        {
            printf("Nincs eleg memoria!!");
            exit(-1);
        }
    int valaszt = 0;
    fp = fopen(fajlnev,"r");//megnyitjuk azt a fajlt, amelyik neve argumentuma volt a függvénynek híváskor
    do
        {
            system("cls");
    switch(valaszt)//menübõl választhatunk az összegzendõ elemek közül
    {
            case 0:
                printf(">Szallitasi koltsegek osszege\n");
                printf(" Aruertekek osszege\n");
                printf(" Osszes koltseg osszege\n");
                printf(" Vissza");
                break;
            case 1:
                printf(" Szallitasi koltsegek osszege\n");
                printf(">Aruertekek osszege\n");
                printf(" Osszes koltseg osszege\n");
                printf(" Vissza");
                break;
            case 2:
                printf(" Szallitasi koltsegek osszege\n");
                printf(" Aruertekek osszege\n");
                printf(">Osszes koltseg osszege\n");
                printf(" Vissza");
                break;
            case 3:
                printf(" Szallitasi koltsegek osszege\n");
                printf(" Aruertekek osszege\n");
                printf(" Osszes koltseg osszege\n");
                printf(">Vissza");
                break;
            default:
                break;
        }
        c = getch();
        valaszt = lepeget(c,valaszt,4);
        }
    while(c != '\r');
    system("cls");
    switch(valaszt)
    {
    case 0:
        while(fscanf(fp,"%s %s %d %d %s",tran->kiindulas,tran->cel,&tran->szallitas,&tran->aruertek,tran->kezbesites)==5)
            //az elõbbi esetekhez hasonlóan, fscanf elõnyösebb mint feof
        {
        osszeg += tran->szallitas;//összegzés tétele szerint, minden létezõ szallitas értéket hozzáadunk egyesével osszeg jelenlegi értékéhez
        }
        printf("Az osszes transzport szallitasi dijanak osszege: %d\n",osszeg);
        printf(">OK");
        free(tran);
        getch();
        fclose(fp);
        olvas(fajlnev);//befejezésnél kiíratás után visszalépünk a hozott fajlnev-el az olvas metódusba
    case 1:
        while(fscanf(fp,"%s %s %d %d %s",tran->kiindulas,tran->cel,&tran->szallitas,&tran->aruertek,tran->kezbesites)==5)
        {
        osszeg += tran->aruertek;
        }
        printf("Az osszes transzport aruertekenek osszege: %d\n",osszeg);
        printf(">OK");
        free(tran);
        getch();
        fclose(fp);
        olvas(fajlnev);
    case 2:
        while(fscanf(fp,"%s %s %d %d %s",tran->kiindulas,tran->cel,&tran->szallitas,&tran->aruertek,tran->kezbesites)==5)
        {
        osszeg += tran->aruertek;
        osszeg += tran->szallitas;
        }
        printf("Az osszes transzport aruertekenek es szallitasi koltsegenek osszege: %d\n",osszeg);
        printf(">OK");
        free(tran);
        getch();
        fclose(fp);
        olvas(fajlnev);
    default:
        olvas(fajlnev);
        break;
    }
}
