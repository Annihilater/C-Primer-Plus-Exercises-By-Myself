//
// Created by klause on 2020/7/14.
//

#include "program.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
 * 读取文件
 */
void read_file(Tree *t);

/*
 * 显示菜单
 */
void show_menu(void);

/*
 * 读取输入
 */
char *s_gets(char *st, int n);

/*
 * 显示所有单词和出现的次数
 */
void show_all_words(Tree *t);

void show_one_word(Tree *t);

void print_item(Item *it);

int main(void) {
    Tree t;
    char select[5] = {[0]='\0'};

    InitializeTree(&t);

    read_file(&t);
    show_menu();
    s_gets(select, 5);
    switch (select[0]) {
        case 'a': {
            show_all_words(&t);
            break;
        }
        case 'b': {
            show_one_word(&t);
            break;
        }
        default: {
            exit(EXIT_SUCCESS);
        }
    }
    DeleteAll(&t);
    return 0;
}

/*
 * 读取文件
 */
void read_file(Tree *t) {
    char buf[100], word[20] = {[0]='\0'};
    FILE *fp;
    int n, j = 0;
    Item tmp;

    char *filename = "chapter_17/17_12_7/test.txt";
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Couldn't not open %s file.", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, sizeof buf, fp) != NULL) {
        printf("\n-------------------\n");
        puts(buf);
        for (int i = 0; i < strlen(buf); ++i) {

            if (ispunct(buf[i]) && (isspace(buf[i - 1]) || isspace(buf[i + 1]))) continue;

            if ((i == 0 && !isspace(buf[0])) || (isspace(buf[i - 1]) && !isspace(buf[i]))) {
                word[j] = buf[i];
                j++;
            } else if (!isspace(buf[i])) {
                word[j] = buf[i];
                j++;
            } else if (isspace(buf[i])) {
                printf("%s ", word);
                for (int l = 0; l < 20; ++l) tmp.word[l] = '\0';

                strcpy(tmp.word, word);
                tmp.times = 1;
                AddItem(&tmp, t);

                j = 0;
                for (int k = 0; k < 20; ++k) {
                    word[k] = '\0';
                }
                continue;
            }
        }
    }
}

/*
 * 显示菜单
 */
void show_menu(void) {
    printf("\nSelect a function:\n");
    printf("a.Show all words and times\n");
    printf("b.Input a word and see how much times it has been record\n");
    printf("c.Quit\n");
}

/*
 * 读取输入
 */
char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')continue;
    }
    return ret_val;
}

/*
 * 显示所有单词和出现的次数
 */
void show_all_words(Tree *t) {
    void (*pr)(Item);
    if (TreeIsEmpty(t))
        printf("Here is no words.\n");
    pr = (void (*)(Item)) print_item;
    Traverse(t, pr);
}

void show_one_word(Tree *t) {
    char tmp_word[20];
    Item it = {}, it2 = {};

    s_gets(tmp_word, 20);
    strcpy(it.word, tmp_word);
    it.times = 1;

    if (InTree(&it, t)) {
        FindItem(&it, t, &it2);
        printf("%30s : %3d\n", it2.word, it2.times);
    } else
        printf("Word not in file.\n");
}

void print_item(Item *it) {
    if (it != NULL)
        printf("%30s : %3d\n", it->word, it->times);
    else
        printf("it == NULL\n");
}
