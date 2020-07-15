//
// Created by klause on 2020/7/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

static void CopyToNode(Item item, Item *pnode);

void InitializeList(List *plist) {
    Item item = {};
    for (int i = 0; i < MAXSIZE; ++i) {
        plist->entries[i] = item;
    }
    plist->items = 0;
}

bool ListIsEmpty(const List *plist) {
    if (plist->items == 0)
        return true;
    else
        return false;
}

//如果链表已满，返回 true
bool ListIsFull(const List *plist) {
    return (plist->items == MAXSIZE) ? true : false;
}

/*
 * 操作:      确定链表的元素数量
 * 前置条件:    plist 指向一个链表
 * 后置条件:    返回链表的元素数量
 */
unsigned int ListItemCount(const List *plist) {
    return plist->items;
}

/*
 * 操作:      在链表的末尾添加项
 * 前置条件:    item 是一个待添加至链表的项，plist 指向一个已初始化链表
 * 后置条件:    如果可以，该函数在链表末尾添加一个项，且返回 true，否则返回 false
 */
bool AddItem(Item item, List *plist) {
    if (plist->items == MAXSIZE)
        return false;

    CopyToNode(item, &plist->entries[plist->items]);
    plist->items++;
    return true;
}

/*
 * 操作:      把函数作用于链表的每一项
 * 前置条件:    pfun 指向一个函数，该函数接受一个 Item 类型的参数，且无返回值，plist 指向一个链表
 * 后置条件:    pfun 指向的函数作用于链表的每一项一次
 */
void Traverse(const List *plist, void (*pfun)(Item item)) {
    for (int i = 0; i < plist->items; ++i) {
        (*pfun)(plist->entries[i]);
    }
}

/*
 * 操作:      释放已分配的内存（如果有的话）
 * 前置条件:    plist 指向一个已初始化的链表
 * 后置条件:    释放了为链表分配的所有内存，链表设置为空
 */
void EmptyTheList(List *plist) {
    Item item = {};
    for (int i = 0; i < MAXSIZE; ++i) {
        plist->entries[i] = item;
    }
    plist->items = 0;
}

//第二个参数是目标变量的指针，因为需要修改它的值，所以比续使用地址，其实也可以不用这个函数直接将代码写进调用方函数，只有一行代码
static void CopyToNode(Item item, Item *pnode) {
    *pnode = item;
}
