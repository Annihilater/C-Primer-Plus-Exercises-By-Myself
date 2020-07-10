//
// Created by klause on 2020/6/22.
//
#include <stdio.h>

#define IN 0.0328084
#define FEET_TO_IN 12

int main(void) {
    double height, inches;
    int feets;
    printf("Enter a height in centimeters:");

    scanf("%lf", &height);
    feets = (int) (height * IN);//厘米转英尺
    inches = (height * IN - feets) * FEET_TO_IN;//厘米转英寸
    printf("%.1f cm = %d feet, %.1f inches.\n", height, feets, inches);

    while (height > 0) {
        printf("Enter a height in centimeters:(<= 0 to quit):");
        scanf("%lf", &height);
        if (height <= 0) break;
        feets = (int) (height * IN);//厘米转英尺
        inches = (height * IN - feets) * FEET_TO_IN;//厘米转英寸
        printf("%.1f cm = %d feet, %.1f inches.\n", height, feets, inches);
    }
    printf("bye");
    return 0;
}
