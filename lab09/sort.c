//by Sebastian Foubert

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

void merge(char *src[], int left, int mid, int right, char *dst[])
{
	int i = left, j = mid, k = left;

	while (i < mid && j < right)
	{
		/* Both subarrays are not empty */
		if (strcmp(src[i], src[j]) < 0) {
			dst[k++] = src[i++];
		}
		else {
			dst[k++] = src[j++];
		}
	}

	while (j < right) {
		/* lower subarray is empty */
		dst[k++] = src[j++];
	}

	while (i < mid ) {
		/* upper subarray is empty */
		dst[k++] = src[i++];
	}
}

#define MIN(a, b) (a < b ? a : b)

/*
 *	A is a list of char*s (double pointer)
 *  n is how many char*s (int)
 */
void *mergesort(char *A[], unsigned int n)
{
	if (n < 2) {
		return A;
	}

	char **src = A;
	char **dst = calloc(n, sizeof(char *));

	if (!dst) {
		return NULL;
	}

	/* Bottom up mergesort */
	int w, i;
	for (w=1; w<n; w*=2) {

		for (i=0; i<n; i+=2*w) {
			int left = i;
			int mid = MIN(i + w, n);
			int right = MIN(i + 2*w, n);

			merge(src, left, mid, right, dst);
		}


		/* Swap the input and output arrays for the next round. */
		char **tmp = src;
		src = dst;
		dst = tmp;
	}

	/* Sorted data is now in src */
	if (src != A) {
		memcpy(A, src, n * sizeof(char));
		free(src);
	}
	else {
		free(dst);
	}
	for ( i = 0 ; i < n ; i++)
	{
		fputs(A[i], stdout);
		fflush(stdout);
		printf("\n");
	}	
	return A;
}

int main(int argc, char *argv[])
{
	char** list = malloc(sizeof(char *)* 10000000);	
	int index = 0;
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
			
			list[index] = malloc(sizeof(char *)*n);
			strcpy(list[index],lineptr);
		
			index++;
		}
		free(lineptr);
		lineptr = 0;
		n = 0;
	}
	
	
	
	mergesort(list,index);
	
	if (ferror(fp)) {
		fprintf(stderr, "Error reading %s: %s\n", argv[1], strerror(errno));
		exit_status = 1;
	}
	

	fclose(fp);
	exit(exit_status);
	return 0;
}