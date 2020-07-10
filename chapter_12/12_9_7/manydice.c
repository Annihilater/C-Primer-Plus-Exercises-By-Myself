//
// Created by klause on 2020/7/1.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void) {
    int dice, roll;//dice 骰子个数
    int sides;//骰子面数
    int status;
    int sets;

    srand((unsigned int) time(0));//随机种子
    printf("Enter the number of sets; enter q to stop: ");

    //读取试验次数、骰子个数、骰子面数
    while (scanf("%d", &sets) == 1 && sets > 0) {
        if (sets == 'q')
            return 0;

        printf("How many sides and how many dice? ");
        if ((status = scanf("%d %d", &sides, &dice)) != 2) {
            if (status == EOF)
                break;
            else {
                printf("You should have entered two integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;
                printf("How many sides and how many dice? ");
                continue;
            }
        }

        for (int i = 0; i < sets; ++i) {
            roll = roll_n_dice(dice, sides);//摇骰子
            printf("%d ", roll);
        }

        printf("\nHow many sets? Enter q to stop.\n");
    }
    printf("The rollem() function was called %d times.\n", roll_count);
    printf("GOOD FORTUNE TO YOU!\n");

    return 0;
}
