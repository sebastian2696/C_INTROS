// Part1 Sebastian Velasquez-Foubert

#include <stdio.h>

void gcd (int u, int v)
{
  int temp;
  
  printf ("The gcd of %i and %i is ", u , v);
  while (v != 0){
    temp = u % v;
    u = v;
    v = temp;
  }
  
  printf ("%i\n", u);
  printf ("3: u= %i, v= %i\n",u,v);
}

int main (void){
  
  int u,v;
  printf("Enter 2 numbers :\n");
  scanf("%d",&u);
  scanf("%d",&v);
  printf ("1: u= %i, v= %i\n",u,v);
  gcd(u,v);
  printf ("2: u= %i, v= %i\n",u,v);
  return 0;
}

/* The GCD function changes the value of the variables U and V as it runs. U becomes the GCD variable and V is the rest of Euclidean division, in other words the remainder.
Before the function U and V have the same value assigned by the user. After the program runs U and V still have the same value assigned by the user because the gcd program does not return a value for U and V in terms of the mainn program. 
This explains the fixed value of U and V in main()*/

