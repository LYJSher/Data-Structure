#include <stdio.h>
#define MAXSIZE 50
typedef struct{
    int data[MAXSIZE];
    int length;
}Sq;
/*
    有序顺序表，二分查找法
    与中间元素比较，若小于中间元素，取前半区间的中间元素比大小
    标记是否找到x,若找到x则mid为x的坐标
    若没找到x则mid为x应该插入的位置
*/
int searchx(Sq *A,int x){
    int low = 0, high = A->length-1;
    int mid = (low + high) / 2;
    while(low <= high){
        if(A->data[mid] == x){
            break;
        }
        else if(A->data[mid] < x)
            low = mid + 1;
        else
            high = mid -1;
        mid = (low + high) / 2;
    };
    if(A->data[mid] == x && mid!=A->length-1){ // 找到且不为最后一个元素
        int temp;
        temp = A->data[mid];
        A->data[mid] = A->data[mid+1];
        A->data[mid+1] = temp;
        return 1;
    }
    else if(A->data[mid]!=x && A->length+1<=MAXSIZE){ // 未找到，且加入后不超过表长
        for(int i=A->length; i>mid; i--){
            A->data[i] = A->data[i-1];
        }
        A->data[mid+1] = x;
        A->length++;
        return 2;
    }
    else
        return 0;
}
// 注意下标变换
int main(){
    Sq A;
    A.length = 4;
    A.data[0] = 0;
    A.data[1] = 2;
    A.data[2] = 3;
    A.data[3] = 4;
    int re;
    if((re=searchx(&A, 1))==1)
        printf("found\n");
    else if(re == 2)
        printf("not found\n");
    else
        printf("error\n");
    for(int i=0; i<A.length; i++)
        printf("%d ",A.data[i]);

    return 0;
}
/*
    下标变化不熟悉，做题太慢
*/
