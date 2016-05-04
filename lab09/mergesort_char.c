#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int debug = 0;

/* Quick and dirty mergesort implementation for sorting integers.
 * By Ahsen Uppal
 */

void printarray(const char *msg, const char *A, int n)//
{
	int i;
	printf("[ ");
	for (i=0; i<n; i++) {
		printf("%c ", A[i]);
	}
	printf("]\n");
}

void merge(const char *src, int left, int mid, int right, char *dst)//
{
	int i = left, j = mid, k = left;

	while (i < mid && j < right)//?
	{
		/* Both subarrays are not empty */
		if (strcmp(src+i,src+j) <= 0){//src[i] < src[j] ) {
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

//#define MIN(a,b) (strcmp(a,b) ?
#define MIN(a, b) (a < b ? a : b)

/*int MIN (int a, int b, char *src){
	/*if (strcmp(src+a,src+b) <= 0){
		return a;
	}
	else return b;
	return strcmp((src + a), (src + b)) <= 0;
}
*/

char *mergesort(char *A, unsigned int n)//int 
{
	if (n < 2) {
		return A;
	}

	char *src = A;
	char *dst = calloc(n, sizeof(char));//int));

	if (!dst) {
		return NULL;
	}

	/* Bottom up mergesort */
	int w, i;
	for (w=1; w<n; w*=2) {
		if (debug) {
			printarray("src = ", src, n);
		}

		for (i=0; i<n; i+=2*w) {
			int left = i;
			int mid = MIN(i + w, n);//, src);
			int right = MIN(i + 2*w, n);//,src);

			if (debug) {
				printf("w = %d merge i = %d to %d and %d to %d into %d\n", w, left, mid, mid, right, left);
			}

			merge(src, left, mid, right, dst);
		}

		if (debug) {
			printarray("dst = ", dst, n);
		}

		/* Swap the input and output arrays for the next round. */
		char *tmp = src;
		src = dst;
		dst = tmp;
	}

	/* Sorted data is now in src */
/*	if (src != A) {
		memcpy(A, src, n * sizeof(char));//int));
		free(src);
	}
	else {
		free(dst);
	}*/

	return A;
}

int test_mergesort_basic()
{
	char A[] = "magwas";
	printf("%c",A[2]);
	int N = sizeof(A) / sizeof(A[0]);
	char *c = mergesort(A, N);

	int i;
	for (i=0; i<N; i++) {
		printf("C[%d] = %d\n", i, c[i]);
	}

	return 0;
}

int test_mergesort_file(const char *fname)
{
	int rc = 0;
	FILE *fp = fopen(fname, "r");

	if (!fp) {
		perror("fopen");
		return 1;
	}

	int N = 1, cnt = 0, j;

	char *A = realloc(NULL, N * sizeof(char));//int));

	while (!feof(fp) && !ferror(fp)) {
		if (fscanf(fp, "%c", &A[cnt]) == 1) {
			cnt++;
		}

		if (cnt == N) {
			N *= 2;

			char *new_A = realloc(A, N * sizeof(char));//int));

			if (!new_A) {
				perror("realloc");
				rc = 1;
				goto out;
			}

			A = new_A;
		}
	}

	int i;
	mergesort(A, cnt);

	for (i=0; i<cnt; i++) {
		printf("%c\n", A[i]);
	}

	for (j=1; j<cnt; j++) {
		if (A[j] < A[j-1]) {
			fprintf(stdout, "Bad order found\n");
			rc = 1;
		}
	}

out:
	free(A);
	fclose(fp);
	return rc;
}

int main(int argc, char *argv[])
{
	int rc;

	if (argc > 2) {
		debug = strtol(argv[2], NULL, 10);
	}

	if (argc > 1) {
		rc = test_mergesort_file(argv[1]);
	}
	else {
		rc = test_mergesort_basic();
	}

	return rc;
}