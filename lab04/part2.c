//Sebastian Velasquez Part2
 #include <stdio.h>

void print_int(char v[], int n)
{
    int i,c;
    for (i=0; i < n; ++i)
    {
        c = v[i];
        putchar(c);
    }   
    putchar('\n');  
}

int main()
{
   char v[1000], print;
   int n = 0;
   
   /*while ((c = getchar()) != EOF) {
        c = getchar();
        v[n] = c;
        ++n;
    }*/
    printf("Enter a number:\n");
    while (print != 10)
    {
        scanf("%c",&print);
        //printf("%d",c);
        v[n] = print;
        ++n;
    }
//    x= v[n];
    print_int(v, n);
    return 0;
}  


