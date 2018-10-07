#include <stdio.h>
#define MAXSIZE 50


typedef struct {
    int data[MAXSIZE];
    int length;
}Sq;

/*
    如果s>t或表空return 0
    遍历有序顺序表，记录小于s的最后一个下标p和大于t的第一个下标q
    将q及其以后至表末尾的元素顺次移动至p后
    修改表长
*/
int del_s_t(Sq *L, int s, int t){
    if(L->length == 0 || s>t)
        return 0;
    int count = 0;
    int p, q = -1; // 记录最后一个小于s值的下标和第一个大于t值的下标
    for(int i=0; i<L->length; i++){
        if(L->data[i] < s)
            p = i;
        if(L->data[i] > t){
            q = i;
            count = q-p-1;
            while(i<L->length){
                L->data[p+1] = L->data[i];
                p++;
                i++;
            }
        }
    }
    L->length = L->length - count;
    return 1;
}
// 先画好图，用纸演算后再写程序

/*
    用k记录有序顺序表中在s-t中的元素个数
    遇到第一个大于t的值，则之后的元素整体前移k
    修改表长
*/
int del_s_t1(Sq *L, int s, int t){
    int i, j;
    if(s>t || L->length == 0)
        return 0;
    for(i=0; L->data[i] < s; i++); // 寻找第一个不小于s的值
    if(i>=L->length)
        return 0; // s大于L中的所有值，报错
    for(j=i; L->data[j] <= t; j++); // 寻找第一个大于t的值 注意：因为第一个大于t所以是<=
    while(j<L->length){
        L->data[i++] = L->data[j++];
    }
    L->length = i; // i为最后一个元素下标
}
int main(){
    Sq L1, L2;
    L2.length = 0;
    L1.length = 10;
    for(int i=0; i<10; i++){
        L1.data[i] = i;
        printf("%d ",L1.data[i]);
    }
    printf("\n");
    if(del_s_t2(&L1, 5, 8))
        for(int i=0; i<L1.length; i++)
            printf("%d ",L1.data[i]);
    else{
        printf("error\n");
    }
    return 0;
}

/*
    note：一般直接指向交换的元素
    顺序表中要移动元素，会先记录需要移动的个数，再满足条件的时候移动
*/

