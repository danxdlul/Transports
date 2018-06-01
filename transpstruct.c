#include "transpstruct.h"
#include <stdio.h>
void listazas(char* str)
{
    FILE *fp; //metódus, mely kiirja egy szöveges állomány minden karakterét
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
  // a fajlnev nevû fajlban megszámolja a sorok számát
  FILE *fp = fopen(fajlnev,"r");
  int ch=0;
  int lines=0;

  while(!feof(fp))//minden karaktert beolvas, sortöréseket számolja
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
