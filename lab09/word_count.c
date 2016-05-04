//by Sebastian Foubert

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

struct count { 
        int lines;
        int words; 
        int characters; 
};
int process_line(char *line, size_t n,struct count *k)
{
	int i;
	//int *j;

	i=0;
	//struct count *k = malloc(sizeof(struct count));
	//struct count *k;
	int a,b,c;
	a = 0;//k -> lines = 0;
	b = 1;//k -> words = 0;
	c = 0;//k -> characters = 0;
	
 
	
	while(line[i]) //Count
	{
		if (line[i] == '\n' )
			a++;
		else if (line[i] == ' ')//&& line[i+1] != ' ')
			b++;
		//else
		if (line[i] != ' ' && line[i+1] != ' ')
			c++;
		
		i++;
	}
	c--;
	k->lines += a ;
	
	k->words += b ;
		
	k->characters += c;
	
	//j = k->lines;


	fputs(line, stdout);
	fflush(stdout);

	return 0;
}

int main(int argc, char *argv[])
{
	struct count *k = malloc(sizeof(struct count*));
	k ->lines = 0;
	k ->words = 0;
	k ->characters = 0; 
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
			if (process_line(lineptr, rc,k) < 0) {
				exit_status = 1;
				free(lineptr);
				break;
			}
		}

		free(lineptr);
		lineptr = 0;
		n = 0;
	}
	
	//printf("%d\n",k ->characters);
	printf("Lines: %d\nWords: %d\nCharacters: %d\n", k -> lines, k -> words, k-> characters);

	if (ferror(fp)) {
		fprintf(stderr, "Error reading %s: %s\n", argv[1], strerror(errno));
		exit_status = 1;
	}

	fclose(fp);
	exit(exit_status);
}