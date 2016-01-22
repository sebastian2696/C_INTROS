#include <stdio.h>

/* ECE1120 - Lab 2 part 4
 * by Sebastian Velasquez-Foubert
 */

int main(void)
{
    double a, b;
    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    printf("%f \n", a);
    return 0;
}

/*
Double allows the variable to be a 64bit number. The max number allowed is 2^63-1 
because you need a bit to store the sign. But, in order to add 1 you need to change the 21 number. But the computer can only store 19.
This makes the addition incorrect. That is why the end result is 0. Because the computer did not make the change by adding 1
*/