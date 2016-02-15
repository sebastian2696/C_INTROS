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
<<<<<<< HEAD
   
   /*while ((c = getchar()) != EOF) {
        c = getchar();
        v[n] = c;
        ++n;
    }*/
=======
>>>>>>> 5eeb65117093c55a1ec074faf9e9369457e97d7c
    printf("Enter a number:\n");
    while (print != 10)
    {
        scanf("%c",&print);
        v[n] = print;
        ++n;
    }
<<<<<<< HEAD
//    x= v[n];
    print_int(v, n);
    return 0;
}  


=======
    print_int(v, n);
    return 0;
}  
>>>>>>> 5eeb65117093c55a1ec074faf9e9369457e97d7c
