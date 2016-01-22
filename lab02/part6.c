#include <stdio.h>

/* ECE1120 - Lab 2 part 6
 * by Sebastian Velasquez-Foubert.
 */

int main(void)
{
	int x, y, z;
	char c;

	printf("enter first number:\n");
	scanf("%d", &x);

	printf("enter second number:\n");
	scanf("%d", &y);

	printf("enter an operator:\n");
	scanf("\n%c", &c);

	if (c == '+') {
		z = x + y;
		printf("%d %c %d is %d\n",x,c,y,z);
	}
	else if (c == '*') {
		z = x * y;
		printf("%d %c %d is %d\n",x,c,y,z);	
	}
	else if (c == '%') {
		z = x % y;
		printf("%d %c %d is %d\n",x,c,y,z);
	}
	else if (c == '-') {
		z = x - y;
		printf("%d %c %d is %d\n",x,c,y,z);
	}
	else if (c == '/') {
		z = x / y;
		printf("%d %c %d is %d\n",x,c,y,z);
	}
	else {
		z = 0;
		printf("Unknown operator %c\n%d %c %d is %d\n",c,x,c,y,z);
	}
	return 0;
}

/*Since x, y are defined as integers, if a non-integer is inputed, the program automatically 
assignes a value of 0 to both x and y. It then shows the character that the user choosed. After that it analises 
the character and compares to @ and &.
*/