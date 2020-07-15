//
// Created by klause on 2020/7/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist) {
    plist->head = NULL;
}

bool ListIsEmpty(const List *plist) {
    if (plist->head == NULL)
        return true;
    else
        return false;
}

//如果链表已满，返回 true
bool ListIsFull(const List *plist) {
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
 * 操作:      确定链表的元素数量
 * 前置条件:    plist 指向一个链表
 * 后置条件:    返回链表的元素数量
 */
unsigned int ListItemCount(const List *plist) {
    unsigned int count = 0;
    Node *pnode = plist->head;

    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

/*
 * 操作:      在链表的末尾添加项
 * 前置条件:    item 是一个待添加至链表的项，plist 指向一个已初始化链表
 * 后置条件:    如果可以，该函数在链表末尾添加一个项，且返回 true，否则返回 false
 */
bool AddItem(Item item, List *plist) {
    Node *pnew;
    Node *scan = plist->head;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)
        plist->head = pnew;
    else {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
    return true;
}

/*
 * 操作:      把函数作用于链表的每一项
 * 前置条件:    pfun 指向一个函数，该函数接受一个 Item 类型的参数，且无返回值，plist 指向一个链表
 * 后置条件:    pfun 指向的函数作用于链表的每一项一次
 */
void Traverse(const List *plist, void (*pfun)(Item item)) {
    Node *pnode = plist->head;
    while (pnode != NULL) {
        (*pfun)(pnode->item);//把函数应用于列表中的项
        pnode = pnode->next;//前进到下一项
    }
}

/*
 * 操作:      释放已分配的内存（如果有的话）
 * 前置条件:    plist 指向一个已初始化的链表
 * 后置条件:    释放了为链表分配的所有内存，链表设置为空
 */
void EmptyTheList(List *plist) {
    Node *psave;
    while (plist->head != NULL) {
        psave = (plist->head)->next;
        free(&(plist->head));
        plist->head = psave;
    }
}

static void CopyToNode(Item item, Node *pnode) {
    pnode->item = item;
}
