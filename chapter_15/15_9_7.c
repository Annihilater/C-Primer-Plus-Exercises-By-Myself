//
// Created by klause on 2020/7/9.
//


/*
 * 第七题
 * 改用 unsigned long 来存储字体信息，依据第六题的解答，改下类型就可以运行，好像没什么难度
 * 全局将 unsigned int 替换为 unsigned long 之后程序照样运行
 *
 * 第六题
 * 本题同样采用联合的方式来初始化 unsigned long 型来达到初始化设置的目的
 * 将位字段结构与 unsigned long 类型放到同一个联合类型，通过初始化位字段，来达到初始化 unsigned long
 * 因为具体的数据是为二进制的位，如果要初始化 unsigned long 就需要将每个字段对应的二进制写出来
 * 例如: 1111 0111 1111 0011 1111, 从右往左数
 * 1-8   位: 0011 1111 表示 63(十进制), 表示 id 是 63
 * 9-15  位: 0111 1111 表示 127(十进制), 表示 size 是 127
 * 16-17 位: 对齐方式 10 表示 2(十进制), 根据本文件中定义的 define 2 表示 RIGHT
 * 18    位: 是否加粗 1 表示 true (真), 是加粗
 * 19    位: 是否斜体 1 表示 true (真), 是斜体
 * 20    位: 是否下划线 1 表示 true (真), 是下划线
 * 这是逆向的想法，要初始化的话，得先写出每个功能位的二进制，再将他们按照顺序(也就是位字段的顺序，可以自定义)
 * 拼接起来, 得到初始化的二进制 unsigned long, 再将二进制转换成十进制
 * 程序中的实际 unsigned long 变量再用十进制初始化
 * 由上过程可知，还是位字段的方式来的方便
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TMP_SIZE sizeof(int)*8

#define LEFT 1
#define RIGHT 2
#define CENTER 0

/*
 * 掩码: 按位方法中用到的符号常量
 * 掩码设计:
 * a 表示对齐方式 alignment
 * b 表示加粗 bold
 * i 表示斜体 italic
 * u 表示下划线 underline
 * 	u iba    size       id     MASK
	                 1111 1111 0xff
	       0111 1111 0000 0000 0x7f00
	     0 1000 0000 0000 0000 0x8000
	     1 0000 0000 0000 0000 0x10000
	     1 1000 0000 0000 0000 0x18000
	    10 0000 0000 0000 0000 0x20000
	   100 0000 0000 0000 0000 0x40000
      1000 0000 0000 0000 0000 0x80000
 * 另外有一点很重要: 16 进制的写法是 零加小写的字母X(不是大写字母 O, 之前写错了一直报错)
 */
#define ID 0xff                     //前 8 位
#define SIZE 0x7f00                 //第 9-15 位
#define ALIGNMENT_LEFT 0x8000       //第 16-17 位 01
#define ALIGNMENT_RIGHT 0x10000     //第 16-17 位 10
#define ALIGNMENT_CENTER 0x18000    //第 16-17 位 11
#define BOLD 0x20000                //第 19 位
#define ITALIC 0x40000              //第 20 位
#define UNDERLINE 0x80000           //第 21 位

/*
 * 这里位字段设置好之后不要随便改动
 * 位字段一改，上面定义的掩码就要改，比较麻烦
 */
struct font {
    unsigned long id: 8;
    unsigned long size: 7;
    unsigned long alignment: 2;
    bool bold: 1;
    bool italic: 1;
    bool underline: 1;
};

union Views {
    struct font st_view;
    unsigned long us_view;
};

void change_font(unsigned long *ps);

void change_size(unsigned long *ps);

void change_alignment(unsigned long *ps);

void change_bold(unsigned long *ps);

void change_italic(unsigned long *ps);

void change_underline(unsigned long *ps);

void show_settings(unsigned long us);

int show_id(unsigned long n);

int show_size(unsigned long n);

char *show_alignment(unsigned long n);

char *show_bold(unsigned long n);

char *show_italic(unsigned long n);

char *show_underline(unsigned long n);

char *itobs(int n, char *ps);

void print_bs(char *st);

int main(void) {
    union Views my_font = {{63, 127, RIGHT, true, true, true}};
    bool is_quit = false;
    char ch;
    unsigned long *ps;

    ps = &my_font.us_view;

    show_settings(my_font.us_view);
    while (1) {
        while (1) {
            while (scanf("%c", &ch) != 1) {
                while (getchar() != '\n') continue;
                show_settings(*ps);
            }
            if (ch == '\n') continue;

            if (strchr("fsabiuq", ch) != NULL) break;//各个选项开头首字母
            show_settings(*ps);
        }

        switch (ch) {
            case 'f': {
                change_font(ps);
                break;
            }
            case 's': {
                change_size(ps);
                break;
            }
            case 'a': {
                change_alignment(ps);
                break;
            }
            case 'b': {
                change_bold(ps);
                break;
            }
            case 'i': {
                change_italic(ps);
                break;
            }
            case 'u': {
                change_underline(ps);
                break;
            }
            default: {//'q'
                is_quit = true;
                break;
            }
        }

        if (is_quit) break;
    }
    printf("Bye!");
    return 0;
}

