#include<stdio.h>
/*
    先求出A、B的表长，求出中位数应该在的位置mid
    再给AB排序，并将排好序的数目k计数，直到得到k=mid则k位的元素为两个表的中位数
    时间复杂度为O(n)
*/
int midnum(int *A, int *B, int la, int lb){
    int i, j, k;
    i = j = k = 0;
    int re;
    while(k<(la + lb)/2){
        if(A[i]<B[j]){
            re = A[i];
            printf("%d ",re);
            i++;
        }
        else{
            re = B[j];
            printf("%d ",re);
            j++;
        }
        k++;
    }
    return re;
}

/*
    减小时间复杂度，应该考虑类似二分法的思想
    先分别找出A、B的中位数
    比较A、B中位数的大小舍去较小者较小的一半，较大者较大的一半
    A、B中都只剩一个元素，较小者为中位数
    时间复杂度为O(logn)
*/
int midnum1(int *A, int *B, int n){
    int al, bl, ah, bh, am, bm;
    al = bl = 0;
    ah = bh = n-1;
    do{
        am = (al + ah)/2;
        bm = (bl + bh)/2;
        printf("A%d B%d\n", A[am], B[bm]);
        if(A[am] == B[bm])
            return A[am];
        else if(A[am] < B[bm]){
                al = am+1;
                bh = bm-1;
        }
        else{
                bl = bm+1;
                ah = am-1;
        }
    }while(al<=ah || bl<=bh);
    return (A[am]<B[bm])?A[am]:B[bm];
}
// 结束条件是或
int main(){
    int A[5] = {11,13,15,17,19};
    int B[5] = {2,4,6,8,20};
    //printf("\n%d", midnum(A, B, sizeof(A)/sizeof(int), sizeof(B)/sizeof(int)));
    printf("\n%d", midnum1(A, B, sizeof(A)/sizeof(int)));
    return 0;
}

/*
    note：排好序的序列找中间数考虑二分法
*/

