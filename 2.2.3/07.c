#include<stdio.h>
#define MAXSIZE 50
typedef struct {
    int data[MAXSIZE];
    int length;
}Sq;
/*
    用i，j分别指向两个有序顺序表表头
    将较小值放入新的顺序表中，直到有一个表走完，将剩余元素依次放入顺序表中
    修改表长，返回有序表的地址
*/
int merge(Sq *A, Sq *B, Sq *C){
    if(A->length + B->length > MAXSIZE)
        return 0;
    int i = 0,j = 0, k = 0;
    while(i<A->length && j<B->length){
        if(A->data[i] < B->data[j])
            C->data[k++] = A->data[i++];
        else
            C->data[k++] = B->data[j++];
    }

    while(i < A->length) // B已排完将A剩余部分加入C中
        C->data[k++] = A->data[i++];
    while(j < B->length)
        C->data[k++] = B->data[j++];
    C->length = k;
    return 1;
}
// 如果在merge函数中创建C，执行完函数后地址被释放，无法存下值，所以C需要当作参数传送
// 未考虑错误情况，如果A的表长加上B的表长超过C的最大限度，应该报错
int main(){
    Sq A, B, C;
    A.length = 4;
    for(int i=0; i<A.length; i++){
        A.data[i] = 2*i;
        printf("%d ",A.data[i]);
    }
    printf("\n");
    B.length = 3;
    B.data[0] = 1;
    B.data[1] = 3;
    B.data[2] = 5;
    for(int i=0; i<B.length; i++)
        printf("%d ", B.data[i]);
    printf("\n");
    if(merge(&A, &B, &C))
        for(int i=0; i<C.length; i++)
            printf("%d ", C.data[i]);
    else
        printf("超过表长");
    return 0;
}
/*
    note：未考虑错误处理，如果A的表长加上B的表长超过C的最大限度，应该报错
*/
