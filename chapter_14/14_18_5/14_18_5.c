//
// Created by klause on 2020/7/7.
//

//交互输入每个学生的分数太烦了，就不做交互输入了，直接初始化分数
#include <stdio.h>

#define CSIZE 4

struct name {
    char first[20];
    char last[20];
};

struct student {
    struct name sna;
    float grade[3];
    float avg;
};

void calculate_avg(struct student ar[CSIZE]);

void show(struct student ar[CSIZE]);

void total_avg(struct student ar[CSIZE]);

int main(void) {
    struct student ar[CSIZE] = {
            {"Claude",  "Johnny",     55, 86, 98,},
            {"Bblythe", "Harry",      87, 83, 98,},
            {"Eudora",  "Daniel",     38, 49, 65,},
            {"Carter",  "Springhall", 67, 33, 94,},
    };
    show(ar);

    calculate_avg(ar);

    total_avg(ar);

    return 0;
}

//计算每个结构的平均分
void calculate_avg(struct student ar[CSIZE]) {
    float total;
    printf("Calculate every student's avg.\n");
    for (int i = 0; i < CSIZE; ++i) {
        total = 0;
        total += ar[i].grade[0];
        total += ar[i].grade[1];
        total += ar[i].grade[2];
        ar[i].avg = total / 3;
    }
    show(ar);
}

//打印每个结构的信息
void show(struct student ar[CSIZE]) {
    printf("Print student information:\n");
    printf("%10s %10s %3s %3s %3s %4s\n", "first", "last", "grade1", "grade2", " grade3", "avg");
    for (int i = 0; i < CSIZE; ++i) {
        printf("%10s %10s %6.2f %6.2f %6.2f %6.2f\n", ar[i].sna.first, ar[i].sna.last, ar[i].grade[0], ar[i].grade[1],
               ar[i].grade[2], ar[i].avg);
    }
}

//计算班级平均分
void total_avg(struct student ar[CSIZE]) {
    float total = 0, class_avg;
    for (int i = 0; i < CSIZE; ++i) {
        total += ar[i].grade[0];
        total += ar[i].grade[1];
        total += ar[i].grade[2];
    }

    class_avg = total / (CSIZE * 3);
    printf("Avg of Class is %.2f.", class_avg);
}
