/* Copy standard input to standard output, one line at a time, using
 * the getline() library function.
 *
 * by Ahsen Uppal
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int process_line(char *line, size_t n)
{
	/* Q10: What do the fputs and fflush functions do?
	 * Q11: Why should we use them instead of printf or fprintf? */
	/* Q12: What does the value of n represent? */

	fputs(line, stdout);
	fflush(stdout);

	return 0;
}

int main(int argc, char *argv[])
{
	int exit_status = 0;
	FILE *fp;

	/* Q1: What values do argc and have when this program is run
	 * without any command-line parameters?
	 * Q2: What value do they have when run with a filename as
	 * an input argument?
	 */
	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");

		/* Q3: When is the condition !fp true, and when is it false?
		 * Q4: strerror() is called with the global variable
		 * errno that the C library maintains internally.
		 * What does strerror do?
		 */

		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
			/* Q5: What does the exit() library function do? */
			exit(1);
		}
	}


	size_t n = 0;
	char *lineptr = 0;

	/* Q6: What does a for(;;) loop do? */
	for (;;) {
		/* Q7: What is the difference between the types size_t
		 * and ssize_t ?
		 */
		ssize_t rc = getline(&lineptr, &n, fp);

		/* Q8: What does the getline function do? 
		 * Q9: What does it return in the normal case,
		 * upon EOF, and upon error?
		 */

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
