//
// Created by klause on 2020/6/28.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 10
#define SIZE 100

char *s_gets(char *st, int n);//读取整行输入并用空字符替代换行符，或者读取一部分输入，并丢弃其余部分

void func1(char *str[], int n);//直接打印源字符串列表

void func2(char *str[], int n);//以 ASCII 的顺序打印字符串列表

void func3(char *str[], int n);//按长度递增顺序打印字符串列表

void func4(char *str[], int n, int m);//按字符串中第 1 个单词的长度打印字符串列表

int first_word_length(char *str, int n);//返回字符串的第一个单词的长度，以空格来区分单词


int main(void) {
    // 这些初始化的字符串数组是用与开发测试时免去输入而使用的，程序运行时需要手动输入 10 个字符串
    char input[LIM][SIZE] = {"lll", "vvv", "ttt",
                             "iii", "ddd", "kkk",
                             "hhh", "ccc", "bbb", "aaa"};
    char *str1[LIM] = {"lll", "vvv", "ttt",
                       "iii", "ddd", "kkk",
                       "hhh", "ccc", "bbb", "aaa"};
    char *str2[LIM] = {"lll", "vvv", "ttt",
                       "iii", "ddd", "kkk",
                       "hhh", "ccc", "bbb", "aaa"};
    char *str3[LIM] = {"a", "aa", "aaaa",
                       "aaa", "aaaaaaaaaa", "aaaaaaaaa",
                       "aaaaaa", "aaaaaaaaaaaaaaaaaaa", "aaaaaaaaa", "aaaaaa"};
    char *str4[LIM] = {"l good", "lll good", "lllll good",
                       "llllllllllllllllllllll good", "lllllll good", "lllllllllllll good",
                       "llllll good", "lllllll good", "llllll good", "lllllllll good"};
    char t;
    int ct = 0;

    printf("Please input 10 strings:\n");
    printf("1 string: ");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0') {
        printf("%d string: ", ct + 2);

        /*
         * 4个字符串拷贝分别用于 4 个功能函数，因为4 个功能函数是在原地修改字符串，所以先拷贝 4 份
         */
        str1[ct] = input[ct];
        str2[ct] = input[ct];
        str3[ct] = input[ct];
        str4[ct] = input[ct];
        ct++;
    }

    printf("源字符串列表为:\n");
    for (int i = 0; i < LIM; ++i) {
        printf("%d string: %s\n", i, input[i]);
    }

    printf("Please select a function:\n");
    printf("a.打印源字符串列表              b.以 ASCII 中的顺序打印字符串\n");
    printf("c.按长度递增的顺序打印字符串      d.按字符串中的第 1 个单词的长度打印字符串\n");
    printf("e.退出\n");

    while (1) {
        scanf("%c", &t);

        while (getchar() != '\n')//上面 scanf 会有换行符残留在输入缓存，此处清楚输入缓存
            continue;

        switch (t) {
            case 'a': {
                func1(str1, LIM);//打印源字符串列表
                break;
            }
            case 'b': {
                func2(str2, LIM);//以 ASCII 的顺序打印字符串列表
                break;
            }
            case 'c': {
                func3(str3, LIM);//按长度递增顺序打印字符串列表
                break;
            }
            case 'd': {
                func4(str4, LIM, SIZE);//按字符串中第 1 个单词的长度打印字符串列表
                break;
            }
            case 'e': {
                return 0;//退出
            }
            default: {
                printf("Please input a~e:\n");//输入错误提示，请重新输入
                break;
            }
        }

        printf("Please select a function:\n");
        printf("a.打印源字符串列表              b.以 ASCII 中的顺序打印字符串\n");
        printf("c.按长度递增的顺序打印字符串      d.按字符串中的第 1 个单词的长度打印字符串\n");
        printf("e.退出\n");
    }
}

//读取整行输入并用空字符替代换行符，或者读取一部分输入，并丢弃其余部分
char *s_gets(char *st, int n) {
    char *ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (*st != '\n' && *st != '\0') // 寻找空字符或者换行符
            st++;
        if (*st == '\n')                   // 如果找到换行符，则将换行符替换为 空字符
            *st = '\0';
        else
            while (getchar() != '\n')      // 如果没有找到换行符（找到了空字符），那么就清空空字符后面的缓存
                continue;
    }
    return ret_val;
}

//直接打印源字符串列表
void func1(char *str[], int n) {
    printf("源字符串列表为:\n");
    for (int j = 0; j < n; ++j) {
        printf("%2d string: ", j + 1);
        printf("%s\n", str[j]);
    }
}

//以 ASCII 的顺序打印字符串列表
void func2(char *str[], int n) {
    char *tmp;//定义一个字符串数组

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(str[i], str[j]) > 0) {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }

    printf("以 ASCII 的顺序打印字符串列表:\n");
    for (int i = 0; i < n; ++i) {
        printf("%2d string: %s\n", i + 1, str[i]);
    }
}

//按长度递增顺序打印字符串列表
void func3(char *str[], int n) {
    char *tmp;//定义一个字符串数组

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strlen(str[i]) > strlen(str[j])) {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }

    printf("按长度递增顺序打印字符串列表:\n");
    for (int k = 0; k < n; ++k) {
        printf("%2d string: %s\n", k + 1, str[k]);
    }
}

//按字符串中第 1 个单词的长度打印字符串列表
void func4(char *str[], int n, int m) {//n 为字符串的长度
    char *tmp;//定义一个字符串数组

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (first_word_length(str[i], m) > first_word_length(str[j], m)) {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }

    printf("按字符串中第 1 个单词的长度打印字符串列表:\n");
    for (int i = 0; i < n; ++i) {
        printf("%2d string: %s\n", i + 1, str[i]);
    }
}

//返回字符串的第一个单词的长度，以空格来区分单词
int first_word_length(char *str, int n) {
    for (int i = 0; i < n; ++i) {
        if (isspace(str[i])) {//查找字符串第一个空格的索引
            return i;
        }
    }
    return n;
}
