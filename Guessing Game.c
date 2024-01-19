/*
###############################################

█▀▀ █░█ █▀▀ █▀ █▀ █ █▄░█ █▀▀
█▄█ █▄█ ██▄ ▄█ ▄█ █ █░▀█ █▄█

█▀▀ ▄▀█ █▀▄▀█ █▀▀
█▄█ █▀█ █░▀░█ ██▄

© Author : Pankaj Rudra
###############################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //building a guessing game (updated)
    int luckynum, played = 0, win_cnt=0, lose_cnt=0;
    char again = 'y';

    int level = 1;  // Current Level
    int (*LVLpassed) [2] = calloc(101, sizeof(*LVLpassed)); // Total Game level records (passed or not and reachpoint)

    long long int pointsTmp=0; // Using for Point initialization of levels
    for(int i=1; i<101; i++){
        pointsTmp += 50;
        LVLpassed[i][1] = pointsTmp;
    }

    long long int earnedPoints = 0;  // Total earned points

    int minNum = 0;  // Random starting number
    int maxNum = 10;  // Random total number

    while (again == 'y' || again == 'Y')
    {
        if(again == 'y' || again == 'Y')
        {
            if (played > 0) system("cls");
            printf("\t\t\t==========================\n\t\t\tWelcome to GUESSING GAME!! - TRY YOUR LUCK\n\t\t\t==========================\n\n");
            if (played > 0) printf("\n\n");  // Styling text after 1 guess
        }

        srand(time(NULL));
        luckynum = (rand() % maxNum) + minNum; // The lucky number randomized (minNum to maxNum)
        int guesslimit = 5;     // Limit guessing count
        int gnum=11;           // User guess number
        int guesscount = 0;     // How many guess performed

        printf("\t\t\tYou have %d chances to guess a number among %d to %d.\n\t\t\tIf you enter the correct guess You Win!\n", guesslimit, minNum, maxNum-1);
        printf("\t\t\t------------------------------------------------------------\n");

        // Level Up message
        if((earnedPoints>=LVLpassed[level][1] && LVLpassed[level][0]!=1)
           || (earnedPoints>=LVLpassed[level][1] && LVLpassed[level][0]!=1)
           ){
            printf("\n\t\t\t\t\t////////////////////////////////////\n\t\t\t\t\t//   Congratulations! LEVEL UP!   //\n\t\t\t\t\t////////////////////////////////////\n");
            LVLpassed[level][0] = 1;
            level++;
        }

        // Current point and level message
        printf("\n\t\t\tEarned Points: %lld\t\t\t\tLevel : %d\n",earnedPoints,level);

        /// Asking guess from user
        while (gnum != luckynum && guesslimit != guesscount)
        {
            if (guesscount < guesslimit)
            {
                printf("\n\tEnter a guess : ");
                scanf("%d", &gnum);
                guesscount++;
                if (gnum != luckynum) printf("\t\t\tfailed!\n");
                else printf("\t\t\tnice!\n");
            }
        }

        /// Print message for user loses or wins a game
        if (gnum != luckynum)
        {
            lose_cnt++;
            printf("\n\n\t\t\t\txxxxxxxxxxxxxxxxxxxx\n\t\t\t\tx  Opps! You Lose  x\t%s\n\t\t\t\txxxxxxxxxxxxxxxxxxxx\n\n\t\t\t\tThe lucky number was %d.\n",((earnedPoints<=0)?"No progress!":"-5 points") , luckynum);
            if(earnedPoints>=5) earnedPoints-=5;
        }
        else
        {
            win_cnt++;
            if (guesscount == 1)
            {
                printf("\n\n\t\t\tExtraordinary !!! +20 points\n");
                earnedPoints+=20;
            }
            else if (guesscount == 2)
            {
                printf("\n\n\t\t\tExcellent !!! +15 points\n");
                earnedPoints+=15;
            }
            else if (guesscount == 3)
            {
                printf("\n\n\t\t\tWonderful !!! +10 points\n");
                earnedPoints+=10;
            }
            else {
                printf("\n\n\t\t\tScored +5 points\n");
                earnedPoints+=5;
            }
            {(guesscount>1)?printf("\n\n\t\t\t*******************************\n\t\t\t* You WIN the Game in %d moves! *\n\t\t\t*******************************\n", guesscount)
                           :printf("\n\n\t\t\t*******************************\n\t\t\t* You WIN the Game in %d move! *\n\t\t\t*******************************\n", guesscount);
            }
        }
        guesscount = 0;
        gnum = 11; // value initialized as invalid
        played++;
        printf("\n\tPLAY AGAIN? ENTER 'y' TO CONTINUE : ");
        scanf(" %c", &again);
    }

    // Game session results
    printf("\n\n\n\n\n\n\t\t\t\t\t G A M E  O V E R !\n");
    printf("\t\t\t----------------------------------------------------\n");
    printf("\n\t\t\t[i]- Played\t\t: session continued %d times!\n", played);
    printf("\t\t\t[i]- Win\t\t: %d times!\n", win_cnt);
    printf("\t\t\t[i]- Lose\t\t: %d times!\n", lose_cnt);
    printf("\t\t\t[i]- Levels upto\t: %d (%lld points)\n", level, earnedPoints);
    printf("\t\t\t[i]- Win Rate\t\t: %.2f%%\n\n\n\n\n\n", (win_cnt*100.0)/played);

    getchar();
    getchar();

    return 0;
}
