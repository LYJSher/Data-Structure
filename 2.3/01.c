#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int data;
    struct LNode *next;
}LNode, *List;

/*
    �ս����������LΪ�ձ� ֱ��return
    �ݹ����壺���L->data == x ɾ���ڵ㣺��pָ��L����L=L->next, �ͷ�p
                               �����ݹ�f(L, x)
              ���򣬼����ݹ�f(L->next, x)
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
    ����Ϥ�ݹ�ֽ�����

    Ԫ��ֵΪxɾ����������������ж�
    һ��ʼ�Լ�д��ʱ���Ǹ��ӣ���ͨ������ָ����ʵ�֣��Ʋ�����

    ɾ������ʱ��Ҫ�ѽ��Ŀռ�һ���ͷ�
*/

