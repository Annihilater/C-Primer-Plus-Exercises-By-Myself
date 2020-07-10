//
// Created by klause on 2020/7/1.
//
#include <stdio.h>
#include "pe12-2a.h"


void set_mode(int mode) {
    m = mode;//将局部变量的值传递给全局变量
    if (mode != 0 && mode != 1) {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        m = 1;
    }
}

void get_info(void) {
    if (m == 0) {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
    if (m == 1) {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
}

void show_info(void) {
    if (m == 0)
        printf("Fuel consumption is %.2f liters per 100km.\n", fuel / (distance / 100));
    if (m == 1)
        printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuel);

}
