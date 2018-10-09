#include<stdio.h>
/*
    循环左移p位
    先将前p位和末尾p位置换
    再将末尾p位逆置，前面n-p位逆置
*/

int rev(int *A, int l, int r, int n){ // 逆置 l:交换首 r:交换尾 n+1:A的长度
    if(r>n+1 || l>r)
        return 0;
    int lim = (r-l)/2; // 最多交换次数
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
    注意下标运算，多熟悉逆置的各种用法
    上述做法的时间复杂度为O(n),空间复杂度为O(1)

    也可以先开辟p个辅助空间
    将n-p个整体左移再将p个放在后面
    时间复杂度为O(n),空间复杂度为O(p)
*/
