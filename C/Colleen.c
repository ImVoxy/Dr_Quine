#include <stdio.h>

char *printer()
{
	return "#include <stdio.h>%1$c%1$cchar *printer()%1$c{%1$c%3$creturn %2$c%4$s%2$c;%1$c}%1$c%1$cint main()%1$c{%1$c%3$c/*%1$c%3$c %3$cMain comment%1$c%3$c*/%1$c%3$cchar *test = printer();%1$c%3$cprintf(test, 10, 34, 9, test);%1$c%3$creturn (0);%1$c}%1$c%1$c%3$c/*%1$c%3$c %3$cOutside comment%1$c%3$c*/%1$c";
}

int main()
{
	/*
	 	Main comment
	*/
	char *test = printer();
	printf(test, 10, 34, 9, test);
	return (0);
}

	/*
	 	Outside comment
	*/
