#include <stdio.h>

// Part 2 Sebastian Velasquez
int main()
{
    long int x,y,a,b,c,d;
    double e;
    char f;
    f='%';
    x=123456789;
    y=1000;
    a=x+y; 
    b=x*y;
    c=x/y;
    d=x%y;
    e=(double)x/y;
    printf("%ld + %ld = %ld\n%ld * %ld = %ld\n%ld // %ld = %ld\n%ld %c %ld = %ld\n%ld / %ld = %f\n",x,y,a,x,y,b,x,y,c,x,f,y,d,x,y,e);
    return 0;
}

/* 
The sum is as it should be 123456789 + 1000 = 123457789
The multiplication by 1000 would add 3 zeros to the answer: 123456789 x 1000 = 123456789000
For the simple division: since c is an integer variable. The result showned will be just the interger part which
in this case is 123456.
The rest of simple division between 123456789 and 1000 is just 789.8
the divison with decimal number by 1000 will move the coma by 3 places to the left: 123456789/1000 = 123456.789
*/

