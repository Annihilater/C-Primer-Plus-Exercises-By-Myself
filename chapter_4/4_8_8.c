//
// Created by klause on 2020/6/19.
//

#include <stdio.h>

#define GALLON_TO_LITER 3.785  // 1 加仑=3.785 升
#define MILE_TO_KM 1.609 // 1 英里=1.609 公里

int main(void) {
    float range, oil;
    // 以英里为单位读取旅行里程
    printf("Please input the range you traveled(in mile):\n");
    scanf("%f", &range);
    // 以加仑为单位读取消耗的汽油
    printf("Please input the oil your spend(in gallon):\n");
    scanf("%f", &oil);
    // 打印美国的耗油量
    printf("In USA, your oil wear is %.1f M/G.\n", range / oil);
    // 打印欧洲的耗油量
    printf("In Europe, your oil wear is %.1f L/100KM.\n", (oil * GALLON_TO_LITER) / (range * MILE_TO_KM));
    return 0;
}
