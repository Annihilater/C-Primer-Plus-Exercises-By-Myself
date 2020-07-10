//
// Created by klause on 2020/6/24.
//

#include <stdio.h>

#define BOUNDARY_SINGLE 17850
#define BOUNDARY_FAMILY 23900
#define BOUNDARY_MARRIED 29750
#define BOUNDARY_DIVORCED 14875
#define RATE1 0.15
#define RATE2 0.28

void helper(double income, double boundary);

int main(void) {
    char t;
    double income, boundary = 0;

    printf("Please your tax type and income: \n");
    printf("1.single      2.family     \n3.married     4.divorced\n");
    printf("type is 1~4(q to quit): ");
    scanf("%s", &t);
    if (t == 'q') {
        return 0;
    }
    scanf("%lf", &income);

    while (t != 'q') {
        switch (t) {
            case 1: {
                boundary = BOUNDARY_SINGLE;
                break;
            }
            case 2: {
                boundary = BOUNDARY_FAMILY;
                break;
            }
            case 3: {
                boundary = BOUNDARY_MARRIED;
                break;
            }
            case 4: {
                boundary = BOUNDARY_DIVORCED;
                break;
            }
            default:
                break;
        }
        helper(income, boundary);
        printf("Please your tax type and income: \n");
        printf("1.single      2.family     \n3.married     4.divorced\n");
        printf("type is 1~4(q to quit): ");
        scanf("%s", &t);
        if (t == 'q') {
            break;
        }
        scanf("%lf", &income);
    }
    return 0;
}

void helper(double income, double boundary) {
    double tax;
    if (income < boundary) {
        tax = income * RATE1;
    } else {
        tax = boundary * RATE1 + (income - boundary) * RATE2;
    }
    printf("tax: $%.2f\n", tax);

}
