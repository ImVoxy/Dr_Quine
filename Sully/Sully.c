#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int printer(int i);
#define FILENAME __FILE__
#define SRC "#include <fcntl.h>%1$c#include <stdio.h>%1$c#include <string.h>%1$c#include <stdlib.h>%1$c%1$cint printer(int i);%1$c#define FILENAME __FILE__%1$c#define SRC %3$c%2$s%3$c%1$c#define FT int printer(int i){int status; FILE *wf = NULL; char toprint[50]; char compname[100]; char exname[50]; if (i > 0){ if (strcmp(FILENAME, %3$cSully.c%3$c) != 0){i = i - 1;} sprintf(toprint, %3$cSully_%4$cd.c%3$c, i); sprintf(compname, %3$cgcc Sully_%4$cd.c -o Sully_%4$cd%3$c, i, i); sprintf(exname, %3$c./Sully_%4$cd%3$c, i); if ((wf = fopen(toprint, %3$cw%3$c)) == NULL) {return 0;} fprintf(wf, SRC, 10, SRC, 34, 37, i); fclose(wf); status = system(compname); while (status == 1) {} system(exname); return(0); } return(0);}%1$c%1$cint main()%1$c{%1$cint i = %5$d;%1$cprinter(i);%1$c}%1$c%1$cFT"
#define FT int printer(int i){int status; FILE *wf = NULL; char toprint[50]; char compname[100]; char exname[50]; if (i > 0){ if (strcmp(FILENAME, "Sully.c") != 0){i = i - 1;} sprintf(toprint, "Sully_%d.c", i); sprintf(compname, "gcc Sully_%d.c -o Sully_%d", i, i); sprintf(exname, "./Sully_%d", i); if ((wf = fopen(toprint, "w")) == NULL) {return 0;} fprintf(wf, SRC, 10, SRC, 34, 37, i); fclose(wf); status = system(compname); while (status == 1) {} system(exname); return(0); } return(0);}

int main()
{
int i = 5;
printer(i);
}

FT