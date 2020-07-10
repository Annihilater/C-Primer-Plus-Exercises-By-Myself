//
// Created by klause on 2020/7/10.
//

#include <stdio.h>
#include <limits.h>

#define CLEARINPUT while (getchar() != '\n') continue

unsigned int rotate_l(unsigned int value, int n);

const unsigned int BITS = sizeof(unsigned int) * CHAR_BIT;
const unsigned int LBITMASK = 1 << (BITS - 1);

int main(void) {
    // test rotate_l()

    unsigned int value, rotated;
    int n;

    printf("Enter a non-negative integer value: ");
    while (scanf("%u", &value) == 1) {
        printf("Enter a number of positions to rotate: ");
        while (scanf("%d", &n) == 1) {
            puts("Before rotation:");
            for (int i = 0; i < BITS; i++) {
                if ((value << i) & LBITMASK)
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
            printf("After rotation by %d positions:\n", n);
            rotated = rotate_l(value, n);
            for (int i = 0; i < BITS; i++) {
                if ((rotated << (unsigned int) i) & LBITMASK)
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
            printf("Enter a number of positions to rotate: ");
        }
        CLEARINPUT;
        printf("\nEnter a non-negative integer value: ");
    }

    puts("Bye.");
    return 0;

}

unsigned int rotate_l(unsigned int value, int n) {
    // rotate the bits in value n postitions to the left

    int leftbit;

    for (int i = 0; i < n; i++) {
        leftbit = value & LBITMASK;
        value <<= 1;
        if (leftbit)
            value |= 1;
    }

    return value;
}
