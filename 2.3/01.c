#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int data;
    struct LNode *next;
}LNode, *List;

/*
    终结条件：如果L为空表 直接return
    递归主体：如果L->data == x 删除节点：用p指向L，令L=L->next, 释放p
                               继续递归f(L, x)
              否则，继续递归f(L->next, x)
*/

void del_x(List *L, int x){
    if(*L == NULL)
        return;
    if((*L)->data == x){
        LNode *p = *L;
        (*L) = (*L)->next;
        free(p);
        del_x((*L), x);
    }
    else
        del_x((*L)->next, x);
}

/*
    不熟悉递归分解问题

    元素值为x删除，否则继续往下判断
    一开始自己写的时候考虑复杂，想通过返回指针来实现，绕不出来

    删除结点的时候要把结点的空间一起释放
*/

