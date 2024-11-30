#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void printer()
{
	FILE *fptr;
	int cont;
	char toprint;

	fptr = NULL;
	cont = 0;
	toprint = 0;
	if ((fptr = fopen("Colleen.c", "r")) == NULL)
	{
		write (1, "Error while opening file\n", 25);
		return ;
	}
	while (1)
	{
		cont = fgetc(fptr);
		if (cont == EOF)
		{
			fclose(fptr);
			break;
		}
		toprint = cont;
		write(1, &toprint, 1);
	}
}

int main()
{
	/*
	 	Main comment
	*/
	printer();
	return (0);
}

	/*
	 	Outside comment
	*/
