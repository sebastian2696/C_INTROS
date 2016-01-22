#include <stdio.h>

// Part 1: Sebastian Velasquez
int main()
{
    int x,y,a,b,c,d;
    float e;
    char f;
    f='%';
    x=35;
    y=14;
    a=x+y; 
    b=x*y;
    c=x/y;
    d=x%y;
    e=(float)x/y;
    printf("%d + %d = %d\n%d * %d = %d\n%d // %d = %d\n%d %c %d = %d\n%d / %d = %f\n",x,y,a,x,y,b,x,y,c,x,f,y,d,x,y,e);
    return 0;
}

/* It is necessary to create a variable that will display the decimal numbers, hence "float e".
Since x is an integer variable it is necessary to change the type to floater in order to have the division appear
with decimal numbers. the division would be 35.000000/14 = 2.500000 
*/ 