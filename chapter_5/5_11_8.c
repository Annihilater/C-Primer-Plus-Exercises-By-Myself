//
// Created by klause on 2020/6/22.
//

#include <stdio.h>

int main(void) {
    int first_operand, second_operand, result;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &second_operand);//输入除数

    printf("Now enter the first operand: ");
    scanf("%d", &first_operand);//输入被除数
    result = first_operand % second_operand;
    printf("%d %% %d is %d\n", first_operand, second_operand, result);

    while (first_operand > 0) {
        printf("Enter next number for first operand (<= 0 to quit): ");
        scanf("%d", &first_operand);//输入被除数
        if (first_operand <= 0) break;//当输入的除数小于等于 0 时，跳出循环
        result = first_operand % second_operand;
        printf("%d %% %d is %d\n", first_operand, second_operand, result);//打印结果
    }
    printf("Done");
    return 0;
}
