#include<stdio.h>
#define MAXSIZE 50

typedef struct{
    int data[MAXSIZE];
    int length;
}Sq;

/*
    如果为空表返回错误
    遍历顺序表，若元素小于当前最小值，更新最小值并记录最小值下标
    用最后一个元素填补最小值下标元素
    顺序表长度-1

*/
int deleteMin(Sq *L, int *e){
    int pos = 0;
    int min;

    if(L->length == 0)
        return 0;
    for(int i=1, min=L->data[0]; i<L->length; i++){
        if(L->data[i] < min){
            min = L->data[i];
            pos = i;
        }
    }
    *e = L->data[pos];
    L->data[pos] = L->data[L->length-1];
    L->length--;
    return 1;
}

int main(){
    Sq L;
    L.length = 3;
    L.data[0] = 1;
    L.data[1] = 1;
    L.data[2] = 0;
    int e;
    if(deleteMin(&L, &e)){
        for(int i=0; i<L.length; i++)
            printf("%d ", L.data[i]);
        printf("\nthe deleted elem:%d\n",e);
    }
    else
        printf("list is empty\n");
    return 0;
}
