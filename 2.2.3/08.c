#include<stdio.h>
/*
    分别将a1—am逆序，将b1—bn逆序
    再将总体逆序
*/
int rever(int *A, int left, int right, int length){
    if(left > right || right > length)
        return 0;
    int temp;
    int mid = (left+right)/2;
    for(int i=0; i<=(mid-left); i++){
        temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
    return 1;
}

int main(){
    int A[5]={1, 2, 3, 7, 8};
    for(int i=0; i<5; i++)
        printf("%d ", A[i]);
    printf("\n");
    rever(A, 0, 2, 5);
    for(int i=0; i<5; i++)
        printf("%d ", A[i]);
    printf("\n");
    rever(A, 3, 4, 5);
    for(int i=0; i<5; i++)
        printf("%d ", A[i]);
    printf("\n");
    rever(A, 0, 4, 5);
    for(int i=0; i<5; i++)
        printf("%d ", A[i]);
}
/*
    note: 未考虑错误处理，如果右边超过总长度
    注意下标变换！！！！！
*/


