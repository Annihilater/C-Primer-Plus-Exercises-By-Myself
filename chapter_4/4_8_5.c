//
// Created by klause on 2020/6/19.
//

#include <stdio.h>

int main(void) {
    float speed, file, seconds;
    printf("Please enter the download speed:");
    scanf("%f", &speed);
    printf("Please enter the file:");
    scanf("%f", &file);
    seconds = (file * 8) / speed;
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", speed, file);
    printf("downloads in %.2f seconds.\n", seconds);
    return 0;
}
