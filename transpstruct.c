#include "transpstruct.h"
#include <stdio.h>
void listazas(char* str)
{
    FILE *fp; //met�dus, mely kiirja egy sz�veges �llom�ny minden karakter�t
    int c;
    fp = fopen(str,"r");
    while((c = getc(fp)) != EOF)
        {
            putchar(c);
        }
        fclose(fp);
}
int countlines(char *fajlnev)
{
  // a fajlnev nev� fajlban megsz�molja a sorok sz�m�t
  FILE *fp = fopen(fajlnev,"r");
  int ch=0;
  int lines=0;

  while(!feof(fp))//minden karaktert beolvas, sort�r�seket sz�molja
{
  ch = fgetc(fp);
  if(ch == '\n')
  {
    lines++;
  }
}
  fclose(fp);
  return lines;
}
