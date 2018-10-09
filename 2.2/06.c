#include<stdio.h>
#define MAXSIZE 50

typedef struct{
    int data[MAXSIZE];
    int length;
}Sq;
/*
    遍历有序顺序表，q指向当前不重复的元素
    k记录元素重复的个数
    当遇到与当前元素不相同的元素时，向前移动k位,p++
    修改表长
*/

void del_same(Sq *L){
    int k = 0; // 记录重复元素的个数
    int p = 0; // 指向当前最后一个不重复的元素
    for(int i=1; i<L->length; i++){
        if(L->data[i] == L->data[p])
            k++;
        else{
            L->data[i-k] = L->data[i];
            p++;
        }
    }
    L->length = L->length - k;
}
// 最后忘记修改表长

/*
    类似直接插入排序，默认前面的为已经排好，不重复的有序表
    因为有序，一次判断后面的元素是否与已排号的元素的最后一个值相同，如果相同则插入，否则继续往下执行
    修改表长
*/
int del_same1(Sq *L){
    if(L->length == 0)
        return 0;
    int i,k;
    k = 0;
    i = 1;
    while(i<L->length){
        if(L->data[i] != L->data[k])
            L->data[++k] = L->data[i];
        i++;
    }
    L->length = k+1;
    return 1;
}

int main(){
    Sq L;
    L.length = 8;
    L.data[0] = 0;
    L.data[1] = L.data[2] = L.data[3] = 1;
    L.data[4] = L.data[5] = 2;
    L.data[6] = L.data[7] = 3;
    for(int i=0; i<L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
    del_same1(&L);
    for(int i=0; i<L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}

/*
    note: 有些不需要的变量可减去
    深刻理解直接插入排序
*/