void show_menu(void) {
    printf("f)change font   s)change size   a)change alignment\n");
    printf("b)change bold   i)toggle italic u)toggle underline\n");
    printf("q)quit\n");
}

void change_font(unsigned long *ps) {
    int n;
    char tmp[TMP_SIZE] = {[0]='\0'};

    printf("Enter font number(0~255):\n");

    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n') continue;
            printf("Enter font number(0~255):\n");
        }

        if (n >= 0 && n <= 255) break;
        printf("Enter font number(0~255):\n");
    }
    printf("要设置的数:\n");
    itobs(n, tmp);
    print_bs(tmp);

    printf("原数:\n");
    itobs(*ps, tmp);
    print_bs(tmp);

    *ps &= ~ID;//清空 id 的 8 位
    printf("清空后:\n");
    itobs(*ps, tmp);
    print_bs(tmp);

    *ps |= n;
    printf("新设置后:\n");
    itobs(*ps, tmp);
    print_bs(tmp);

    show_settings(*ps);
}

void change_size(unsigned long *ps) {
    int n;
    char tmp[TMP_SIZE] = {[0]='\0'};

    printf("Enter font size(0~127):\n");
    while (1) {
        while (scanf("%d", &n) != 1) {
            while (getchar() != '\n') continue;
            printf("Enter font size(0~127):\n");
        }

        if (n >= 0 && n <= 127) break;
        printf("Enter font size(0~127):\n");
    }
    n <<= 8;

    printf("要设置的数:\n");
    itobs(n, tmp);
    print_bs(tmp);

    printf("原数:\n");
    itobs(*ps, tmp);
    print_bs(tmp);

    *ps &= ~SIZE;//清空 size 的 7 位
    printf("清空后:\n");
    itobs(*ps, tmp);
    print_bs(tmp);

    *ps |= n;
    printf("新设置后:\n");
    itobs(*ps, tmp);
    print_bs(tmp);

    show_settings(*ps);
}

void change_alignment(unsigned long *ps) {
    char ch;
    printf("Select alignment:\n");
    printf("1)left  2)center    3)right\n");

    while (1) {
        while (scanf("%c", &ch) != 1) {
            while (getchar() != '\n') continue;
            printf("Select alignment:\n");
            printf("1)left  2)center    3)right\n");
        }
        if (ch == '\n') continue;

        if (strchr("lcr", ch) != NULL) break;
        printf("Select alignment:\n");
        printf("1)left  2)center    3)right\n");
    }

    switch (ch) {
        case 'l': {
            *ps &= ~ALIGNMENT_CENTER;//清空 对齐 的 2 位
            *ps |= ALIGNMENT_LEFT;
            break;
        }
        case 'r': {
            *ps &= ~ALIGNMENT_CENTER;//清空 对齐 的 2 位
            *ps |= ALIGNMENT_RIGHT;
            break;
        }
        default: {//'c'
            *ps &= ~ALIGNMENT_CENTER;//清空 id 的 2 位
            *ps |= ALIGNMENT_CENTER;
            break;
        }
    }
    show_settings(*ps);
}

void change_bold(unsigned long *ps) {
    *ps ^= BOLD;
    show_settings(*ps);
}

void change_italic(unsigned long *ps) {
    *ps ^= ITALIC;
    show_settings(*ps);
}

void change_underline(unsigned long *ps) {
    *ps ^= UNDERLINE;
    show_settings(*ps);
}

void show_settings(unsigned long us) {
    printf("Font settings:\n");
    printf("%5s %5s %10s %5s %5s %5s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%4d %5d %8s %9s %5s %5s\n\n", show_id(us), show_size(us), show_alignment(us),
           show_bold(us), show_italic(us), show_underline(us));
    show_menu();
}

int show_id(unsigned long n) {
    return n & ID;
}

int show_size(unsigned long n) {
    return (int) ((n & SIZE) >> 8);
}

char *show_alignment(unsigned long n) {
    int m = (n & ALIGNMENT_CENTER) >> 15;

    if (m == 2)
        return "right";
    else if (m == 1)
        return "left";
    else
        return "center";
}

char *show_bold(unsigned long n) {
    n &= BOLD;
    n >>= 17;
    return n == 1 ? "on" : "off";
}

char *show_italic(unsigned long n) {
    n &= ITALIC;
    n >>= 18;
    return n == 1 ? "on" : "off";
}

char *show_underline(unsigned long n) {
    n &= UNDERLINE;
    n >>= 19;
    return n == 1 ? "on" : "off";
}

char *itobs(int n, char *ps) {
    const static int size = sizeof(int) * 8;

    for (int j = size - 1; j >= 0; j--, n >>= 1)
        ps[j] = (n & 01) + '0';
    ps[size] = '\0';
    return ps;
}

void print_bs(char *st) {
    printf("bin str = ");
    for (int j = 0; j < strlen(st); ++j) {
        printf("%c", st[j]);
        if (((j + 1) % 4) == 0)
            printf(" ");
    }
    printf("\n");
}
