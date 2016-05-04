//by Sebastian Foubert

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char prev_line[256];
int prev_count;

int process_line(char *line, size_t n)
{
    if(strcmp(line, prev_line) == 0){
        prev_count++;
    }
    else {
        if(prev_count > 0){
            char output[256];
            sprintf(output, "%12d\t%s", prev_count, prev_line);
            fputs(output, stdout);
            fflush(stdout);
        }
        strcpy(prev_line, line);
        prev_count=1;
   }

	return 0;
}

int main(int argc, char *argv[])
{
	int exit_status = 0;
	FILE *fp;
    prev_count = 0;

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

    char output[256];
    sprintf(output, "%12d\t%s", prev_count, prev_line);
    fputs(output, stdout);
    fflush(stdout);
    
	fclose(fp);
	exit(exit_status);
}