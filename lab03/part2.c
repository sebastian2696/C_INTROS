// Part2 Sebastian Velasquez/

#include <stdio.h>

int main()
{
    int i=0;
    int j;
    char u;
    char* v[1000];
    printf("Enter number \n");
    while (u != 10)
    {
        scanf("%c",&u);
        //u = u-48;
        //printf("%d\n",u);
        switch(u){
             case 45: v[i++] = "negative";
             break;
             case 48: v[i++] = "zero"; 
             break;
             case 49: v[i++] = "one";
             break;
             case 50: v[i++] = "two";
             break;
             case 51: v[i++] = "three";
             break;
             case 52: v[i++] = "four";
             break;
             case 53: v[i++] = "five";
             break;
             case 54: v[i++] = "six";
             break;
             case 55: v[i++] = "seven"; 
             break;
             case 56: v[i++] = "eight";
             break;
             case 57: v[i++] = "nine";
             break;
        }
    }
    for(j=i-1;j>=0;j--)
    {
         printf("%s ",v[j]);
    }
    printf("\n");
    return 0; 
}