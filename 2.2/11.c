#include<stdio.h>
/*
    �����A��B�ı��������λ��Ӧ���ڵ�λ��mid
    �ٸ�AB���򣬲����ź������Ŀk������ֱ���õ�k=mid��kλ��Ԫ��Ϊ���������λ��
    ʱ�临�Ӷ�ΪO(n)
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
    ��Сʱ�临�Ӷȣ�Ӧ�ÿ������ƶ��ַ���˼��
    �ȷֱ��ҳ�A��B����λ��
    �Ƚ�A��B��λ���Ĵ�С��ȥ��С�߽�С��һ�룬�ϴ��߽ϴ��һ��
    A��B�ж�ֻʣһ��Ԫ�أ���С��Ϊ��λ��
    ʱ�临�Ӷ�ΪO(logn)
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
// ���������ǻ�
int main(){
    int A[5] = {11,13,15,17,19};
    int B[5] = {2,4,6,8,20};
    //printf("\n%d", midnum(A, B, sizeof(A)/sizeof(int), sizeof(B)/sizeof(int)));
    printf("\n%d", midnum1(A, B, sizeof(A)/sizeof(int)));
    return 0;
}

/*
    note���ź�����������м������Ƕ��ַ�
*/

