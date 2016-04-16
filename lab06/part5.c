// Part5 Sebastian Velasquez
#include <stdio.h>
#include <time.h>
// #include <float.h> 0.16

long int random(void);
// srandom(time(NULL));


int GAME(void)
{
    int dice, level = 1, Rand;
    while ( level != 1000)
    {
        if (level == 0)
        {
            return -1;
        }
        Rand = random();
        dice = (Rand % 6) +1;
        if (dice < 3)
        {
            level--;
        }
        else level++;
    }
    return 0;
}

int main (void)
{
    int Tries, Result, WIN=0, LOSE=0; 
    double probaW, probaF;
    for (Tries=0; Tries<10000; Tries++)
    {
        Result = GAME();
        if (Result == 0)
        {
            WIN++;
        }
        else LOSE++;
    }
    probaW = (double)WIN * 100 / 10000;
    probaF = 100 - probaW; 
    printf("On 10000 tries, %d were a Win, %d were a failure.\n Win Rate:%lf%%\n Lose Rate:%lf%%\n",WIN ,LOSE, probaW, probaF);
    return 0;
}
/* The program uses a function GAME to simulate a single playthrought. I use the function random() to simulate a DICE roll and mudulated between 1 and 6 using %6 + 1.
I used the win condition as well the lose condition to determine and outcome. You win if level is 1000 you lose if level = 0. 
I simulate indefinetly until the player either wins or loses (while (level != 1000) && if (level = 0)). If the player wins the function return 0 if he loses the function return -1.
In main. I simulate 10000 rolls using a for loop. Every time a win or losss is register a counter is added to the WIN or LOSE variable. 
After this, the program does simple math in order to obtain the percentage of sucess and failure (probaW, probaF). And to finish, a printf that prints the results (# loses/wins, as well as the percentage of Sucess and Failure).
I is possible that is the number of tries is */