//
// Created by klause on 2020/7/14.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "program.h"

#define MAXITEMS 1000000000

typedef struct pairs {
    Node *parents;
    Node *child;
} Pairs;

static Node *MakeNode(const Item *pi);

static bool ToLeft(const Item *i1, const Item *i2);

static bool ToRight(const Item *i1, const Item *i2);

static void AddNode(Node *new_node, Node *root);

static void InOrder(const Node *root, void (*pfunc)(Item item));

static Pairs SeekItem(const Item *pi, const Tree *t);

static void DeleteNode(Node **ptr);

static void DeleteAllNode(Node *root);

/*
 * 初始化
 */
void InitializeTree(Tree *t) {
    t->root = NULL;
    t->size = 0;
}

/*
 * 检查树是否为空
 */
bool TreeIsEmpty(const Tree *t) {
    if (t->root == NULL)
        return true;
    else
        return false;
}

/*
 * 检查树是否已满
 */
bool TreeIsFull(const Tree *t) {
    if (t->size == MAXITEMS)
        return true;
    else
        return false;
}

/*
 * 返回数的节点数量
 */
int TreeItemCount(const Tree *t) {
    return t->size;
}

bool AddItem(Item *pi, Tree *t) {
    Node *tmp;
    Node *new_node;

    if (TreeIsFull(t)) {
        fprintf(stderr, "Tree is full\n");
        return false;
    }

    if ((tmp = SeekItem(pi, t).child) != NULL) {
        fprintf(stdout, " +1.\n");
        tmp->item.times++;
        return true;
    }

    new_node = MakeNode(pi);
    if (new_node == NULL) {
        fprintf(stderr, "Couldn't creat node\n");
        return false;
    }

    if (t->root == NULL)
        t->root = new_node;
    else
        AddNode(new_node, t->root);

    t->size++;
    return true;
}

/*
 * 在树中查找一个项
 */
bool InTree(Item *pi, const Tree *t) {
    return (SeekItem(pi, t).child == NULL) ? false : true;
}

bool FindItem(Item *pi, const Tree *t, Item *pi2) {
    Pairs pa;
    pa = SeekItem(pi, t);
    if (pa.child == NULL)
        return false;
    strcpy(pi2->word, pa.child->item.word);
    pi2->times = pa.child->item.times;
    return true;
}

/*
 * 删除树中的项
 * 先查找 item 在不在树中：
 *      不在树中，返回 false
 *      在树中时，删除操作需要考虑目标节点的子树：
 *          无左右子树
 *              父节点相应的子树设置为空
 *              释放目标节点内存
 *          有左子树无右子树 或者 左右子树都有
 *              左子树的最右节点的右子节点 连接 目标节点的右节点
 *              父节点相应子树设置为左子树的最右节点
 *              释放目标节点内存
 *          无左子树有右子树
 *              父节点的相应子树设置为右子树
 *              释放目标节点内存
 *
 */
bool DeleteItem(Item *pi, Tree *t) {
    Pairs look;

    look = SeekItem(pi, t);
    if (look.child == NULL)
        return false;

    if (look.parents == NULL)
        DeleteNode(&t->root);
    else if (look.parents->left == look.child)
        DeleteNode(&look.parents->left);
    else
        DeleteNode(&look.parents->right);

    t->size--;
    return true;
}

/*
 * pfunc 是指向函数的指针
 * 为树中每个节点执行 pfunc 函数一次
 */
void Traverse(const Tree *t, void (*pfunc)(Item item)) {
    if (t != NULL)
        InOrder(t->root, pfunc);
}

void DeleteAll(Tree *t) {
    if (t != NULL)
        DeleteAllNode(t->root);
    t->root = NULL;
    t->size = 0;
}

static void InOrder(const Node *root, void (*pfunc)(Item item)) {
    if (root != NULL) {
        InOrder(root->left, pfunc);
        (*pfunc)(root->item);
        InOrder(root->right, pfunc);
    }
}

static void DeleteAllNode(Node *root) {
    Node *pright;

    if (root != NULL) {
        pright = root->right;
        DeleteAllNode(root->left);
        free(root);
        DeleteAllNode(pright);
    }
}

static void AddNode(Node *new_node, Node *root) {
    if (ToLeft(&new_node->item, &root->item)) {
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    } else if (ToRight(&new_node->item, &root->item)) {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    } else {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item *i1, const Item *i2) {
    if (strcmp(i1->word, i2->word) < 0)//i1 < i2
        return true;
    else
        return false;
}

static bool ToRight(const Item *i1, const Item *i2) {
    if (strcmp(i1->word, i2->word) > 0)//i1 > i2
        return true;
    else
        return false;
}

static Node *MakeNode(const Item *pi) {
    Node *new_node = NULL;

    if ((new_node = (Node *) malloc(sizeof(Node))) != NULL) {
        new_node->item = *pi;
        new_node->left = new_node->right = NULL;
    }
    return new_node;
}

static Pairs SeekItem(const Item *pi, const Tree *t) {
    Pairs look;
    look.parents = NULL;
    look.child = t->root;

    if (look.child == NULL)
        return look;

    while (look.child != NULL) {
        if (ToLeft(pi, &(look.child->item))) {          //目标节点在左子树
            look.parents = look.child;
            look.child = look.child->left;
        } else if (ToRight(pi, &(look.child->item))) {  //目标节点在右子树
            look.parents = look.child;
            look.child = look.child->right;
        } else                                          //目标节点就是 look.child
            break;
    }
    return look;
}

static void DeleteNode(Node **ptr) {
    Node *temp;

    if ((*ptr)->left == NULL) {             //左子树为空
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {     //右子树为空
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else {                                //左右子树都不为空
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

