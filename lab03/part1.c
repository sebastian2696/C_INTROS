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
}

int main (void){
  
  int u,v;
  printf("Enter 2 numbers :\n");
  scanf("%d",&u);
  scanf("%d",&v);
  gcd(u,v);
  return 0;
}