#include<stdio.h>
/*
    �ֱ�a1��am���򣬽�b1��bn����
    �ٽ���������
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
    note: δ���Ǵ���������ұ߳����ܳ���
    ע���±�任����������
*/


