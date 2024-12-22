#include <stdio.h>
#include <fcntl.h>
#define FILENAME "Grace_kid.c"
#define SRC "#include <stdio.h>%1$c#include <fcntl.h>%1$c#define FILENAME %4$cGrace_kid.c%4$c%1$c#define SRC %4$c%3$s%4$c%1$c#define FT int main(){FILE *wf = NULL; if ((wf = fopen(FILENAME, %4$cw%4$c)) == NULL) return 0; fprintf(wf, SRC, 10, 9, SRC, 34); return(0);}%1$c%1$cFT%1$c%1$c/*%1$c%2$cThe comment%1$c*/"
#define FT int main(){FILE *wf = NULL; if ((wf = fopen(FILENAME, "w")) == NULL) return 0; fprintf(wf, SRC, 10, 9, SRC, 34); return(0);}

FT

/*
	The comment
*/