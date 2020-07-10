//
// Created by klause on 2020/6/23.
//

#include <stdio.h>

int main(void) {
    int n;//项的个数
    double m, k, s1 = 0.0, s2 = 0.0, s3 = 0.0;
    printf("Please input n: ");
    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        m = 1.0 / (double) i;

        s1 += m;

        if ((i % 2) == 0) {
            k = -m;
        } else {
            k = m;
        }
        s2 += k;

        s3 = s1 + s2;
        printf("%+lf %+lf %+lf %+lf %+lf\n", m, s1, k, s2, s3);
    }
    return 0;
}
