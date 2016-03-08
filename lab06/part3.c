// Part3 Sebastian Velasquez
#include <stdio.h>

struct time { 
        int hour; /* 0 to 23 */
        int min;  /* 0 to 59 */
        int sec;  /* 0 to 59 */
};

int error (struct time t_1, struct time t_2)
{
    if (t_1.hour < 0 || t_2.hour < 0 || t_1.hour > 23 || t_2.hour > 23 )
    {
        return -1;
    }
    if (t_1.min < 0 || t_2.min < 0|| t_1.min > 59 || t_2.min > 59 )
    {
        return -2;
    }
    if (t_1.sec < 0 || t_2.sec < 0|| t_1.sec > 59 || t_2.sec > 59 )
    {
        return -3;
    }
    return 0;
}

void error_2 (int e)
{
   switch (e)
   {
       case -1: printf ("Invalid Hour Input. Please Restart") ;
       break;
       case -2: printf ("Invalid Minute Input. Please Restart") ;
       break;
       case -3: printf ("Invalid Second Input. Please Restart ") ;
       break;
   }
}

void Difference(struct time t_1, struct time t_2, struct time *t_t)
{
    if(t_1.hour > t_2.hour)
    {
        t_2.hour += 24;

    } 
   
    
    if (t_1.min > t_2.min)
    {
        t_2.min += 60;
        t_1.hour ++;
 
    }
   
    
    if (t_1.sec > t_2.sec)
    {
        t_2.sec += 60;
        t_1.min ++;
    }
    
    t_t -> hour = t_2.hour - t_1.hour;
    t_t -> min = t_2.min - t_1.min;
    t_t -> sec = t_2.sec - t_1.sec;
}



int main (void)
{
    int e;
    struct time t_1, t_2, t_t;
    printf("In 24H format.\nEnter the start time \n");
    printf("(hours, minutes and seconds): ");
    scanf("%d%d%d",&t_1.hour,&t_1.min,&t_1.sec);
    printf("Enter stop time \n");
    printf("(hours, minutes and seconds): ");
    scanf("%d%d%d",&t_2.hour,&t_2.min,&t_2.sec);
    
    e = error(t_1,t_2);
    error_2 (e);
    
    if (e != 0)
    {
        return -1;
    }
    
    Difference(t_1,t_2,&t_t);
    printf("\nThe time difference between %d:%d:%d",t_1.hour,t_1.min,t_1.sec);
    printf(" and %d:%d:%d ",t_2.hour,t_2.min,t_2.sec);
    printf("is %d:%d:%d\n",t_t.hour, t_t.min, t_t.sec);
    return 0;
}
 
