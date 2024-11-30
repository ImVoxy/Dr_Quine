#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void printer();
#define FT int main(){printer();return(0);}


void printer()
{
        FILE *rfptr;
        int wf;
        int cont;
        char toprint;

        rfptr = NULL;
        wf = 0;
        cont = 0;
        toprint = 0;
        if ((rfptr = fopen("Grace.c", "r")) == NULL)
        {
                write (1, "Error while opening file\n", 25);
                return ;
        }
        if ((wf = open("./Grace_kid.c", O_CREAT | O_APPEND | O_RDWR, 0666)) == -1)
        {
                write (1, "Error while opening file\n", 25);
                return ;
        }
        while (1)
        {
                cont = fgetc(rfptr);
                if (cont == EOF)
                {
                        fclose(rfptr);
			close(wf);
                        break;
                }
                toprint = cont;
                write(wf, &toprint, 1);
        }
}

FT

/*
	The comment
*/
