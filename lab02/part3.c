#include <stdio.h>

//part3 Sebastian Velasquez

int main()
{
    char x;
    x = 'C';
    printf("The Character is %c\nThe Variable is %d\n",x,x);
    x=x+1;
    printf("(Updated)\nThe Character is %c\nThe Variable is %d\n",x,x);
    return 0;
}    
    
/*In ASCII, the letter C (Caps) is represented by the number 67.
This corresponds to the first statement. But if you add 1 to 'C',
the the variable 68 becomes 68+1=69. Which in ASCII corresponds to the letter 'D'.
This explains the second output
*/