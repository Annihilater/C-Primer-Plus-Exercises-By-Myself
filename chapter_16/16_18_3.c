//
// Created by klause on 2020/7/10.
//

#include <stdio.h>
#include <math.h>

struct polar_coordinates {
    double r;
    double angle;
};
struct cartesian_coordinates {
    double x;
    double y;
};

typedef struct polar_coordinates polar;
typedef struct cartesian_coordinates cartesian;

int main(void) {
    polar co1;
    cartesian co2;

    printf("Please input polar_coordinates's len and angle:\n");
    scanf("%lf %lf", &co1.r, &co1.angle);

    co2.x = co1.r * cos(co1.angle);
    co2.y = co1.r * sin(co1.angle);

    printf("x = %lf  y = %lf", co2.x, co2.y);

    return 0;
}
