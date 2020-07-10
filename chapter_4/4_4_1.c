//
// Created by klause on 2020/6/19.
//

#include <stdio.h>

int main(void) {
    char a = 'a'; // 97
    printf("ASCII: %d\n", a);
    printf("%hhu\n", a); // 字符转换为ascii码值，十进制表示
    printf("%hhx\n", a); // 字符转换为ascii码值，十六进制表示
    printf("%6.4hhd\n", a); // 字符转换为ascii码值，十进制表示，整数部分 6 位，小数部分 4 位
    printf("---------\n");

    long b = 97;
    printf("%jd\n", b);
    printf("%3ju\n", b);
    printf("%3jx\n", b);
    printf("---------\n");

    printf("%ld\n", b);
    printf("%3lu\n", b);
    printf("%3lx\n", b);
    printf("---------\n");

    long double c = 97;
    printf("%Lf\n", c);
    printf("%10.4Le\n", c);
    printf("---------\n");

    short d = 97;
    printf("%hu\n", d);
    printf("%hx\n", d);
    printf("%6.4hd\n", d);
    printf("%.4hd\n", d);
    printf("---------\n");

    double e = 97.345;
    double f = -97.345;
    printf("% 6.3f\n", e); // 空格表示：正数还是空格，负数显示负号，正数 6 位，小数 3 位
    printf("% 6.2f\n", f); // 空格表示：正数还是空格，负数显示负号，正数 6 位，小数 2 位
    printf("---------\n");

    int g = 97;
    printf("%#o\n", g); // 0141 = 1*16+4*8+1 = 97 八进制
    printf("%#x\n", g); // 0x61 = 6*16+1 = 97 十六进制
    printf("%#X\n", g); // 0x61 = 6*16+1 = 97 十六进制
    printf("---------\n");

    printf("hello\n\nworld");
    return 0;
}


