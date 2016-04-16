//by Sebastian Foubert

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>


int process_line(char *line, size_t n)
{
	int i,j;



	while (line[i]) // Lower cap
	{
		if (line[i] > 63 && line[i] < 97 )
			line[i] = line[i] + 32;
		i++;
	}
	i=0;
	while (line[i]) // Punctuation
	{	
		if (ispunct(line[i]) != 0 ) //line[i] > 122 || line[i] < 97
		{
			j = i;
			for (; j < n - 1 ; j++)
    		{
       			line[j] = line[j+1];
    		}
    		line[j] = '\0';

		}
		i++;
	}
	
	fputs(line, stdout);
	fflush(stdout);
	printf("\n");
	

	return 0;
}

int main(int argc, char *argv[])
{
	int exit_status = 0;
	FILE *fp;


	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");

	

		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
			exit(1);
		}
	}


	size_t n = 0;
	char *lineptr = 0;


	for (;;) {

		ssize_t rc = getline(&lineptr, &n, fp);

	

		if (rc < 0) {
			break;
		}

		if (rc > 0) {
			if (process_line(lineptr, rc) < 0) {
				exit_status = 1;
				free(lineptr);
				break;
			}
		}

		free(lineptr);
		lineptr = 0;
		n = 0;
	}

	if (ferror(fp)) {
		fprintf(stderr, "Error reading %s: %s\n", argv[1], strerror(errno));
		exit_status = 1;
	}

	fclose(fp);
	exit(exit_status);
}