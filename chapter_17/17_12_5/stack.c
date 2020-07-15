//
// Created by klause on 2020/7/14.
//

#include "stack.h"
#include <stdlib.h>

/*
 * 操作:      初始化栈
 * 前置条件:    st 指向一个栈
 * 后置条件:    栈被初始化为空
 */
void InitializeStack(Stack *st) {
    st->top = NULL;
    st->size = 0;
}

/*
 * 操作:      确定栈是否已满
 * 前置条件:    st 指向一个栈
 * 后置条件:    如果栈已满，返回 true，否则返回 false
 */
bool StackIsFull(const Stack *st) {
    Node *pt;
    bool full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

/*
 * 操作:      确定栈是否为空
 * 前置条件:    st 指向一个栈
 * 后置条件:    如果栈为空，返回 true，否则返回 false
 */
bool StackIsEmpty(const Stack *st) {
    return st->size == 0 ? true : false;
}

/*
 * 操作:      确定栈的元素数量
 * 前置条件:    st 指向一个栈
 * 后置条件:    返回栈的元素数量
 */
int StackItemCount(const Stack *st) {
    return st->size;
}

/*
 * 操作:      向栈顶压入一个元素
 * 前置条件:    st 指向一个栈，pi是待压入元素的地址
 * 后置条件:    如果可以压入，该函数在栈中压入一个元素并返回true，否则返回 false
 */
bool Push(const Item *pi, Stack *st) {
    if (StackIsFull(st))                    //如果栈已满，则返回 false
        return false;

    Node *pt;                               //创建一个指向 Node 的指针
    pt = (Node *) malloc(sizeof(Node));     //为新的 Node 分配内存
    pt->item = *pi;                         //将目标元素赋值给新的 Node

    pt->next = st->top;                     //将新的 Node 的 next 指向原栈中的 top(头部 Node 节点)

    st->top = pt;                           //将新的 Node 赋值给栈的头部 Node 节点
    st->size++;                             //栈的元素数量 +1
    return true;
}

/*
 * 操作:      从栈顶弹出一个
 * 前置条件:    st 指向一个栈，pi 弹出元素的地址
 * 后置条件:    如果从栈中成功弹出一个元素，该函数返回true，否则返回 false
 */
bool Pop(Item *pi, Stack *st) {
    if (StackIsEmpty(st))   //如果栈为空，则弹出失败
        return false;

    Node *pt = NULL, *pt2 = NULL;

    pt2 = st->top;          //先保存下栈顶节点的地址，稍后释放它

    pt = st->top->next;     //先用一个指针 pt 把顶部节点的下一个节点地址存起来
    *pi = st->top->item;    //再将顶部节点的 item 赋值给目标 item (pi), 采用指针形式
    st->top = pt;           //将 pt 赋值给栈的顶部节点
    free(pt2);              //释放顶部节点的内存
    st->size--;             //栈的节点数量减 1，这个很重要，不然栈的节点数量永远不变
    return true;
}

/*
 * 操作:      把函数应用于栈中的每一个元素
 * 前置条件:    st 指向一个栈，pfunc 指向一个函数，该函数接受一个 Item 类型的参数，并无返回值
 * 后置条件:    pfunc 指向的这个函数为栈中每个元素执行一次
 */
void Traverse(const Stack *st, void (*pfunc)(Item item)) {
    Node *pnode = st->top;
    while (pnode != NULL) {
        (*pfunc)(pnode->item);//把函数应用于栈中的项
        pnode = pnode->next;//前进到下一项
    }
}

/*
 * 操作:      清空栈
 * 前置条件:    st 指向一个栈
 * 后置条件:    栈为空
 */
void DeleteAll(Stack *st) {
    Node *pnode = st->top;
    Node *tmp;
    while (pnode != NULL) {
        tmp = pnode->next;
        free(pnode);//把函数应用于栈中的项
        pnode = tmp;//前进到下一项
    }
}
