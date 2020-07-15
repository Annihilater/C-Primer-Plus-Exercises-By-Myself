//
// Created by klause on 2020/7/13.
//

// 修改链表的定义实现逆序显示电影列表

#include <stdio.h>
#include <stdlib.h>     //提供 malloc 原型
#include <string.h>     //提供 strcpy 原型

#define TSIZE 45        //储存片名的数组大小

struct film {
    char title[TSIZE];
    int rating;
    struct film *next;//指向链表中的下一个结构
    struct film *prev;//指向链表中的上一个结构
};

char *s_gets(char *st, int n);

int main(void) {
    struct film *head = NULL;
    struct film *tail = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    //收集并储存信息
    puts("Enter first movie title: ");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL) {
            head = current;
            current->prev = NULL;
        } else {
            prev->next = current;
            current->prev = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>: ");
        scanf("%d", &current->rating);
        while (getchar() != '\n')continue;
        puts("Enter next movie title (empty line to stop): ");
        prev = tail = current;
    }

    //正序显示电影列表
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list(Positive sequence):\n");
    current = head;
    while (current != NULL) {
        printf("Movie: %s Rating %d\n", current->title, current->rating);
        current = current->next;
    }
    printf("\n");
    //逆序显示电影列表
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list(Reverse order):\n");
    current = tail;
    while (current != NULL) {
        printf("Movie: %s Rating %d\n", current->title, current->rating);
        current = current->prev;
    }

    //完成任务，释放已分配的内存
    current = head;
    while (current != NULL) {
        head = current->next;
        free(current);
        current = head;
    }

    printf("Bye!\n");
    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n') continue;
    }
    return ret_val;
}
