#include<stdio.h>
/*
    ѭ������pλ
    �Ƚ�ǰpλ��ĩβpλ�û�
    �ٽ�ĩβpλ���ã�ǰ��n-pλ����
*/

int rev(int *A, int l, int r, int n){ // ���� l:������ r:����β n+1:A�ĳ���
    if(r>n+1 || l>r)
        return 0;
    int lim = (r-l)/2; // ��ཻ������
    int temp;
    for(int i=0; lim-i>=0; i++){
        temp = A[l+i];
        A[l+i] = A[r-i];
        A[r-i] = temp;
    }
    //for(int i=0; i<=5; i++)
    //        printf("%d ", A[i]);
    //printf("\n");
    return 1;
}

int cir_left(int *A, int n, int p){
    if(rev(A,0,n,n) && rev(A,0,n-p,n) && rev(A,n-p+1,n,n))
        return 1;
    else
        return 0;
}

int main(){
    int A[6] = {1,2,3,4,5,6};
    for(int i=0; i<=5; i++)
            printf("%d ", A[i]);
    printf("\n");
    if(cir_left(A, 5,3))
        for(int i=0; i<=5; i++)
            printf("%d ", A[i]);
    else
        printf("error\n");
}
/*
    ע���±����㣬����Ϥ���õĸ����÷�
    ����������ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)

    Ҳ�����ȿ���p�������ռ�
    ��n-p�����������ٽ�p�����ں���
    ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(p)
*/
