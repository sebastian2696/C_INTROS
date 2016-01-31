//part4 Sebastian Velasquez
#include <stdio.h>
 
int main()
{
   int x,y,r,s = 0;
   printf("Enter a number\n");
   scanf("%d",&x);
   y = x;
   while (y != 0)
   {
      r = y % 10;
      s = s + r;
      y = y / 10;
   }
 
   printf("The sum is %d = %d\n", x, s);
   return 0;
}

//It does the sum and then it puts a negative sign when a negative number is inputed