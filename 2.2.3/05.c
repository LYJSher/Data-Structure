#include<stdio.h>
#define MAXSIZE 50
typedef struct{
    int data[MAXSIZE];
    int length;
}Sq;

/*
    当s>=t或表为空表返回错误
    遍历顺序表，p记录第一个s-t之间的坐标
    当p指向的元素在s-t之间时，q从表尾找不为s-t之间的元素，与p交换
    直到p>=q时，结束
    修改表长，length = q+1
*/
int del_s_t(Sq *L, int s, int t){
    if(s>=t || L->length==0)
        return 0;

    int p = 0;
    int q = L->length-1;
    for(int i=0; p<q; i++){
        if(L->data[i] >= s && L->data[i] <= t){
            p = i; // 寻找第一个在s-t之间的值
            while(q > p){
                if(L->data[q] <s || L->data[q] > t){  // 寻找第一个不在s-t之间的值
                    L->data[p] = L->data[q];
                    q--;
                    break;
                }
                else
                    q--;
            }
        }
    }
    L->length = q+1;
    return 1;
}
// 忘记break和q--

/*
    从前往后扫描顺序表，用k记录值在s-t的元素个数
    当遇到不在s-t中值时，往前移动k个元素，否则k++
*/
int del_s_t1(Sq *L, int s, int t){
    if(s>=t || L->length==0)
        return 0;
    int k = 0;
    for(int i=0; i<L->length; i++){
        if(L->data[i] < s || L->data[i] > t){
            L->data[i-k] = L->data[i];
        }
        else
            k++;
    }
    L->length = L->length - k;
    return 1;
}

int main(){
    Sq L;
    L.length = 7;
    L.data[0] = 0;
    L.data[1] = 2;
    L.data[2] = 4;
    L.data[3] = 3;
    L.data[4] = 2;
    L.data[5] = 5;
    L.data[6] = 6;
    for(int i=0; i<L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
    if(del_s_t1(&L, 3, 5)){
        for(int i=0; i<L.length; i++)
            printf("%d ", L.data[i]);
    }
    else
        printf("error\n");
    return 0;
}

/*
    note:用k记录需要移动的位置比交换前后的优点在于保持了顺序性
*/
