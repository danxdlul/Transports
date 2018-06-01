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
void szures(char* fajlnev)
{
    //a szures metódusban menün kereszül kiválaszthatjuk melyik adattípusra szeretnénk szûrni
    char c;
    FILE *fp;
    int szamlalo = 0;
    int valaszt = 0;
    do
        {
            system("cls");
            printf("Melyik adatra szeretne szurni?\n");
            switch(valaszt)
            {
            case 0:
                printf(">Transzport kiindulasi pontja\n");
                printf(" Transzport celpontja\n");
                printf(" Transzport szallitasi koltsege\n");
                printf(" Transport altal szallitot aru erteke\n");
                printf(" Transzport megerkezesenek idopontja\n");
                printf(" Vissza\n");
                break;
            case 1:
                printf(" Transzport kiindulasi pontja\n");
                printf(">Transzport celpontja\n");
                printf(" Transzport szallitasi koltsege\n");
                printf(" Transport altal szallitot aru erteke\n");
                printf(" Transzport megerkezesenek idopontja\n");
                printf(" Vissza\n");
                break;
            case 2:
                printf(" Transzport kiindulasi pontja\n");
                printf(" Transzport celpontja\n");
                printf(">Transzport szallitasi koltsege\n");
                printf(" Transport altal szallitot aru erteke\n");
                printf(" Transzport megerkezesenek idopontja\n");
                printf(" Vissza\n");
                break;
            case 3:
                printf(" Transzport kiindulasi pontja\n");
                printf(" Transzport celpontja\n");
                printf(" Transzport szallitasi koltsege\n");
                printf(">Transport altal szallitot aru erteke\n");
                printf(" Transzport megerkezesenek idopontja\n");
                printf(" Vissza\n");
                break;
            case 4:
                printf(" Transzport kiindulasi pontja\n");
                printf(" Transzport celpontja\n");
                printf(" Transzport szallitasi koltsege\n");
                printf(" Transport altal szallitot aru erteke\n");
                printf(">Transzport megerkezesenek idopontja\n");
                printf(" Vissza\n");
                break;
            case 5:
                printf(" Transzport kiindulasi pontja\n");
                printf(" Transzport celpontja\n");
                printf(" Transzport szallitasi koltsege\n");
                printf(" Transport altal szallitot aru erteke\n");
                printf(" Transzport megerkezesenek idopontja\n");
                printf(">Vissza\n");
            default:
                break;
            }
            c = getch();
            valaszt = lepeget(c,valaszt,6);
        }
        while(c != '\r');
        system("cls");
        fp = fopen(fajlnev,"r");
        int be;
        char bet[30];
        switch(valaszt)//minden egyes elágazásban bekérjük a keresési értéket, majd karakter esetén szureskarakter, szám esetén szuresszamot hívjuk meg
        {
        case 0:
            printf("Adja meg a keresni kivant kiindulasi pontot!\n");
            scanf("%s",bet);
            szureskarakter(bet,fp,1);//a harmadik agumentum a struktúrában szereplõ helyére utal, a karaktertömbök közül
            break;
        case 1:
            printf("Adja meg a keresni kivant celpontot!\n");
            scanf("%s",bet);
            szureskarakter(bet,fp,2);
            break;
        case 2:
            printf("Adja meg a keresni kivant szallitasi koltseget!\n");
            scanf("%d",&be);
            szuresszam(be,fp,1);//a harmadik argumentum a struktúrában szereplõ helyére utal, az integerek közül
            break;
        case 3:
            printf("Adja meg a keresni kivant aruerteket!\n");
            scanf("%d",&be);
            szuresszam(be,fp,2);
            break;
        case 4:
            printf("Adja meg a keresni kivant kezbesitesi datumot!(EEEE/HH/NN)\n");
            scanf("%s",bet);
            szureskarakter(bet,fp,3);
            break;
        case 5:
            fclose(fp);
            olvas(fajlnev);
        default:
            break;
        }
        getch();
        olvas(fajlnev); //végül az olvas metódusba lépünk vissza, a hozott fajlnev változóval
}
void szuresszam(int szam,FILE *fp,int nmbr)
{
    int counter = 0;
    Transzport *transp=(Transzport*)malloc(sizeof(Transzport));//lokális struktúrának memória allokálása
    if(transp == NULL)
        {
            printf("Nincs eleg memoria!!");//hibakezelés
            exit(-1);
        }
    while(fscanf(fp,"%s %s %d %d %s",transp->kiindulas,transp->cel,&transp->szallitas,&transp->aruertek,transp->kezbesites)==5)//attól függõen hogy a struktúrában hanyadik helyen álló integert nézzük, összehasonlítjuk a fájlbeli értéket a megadott kereseési értékkel
        {/*megj: az fscanf fv-nél nem célszerû az feof kritériumot adni, ugyanis utolsó sor olvasása után nem teljesül egybõl feof, tehát kétszer olvasná be
            célszerûbb azt vizsgálni hogy fscanf mennyi értékkel tért vissza, ha ez 5 akkor sikeresen beolvasott egy sort*/
            switch(nmbr)
            {
            case 1:
                if(szam == transp->szallitas)//összehasonlítás
                    {
                        counter++;//minden egyes egyezésnél növeljük a számlálót(megszámlálás tétele szerint)
                        printf("%s %s %d %d %s\n",transp->kiindulas,transp->cel,transp->szallitas,transp->aruertek,transp->kezbesites);
                    }
                    break;
            case 2:
                if(szam == transp->aruertek)
                    {
                        counter++;
                        printf("%s %s %d %d %s\n",transp->kiindulas,transp->cel,transp->szallitas,transp->aruertek,transp->kezbesites);
                    }
                    break;
            default:
                break;
            }
        }
        free(transp);//lefoglalt terület felszabadítása, majd számláló értékének kiírása
        printf("A kriteriumnak eleget tevo elemek szama: %d\n",counter);
        fclose(fp);
}
void szureskarakter(char szoveg[],FILE *fp,int nmbr)
{
    int counter = 0;
    Transzport *transp=(Transzport*)malloc(sizeof(Transzport));//memória allokálása lokális transzport struktúrának
    if(transp==NULL)//hibakezelés
        {
            printf("Nincs eleg memoria!!");
            exit(-1);
        }
    while(fscanf(fp,"%s %s %d %d %s",transp->kiindulas,transp->cel,&transp->szallitas,&transp->aruertek,transp->kezbesites)==5)
    {
        //akárcsak szuresszamnal, feof helyett érdemes fscanf visszatérési értékeinek számát vizsgálni
        switch(nmbr)
        {
        case 1:
            if (stricmp(szoveg,transp->kiindulas) == 0)//két sztring stricmp fv-el való vizsgálata, egyezés esetén 0 értéket ad(strcmp-vel ellentétben ez nagy- és kisbetû független)
                {
                    counter++;//megszámlálás tétele szerint egyezésnél a számlálót növeljük 1-el
                    printf("%s %s %d %d %s\n",transp->kiindulas,transp->cel,transp->szallitas,transp->aruertek,transp->kezbesites);
                    break;
                }
        case 2:
            if (stricmp(szoveg,transp->cel) ==0)
                {
                    counter++;
                    printf("%s %s %d %d %s\n",transp->kiindulas,transp->cel,transp->szallitas,transp->aruertek,transp->kezbesites);
                    break;
                }
        case 3:
            if (stricmp(szoveg,transp->kezbesites) ==0)
                {
                    counter++;
                    printf("%s %s %d %d %s\n",transp->kiindulas,transp->cel,transp->szallitas,transp->aruertek,transp->kezbesites);
                    break;
                }
        default:
            break;
        }
    }
    free(transp);//lefoglalt terület felszabadítása, számláló kiíratása
    printf("A kriteriumnak eleget tevo elemek szama: %d\n",counter);
    fclose(fp);
}


#endif // SZURESEK_H_INCLUDED
