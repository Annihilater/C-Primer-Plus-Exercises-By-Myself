//
// Created by klause on 2020/6/22.
//

#include <stdio.h>

int main(void) {
    int days, weeks, day;
    days = 1;
    while (days > 0) {
        printf("Please input days:");
        scanf("%d", &days);
        if (days <= 0) break;

        weeks = days / 7;
        day = days % 7;

        printf("%d days are %d weeks, %d days.\n", days, weeks, day);
    }

    return 0;
}
