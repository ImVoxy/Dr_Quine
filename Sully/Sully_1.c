int z = 1;
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printer();
#define FT int main(){printer();return(0);}

static void		letri(char *a, int i)
{
	int		j;
	int		k;
	char	c;

	j = 0;
	if (a[0] == '-')
		j = 1;
	k = i / 2;
	while (i > k)
	{
		c = a[i];
		a[i] = a[j];
		a[j] = c;
		i--;
		j++;
	}
}

static int		ft_abs(int n)
{
	long int r;

	r = n;
	if (r < 0)
		r *= -1;
	return (r);
}

static long int	ft_pow(int i)
{
	long int val;

	val = 1;
	while (i)
	{
		val *= 10;
		i--;
	}
	return (val);
}

char			*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*a;

	size = 1;
	i = 0;
	while (n / ft_pow(size))
		size++;
	if (n < 0)
		i = 1;
	if (!(a = (char *)calloc(size + 1 + i, sizeof(char))))
		return (NULL);
	if (i == 1)
		a[0] = '-';
	while (n >= 10 || n <= -10)
	{
		a[i] = ft_abs(n % 10) + 48;
		i++;
		n /= 10;
	}
	a[i] = ft_abs(n % 10) + 48;
	letri(a, i);
	return (a);
}

char* ft_concat(const char *s1, const char *s2)
{
	char *result;

	result = NULL;
	if (!(result = malloc(strlen(s1) + strlen(s2) + 1)))
	{
		write (1, "Error malloc\n", 13);
		result = "0";
		return (result);	
	}
	strcpy(result, s1);
	strcat(result, s2);
	return (result);
}

void printer()
{
	if (z > 0)
	{
		FILE *rfptr;
		int wf;
		int cont;
		char toprint;
		int status;
		char *num;
		char *numprev;
		char *fname;
		char *fnameprev;
		char *exname;
		char *ccname;

		numprev = ft_itoa(z);
		fnameprev = ft_concat(ft_concat("Sully_", numprev), ".c");
		rfptr = NULL;
		if ((rfptr = fopen(fnameprev, "r")) == NULL)
			{
				num = ft_itoa(z);
				z = z + '0';
				if ((rfptr = fopen("Sully.c", "r")) == NULL)
				{
					write (1, "Error while opening file\n", 25);
					free(fnameprev);
					free(num);
					return ;
				}
			}
		else
		{
			num = ft_itoa(z - 1);
			z = z + '0' - 1;
		}
		fname = ft_concat(ft_concat("Sully_", num), ".c");
		ccname = ft_concat(ft_concat(ft_concat("gcc -o Sully_", num), " "), fname);
		exname = ft_concat("./Sully_", num);
		status = 1;
			
			wf = 0;
			cont = 0;
			toprint = 0;
			
			if ((wf = open(fname, O_CREAT | O_APPEND | O_RDWR, 0666)) == -1)
			{	
					write (1, "Error while opening file\n", 25);
			free(ccname);
			free(exname);
			free(fname);
			free(fnameprev);
			free(num);
					return ;
			}
		free(fname);
		free(fnameprev);
		free(num);
		while (cont != '\n' && cont != EOF)
            cont = fgetc(rfptr);
		write(wf, "int z = ", 8);
		write(wf, &z, 1);
		write(wf, ";\n", 2);
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
//		if (ccname[13] != '0')
//		{
			status = system(ccname);
			while (status == 1)
			{}
			system(exname);
//		}
		free(ccname);
		free(exname);
	}
}

FT