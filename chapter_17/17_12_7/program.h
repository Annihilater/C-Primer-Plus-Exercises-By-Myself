//
// Created by klause on 2020/7/14.
//

#ifndef C_PRIMER_PLUS_PROGRAM_H
#define C_PRIMER_PLUS_PROGRAM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item {
    char word[20];
    int times;
} Item;

typedef struct node {
    Item item;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree {
    Node *root;
    int size;
} Tree;

//函数原型

/*
 * 初始化
 */
void InitializeTree(Tree *t);

/*
 * 检查树是否为空
 */
bool TreeIsEmpty(const Tree *t);

/*
 * 检查树是否已满
 */
bool TreeIsFull(const Tree *t);

/*
 * 返回数的节点数量
 */
int TreeItemCount(const Tree *t);

/*
 * 向树种添加项
 */
bool AddItem(Item *pi, Tree *t);

/*
 * 在树中查找一个项
 */
bool InTree(Item *pi, const Tree *t);

/*
 * 在树中查找项 pi2 是用来接收树中的项
 */
bool FindItem(Item *pi, const Tree *t, Item *pi2);

/*
 * 删除树中的项
 */
bool DeleteItem(Item *pi, Tree *t);

/*
 * pfunc 是指向函数的指针
 * 为树中每个节点执行 pfunc 函数一次
 */
void Traverse(const Tree *t, void (*pfunc)(Item item));

/*
 * 删除树中所有内容
 */
void DeleteAll(Tree *t);

#endif //C_PRIMER_PLUS_PROGRAM_H
