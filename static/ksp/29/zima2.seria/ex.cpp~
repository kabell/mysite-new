#include <stdio.h> 
#include <stdlib.h> 

int main (int argc, char *argv[]) 
{ 
  FILE *f, *f1;
  int c,j;
  const char Win1250[] =  {(char)0xE1,(char)0xE4,(char)0xB9,(char)0xE2,
                           (char)0xE3,(char)0xE8,(char)0xE6,(char)0xE7,
                           (char)0xEF,(char)0xF0,(char)0xE9,(char)0xEC,
                           (char)0xEB,(char)0xEA,(char)0xED,(char)0xEE,
                           (char)0xBE,(char)0xB3,(char)0xE5,(char)0xF2,
                           (char)0xF1,(char)0xF3,(char)0xF6,(char)0xF4,
                           (char)0xF5,(char)0xF8,(char)0xE0,(char)0x9A,
                           (char)0xBA,(char)0x9C,(char)0x9D,(char)0xFE,
                           (char)0xFA,(char)0xF9,(char)0xFC,(char)0xFB,
                           (char)0xFD,(char)0x9E,(char)0x9F,(char)0xBF,
                           (char)0xC1,(char)0xC4,(char)0xA5,(char)0xC2,
                           (char)0xC3,(char)0xC8,(char)0xC6,(char)0xC7,
                           (char)0xCF,(char)0xD0,(char)0xC9,(char)0xCC,
                           (char)0xCB,(char)0xCA,(char)0xCD,(char)0xCE,
                           (char)0xBC,(char)0xA3,(char)0xC5,(char)0xD2,
                           (char)0xD1,(char)0xD3,(char)0xD6,(char)0xD4,
                           (char)0xD5,(char)0xD8,(char)0xC0,(char)0x8A,
                           (char)0xAA,(char)0x8C,(char)0x8D,(char)0xDE,
                           (char)0xDA,(char)0xD9,(char)0xDC,(char)0xDB,
                           (char)0xDD,(char)0x8E,(char)0x8F,(char)0xAF,
                           (char)0x00};
  const char BezDiak[] =  {(char)0x61,(char)0x61,(char)0x61,(char)0x61,
                           (char)0x61,(char)0x63,(char)0x63,(char)0x63,
                           (char)0x64,(char)0x64,(char)0x65,(char)0x65,
                           (char)0x65,(char)0x65,(char)0x69,(char)0x69,
                           (char)0x6C,(char)0x6C,(char)0x6C,(char)0x6E,
                           (char)0x6E,(char)0x6F,(char)0x6F,(char)0x6F,
                           (char)0x6F,(char)0x72,(char)0x72,(char)0x73,
                           (char)0x73,(char)0x73,(char)0x74,(char)0x74,
                           (char)0x75,(char)0x75,(char)0x75,(char)0x75,
                           (char)0x79,(char)0x7A,(char)0x7A,(char)0x7A,
                           (char)0x41,(char)0x41,(char)0x41,(char)0x41,
                           (char)0x41,(char)0x43,(char)0x43,(char)0x43,
                           (char)0x44,(char)0x44,(char)0x45,(char)0x45,
                           (char)0x45,(char)0x45,(char)0x49,(char)0x49,
                           (char)0x4C,(char)0x4C,(char)0x4C,(char)0x4E,
                           (char)0x4E,(char)0x4F,(char)0x4F,(char)0x4F,
                           (char)0x4F,(char)0x52,(char)0x52,(char)0x53,
                           (char)0x53,(char)0x53,(char)0x54,(char)0x54,
                           (char)0x55,(char)0x55,(char)0x55,(char)0x55,
                           (char)0x59,(char)0x5A,(char)0x5A,(char)0x5A,
                           (char)0x00};
  f = fopen("wiki","r");
  if (!f) { 
    printf("Soubor se nepodarilo otevrit soubor pokus.txt pro cteni!\n"
           "Program ukoncete stiskem klavesy ENTER!...");
    fflush(stdin);
    getchar();
    return 1; 
  };
  f1 = fopen("output","w"); 
  if (!f1) { 
    fclose(f);
    printf("Soubor se nepodarilo otevrit soubor pokus1.txt pro zapis!\n"
           "Program ukoncete stiskem klavesy ENTER!...");
    fflush(stdin);
    getchar();
    return 2; 
  };
  while ((c = getc(f)) != EOF) {
    for (j = 0; Win1250[j]; j++) if ((char)c == Win1250[j]) break;
    if (Win1250[j]) {
      putc((int)BezDiak[j],f1);
    } else {
      putc(c,f1);
    };
  };
  fclose(f); 
  fclose(f1);
  printf("Provedeno OK. Program ukoncete stiskem klavesy ENTER!...");
  fflush(stdin);
  getchar();
  return 0;
};
