#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define C_ID_FIRSTCHAR "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

int main(int argc, char *argv[])
{
	char *fileprefix = "y";
	char *symbolprefix = "yy";
	int header = 0;
	int lines = 1;
	int debug = 0;
	int verbose = 0;
	int c;

	while ((c = getopt(argc, argv, "bdlptv")) != -1) {
		switch (c) {
		case 'b':
			/* Change file prefix */
			fileprefix = optarg;
			break;

		case 'd':
			/* Write a header file */
			header = 1;
			break;

		case 'l':
			/* Omit #line directives */
			lines = 0;
			break;

		case 'p':
			/* Change symbol prefix */
			symbolprefix = optarg;
			if (!strchr(C_ID_FIRSTCHAR, *symbolprefix)) {
				printf("'%s' is not a valid prefix\n", optarg);
				return 1;
			}
			break;

		case 't':
			/* Include debugging code */
			debug = 1;
			break;

		case 'v':
			/* Output a description file */
			verbose = 1;
			break;
			
		default:
			return 1;
		}
	}

	if (optind != argc - 1) {
		fprintf(stderr, "Must specify exactly one grammar file\n");
		return 1;
	}

	return 0;
}
