//
// Created by klause on 2020/6/24.
//

#include <stdio.h>

#define PRICE_A 2.05
#define PRICE_B 1.15
#define PRICE_C 1.09

int main(void) {
    char t;
    double a_w = 0, b_w = 0, c_w = 0, sum_a_w = 0, sum_b_w = 0, sum_c_w = 0, total = 0, sum_w = 0;

    printf("Please input type or p to pay or q to quit:");
    scanf("%c", &t);
    while (1) {
        if (t == 'p') {//按 p 结算
            break;
        } else if (t == 'q') {// 按 q 退出
            return 0;
        }
        switch (t) {
            case 'a': {
                printf("Please input a weights: ");
                scanf("%lf", &a_w);
                sum_a_w += a_w;
                break;
            }
            case 'b': {
                printf("Please input b weights: ");
                scanf("%lf", &b_w);
                sum_b_w += b_w;
                break;
            }
            case 'c': {
                printf("Please input c weights: ");
                scanf("%lf", &c_w);
                sum_c_w += c_w;
                break;
            }
            default: {
                break;
            }
        }
        scanf("%c", &t);
        printf("Input next type or p to pay:\n");
    }

    printf("\n");
    sum_w = sum_a_w + sum_b_w + sum_c_w;
    total = sum_a_w * PRICE_A + sum_b_w * PRICE_B + sum_c_w * PRICE_C;

    if (total >= 100) {//满 100 美元 5% 优惠
        total = total * (1 - 0.05);
    }

    if (sum_w <= 5) {//少于 5 磅时，加收 6.5 美元/磅的运费和包装费
        total += 6.5 * sum_w;
    } else if (sum_w <= 20) {//5 磅 ~ 20 磅，加收 14 美元的运费和包装费
        total += 14;
    } else {
        total = total + 14 + (sum_w - 20) * 0.5;
    }

    printf("a: $%.2lf/LB %.2lfLB $%.2lf\n", PRICE_A, a_w, a_w * PRICE_A);
    printf("b: $%.2lf/LB %.2lfLB $%.2lf\n", PRICE_B, b_w, b_w * PRICE_B);
    printf("c: $%.2lf/LB %.2lfLB $%.2lf\n", PRICE_C, c_w, c_w * PRICE_C);
    printf("total: $%.2lf sum weights: %.2lfLB", total, sum_w);
    return 0;
}
