//
// Created by klause on 2020/7/13.
//

/*
 * 类型名: 栈
 * 类型属性: 可以储存一系列项
 * 类型操作: 初始化栈为空
 *          确定栈为空
 *          确定栈已满
 *          确定栈中的项数
 *          在栈顶压入元素
 *          在栈顶弹出元素
 *          遍历栈
 *          清空栈
 */

#ifndef C_PRIMER_PLUS_STACK_H
#define C_PRIMER_PLUS_STACK_H

#include <stdbool.h>

typedef struct {
    char ch;
} Item;

#define MAXSTACK 10

typedef struct node {
    Item item;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
    int size;
} Stack;

/*
 * 操作:      初始化栈
 * 前置条件:    st 指向一个栈
 * 后置条件:    栈被初始化为空
 */
void InitializeStack(Stack *st);

/*
 * 操作:      确定栈是否已满
 * 前置条件:    st 指向一个栈
 * 后置条件:    如果栈已满，返回 true，否则返回 false
 */
bool StackIsFull(const Stack *st);

/*
 * 操作:      确定栈是否为空
 * 前置条件:    st 指向一个栈
 * 后置条件:    如果栈为空，返回 true，否则返回 false
 */
bool StackIsEmpty(const Stack *st);

/*
 * 操作:      确定栈的元素数量
 * 前置条件:    st 指向一个栈
 * 后置条件:    返回栈的元素数量
 */
int StackItemCount(const Stack *st);

/*
 * 操作:      向栈顶压入一个元素
 * 前置条件:    st 指向一个栈，pi是待压入元素的地址
 * 后置条件:    如果可以压入，该函数在栈中压入一个元素并返回true，否则返回 false
 */
bool Push(const Item *pi, Stack *st);

/*
 * 操作:      从栈顶弹出一个
 * 前置条件:    st 指向一个栈，pi 弹出元素的地址
 * 后置条件:    如果从栈中成功弹出一个元素，该函数返回true，否则返回 false
 */
bool Pop(Item *pi, Stack *st);

/*
 * 操作:      把函数应用于栈中的每一个元素
 * 前置条件:    st 指向一个栈，pfunc 指向一个函数，该函数接受一个 Item 类型的参数，并无返回值
 * 后置条件:    pfunc 指向的这个函数为栈中每个元素执行一次
 */
void Traverse(const Stack *st, void (*pfunc)(Item item));

/*
 * 操作:      清空栈
 * 前置条件:    st 指向一个栈
 * 后置条件:    栈为空
 */
void DeleteAll(Stack *st);

#endif //C_PRIMER_PLUS_STACK_H
