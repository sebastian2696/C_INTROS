#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

struct count { 
        int *lines;
        int *words; 
        int *characters; 
};
int process_line(char *line, size_t n)
{
	int i,j;
	struct count k;
	
/*	for (i=0; i < n; i++) //Fix
	{
		tolower(line[i]);

	}
	for (i=0; i < n; i++) //works
	{
		if (line[i] > 63 && line[i] < 97 )
		line[i] = line[i] + 32;
	}
			printf("commencing strreask\n");	
	for (i=0; i < n; i++)
	{
		if (ispunct(line[i]));
		{
			printf("strreask\n");
			line[i] = line[i++];
		}
	}*/

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
	i=0;
	while (line[i]) //single out word
	{ 
		if (isspace(line[i]) != 0 && line[i] != line[i+1])
			line[i] = '\n';
		i++;
	}

	i=0;
	int a,b,c;
	a = 0;//k -> lines = 0;
	b = 0;//k -> words = 0;
	c = 0;//k -> characters = 0;
	
	while(line[i])
	{
		if (line[i] == '\n' )//&& line[i+1] == '\n')
			a++;//k.lines = k.lines + 1;//k -> lines = (*k).lines + 1;
		else if (line[i] == ' ' )//&& line[i+1] != ' ')
			b++;//k.words = k.words + 1;//k -> words = (*k).words + 1;
		//else
		if (line[i] != ' ' && line[i+1] != ' ')
			c++;//k.characters++; //= k.characters + 1;//k -> characters = (*k).characters + 1;//if(line[i] != '\n' || line[i] != ' ')
		
		i++;
//		printf("%d",i);
	}
	k.lines = a;
	k.words = b;
	k.characters = c-1;

	printf("Lines: %d\nWords: %d\nCharacters: %d\n",k.lines,k.words,k.characters);
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