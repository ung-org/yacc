#include <stdio.h>
#include <locale.h>

extern int yyparse(void);

int yyerror(const char *s)
{
	fprintf(stderr, "%s\n", s);
	return 0;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	yyparse();
	return 0;
}
