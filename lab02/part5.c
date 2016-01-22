#include <stdio.h>

/* ECE1120 - Lab 2 part 5
 * by Sebastian Velasquez-/Foubert.
 */

int main(void)
{
    double number = 3.4E307;
    printf("number is %e\n", number);
    number=number * 10000.0;
    printf("number multiplied by 10000 is %e\n", number);
    return 0;
}

/* The first 'printf' will show the number that is currently assigned to the variable 'number' (3.4E307).
Then we multiply by 1000 so the answer is 3.4E310. But that exceeds the available space that 'double' (64bit) is able to store.
'double' maximum limit is 1.7E308 any number higher or a number smaller to -1.7E308.
*/