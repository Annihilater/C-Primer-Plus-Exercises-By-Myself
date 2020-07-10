//
// Created by klause on 2020/7/1.
//

#include <stdio.h>
#include <stdlib.h>

#define START 1
#define END 10
#define SIZE 1000
int ar[SIZE];

void show(void);

void analyse(const int ar[]);

void gen_array(void);

int main(void) {
    for (int i = 0; i < 10; ++i) {
        gen_array();
        analyse(ar);
    }
    return 0;
}

//打印数组
void show(void) {
    printf("Your array list is:\n");
    for (int j = 1; j < SIZE + 1; ++j) {
        printf("%2d ", ar[j - 1]);
        if ((j % 25) == 0)
            printf("\n");
    }
}

//生成随机数组
void gen_array(void) {
    for (int i = 0; i < SIZE; ++i) {
        ar[i] = rand() % 10 + 1;
    }
}

//统计数组数字出现的次数
void analyse(const int ar[]) {
    int count_ar[END - START + 1];

    //统计数组初始化
    for (int k = 0; k < END - START + 1; ++k) {
        count_ar[k] = 0;
    }

    printf("统计数字出现的次数:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < END - START + 1; ++j) {
            if (ar[i] == (START + j))
                count_ar[j]++;
        }
    }

    //打印统计数组
    for (int l = 0; l < END - START + 1; ++l) {
        printf("数字 %2d : %4d 次\n", START + l, count_ar[l]);
    }
}

