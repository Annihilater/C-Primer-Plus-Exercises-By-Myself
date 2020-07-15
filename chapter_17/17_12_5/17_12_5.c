//
// Created by klause on 2020/7/13.
//

#include <stdio.h>
#include <string.h>

#include "stack.h"

#define SIZE 10

char *s_gets(char *st, int n);

int main(void) {
    char st[SIZE] = {[0]='\0'};//实际上只能存 SIZE-1 个字符，最后一个留给空字符，因为用了 s_gets 函数
    Stack stk;
    Item t = {};
    Item *tmp = &t;

    InitializeStack(&stk);
    puts("Please input a strings:");
    s_gets(st, SIZE);

    puts(st);
    printf("Push char to the stack:\n");
    for (int i = 0; i < strlen(st); ++i) {
        tmp->ch = st[i];
        Push(tmp, &stk);
        printf("%c ", st[i]);
    }

    printf("\nPop char from the stack:\n");
    //第一种方式
//    for (int j = 0; j < stk.size; ++j) {
//        Pop(tmp, &stk);
//        printf("%c ", tmp->ch);
//    }
    //第二种方式
    while (Pop(tmp, &stk))
        printf("%c ", tmp->ch);

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n') continue;
    }
    return ret_val;
}

