//
// Created by klause on 2020/7/14.
//

#include <stdio.h>

#define SIZE 10

int lookup(const int ar[], int n, int m);

int lookup1(const int ar[], int n, int m);

int binarysearch(int *arr, int arr_size, int target);

static int binarysearch_aux(int *arr, int target, int low, int high);


int main(void) {
    int ar[SIZE], m = 8;

    for (int i = 0; i < SIZE; ++i) {
        ar[i] = i;
    }

    if (lookup(ar, SIZE, m))
        printf("%d is in array\n", m);
    else
        printf("%d is not in array\n", m);

    if (lookup1(ar, SIZE, m))
        printf("%d is in array\n", m);
    else
        printf("%d is not in array\n", m);

    if (binarysearch(ar, SIZE, m))
        printf("%d is in array\n", m);
    else
        printf("%d is not in array\n", m);
    return 0;
}

int lookup(const int ar[], int n, int m) {
    int in_or_not = 0;

    for (int i = 0; i < n; ++i) {
        if (ar[i] == m)
            in_or_not = 1;
    }
    return in_or_not;
}

//二分查找: 数组必须是有序数组
int lookup1(const int ar[], int n, int m) {
    int in_or_not = 0;
    int start = 0;
    int end = n;
    int half = (start + end) / 2;

    while (half != 1) {
        if (m < ar[half]) {
            end = half;
            half = (start + end) / 2;
        } else if (m > ar[half]) {
            start = half;
            half = (start + end) / 2;
        } else {
            in_or_not = 1;
            break;
        }
    }

    return in_or_not;
}

//修改参数, 没有参数就创造参数
int binarysearch(int *arr, int arr_size, int target) {
    return binarysearch_aux(arr, target, 0, arr_size - 1);
}

//使用了递归
static int binarysearch_aux(int *arr, int target, int low, int high) {
    if (low == high)// base case 递归终止条件
        return arr[low] == target ? 1 : 0;
    else {// recursion case
        int mid = (low + high) / 2;
        if (arr[mid] < target)
            return binarysearch_aux(arr, target, mid + 1, high);
        else
            return binarysearch_aux(arr, target, low, mid);
    }
}
