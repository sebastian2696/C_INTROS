#include <stdio.h>

/* Hello world 
 * by Sebastian Elias Velasquez-Foubert
 */

int main(int argc, char *argv[])
{
	printf("Hello world!\n");

	/* This section computes a sum. */
	int x, y, z;
	x = 10;
	y = 20;
	z = x + y;
	printf("x is %d, y is %d, and z is %d\n", x, y, z);
	/* This sections computes the volume of a box.*/
	int q;
	x = 11;
	y = 14;
	z = 7;
	q = x*y*z;
	printf("The height is %d, the width is %d, the depth is %d and the volume of the box is %d\n", x, z, y, q);
	return 0;
}