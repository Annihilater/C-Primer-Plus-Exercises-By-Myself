//
// Created by klause on 2020/7/1.
//
#include <stdio.h>
#include "pe12-3a.h"


void set_mode(int *m) {
    if (*m != 0 && *m != 1) {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        *m = 1;
    }
}

void get_info(double *distance, double *fuel, int mode) {
    if (mode == 0) {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", fuel);
    }
    if (mode == 1) {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", fuel);
    }
}

void show_info(double distance, double fuel, int mode) {
    if (mode == 0)
        printf("Fuel consumption is %.2f liters per 100km.\n", fuel / (distance / 100));
    if (mode == 1)
        printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuel);
}
