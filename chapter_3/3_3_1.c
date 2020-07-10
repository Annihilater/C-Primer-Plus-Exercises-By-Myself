//
// Created by klause on 2020/6/18.
//

#include <stdio.h>

int main(void) {
    float tooBig = 3.4E38 * 100.0f;
    printf("%e\n", tooBig);
    return 0;
}
