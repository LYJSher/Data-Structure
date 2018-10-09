#include<stdio.h>
#include <stdlib.h>
/*
    一、0<=元素数<序列长度n
    二、相同元素个数 > n/2
    则为主元素
    排序后的中位数以其前后计算该中位数的个数，大于n/2则返回该数
    否则返回-1
    时间复杂度是O(nlogn)
*/

int cmp(const void*a,const void*b)
{
   return  *(int*)a-*(int*)b;
}
int comp(int *a, int *b){
    return (*a)-(*b);
}
// 注意cmp的写法

int findmain(int *A, int n){
    qsort(A,n,sizeof(int),comp);
    int mid = A[(int)((n-1)/2)];
    int count = 1;
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
    for(int i=(n-1)/2+1; i<n-1;i++){
        if(A[i] == mid)
            count++;
        else
            break;
    }
    for(int i=(n-1)/2-1; i>0; i--){
        if(A[i] == mid)
            count++;
        else
            break;
    }
    printf("%d\n",count);
    if(count > n/2)
        return A[mid];
    else
        return -1;
}

int main(){
    int A[8] = {0,5,5,3,5,7,5,5};
    printf("%d",findmain(A,8));
}
/*
    熟悉qsort的用法，注意qsort的参数，使用时要自己定义comp
    void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
    base：指向要排序的数组的第一个元素的指针。
    nitems：由 base 指向的数组中元素的个数。
    size：数组中每个元素的大小，以字节为单位。

    compar：用来比较两个元素的函数。 需要自己定义，注意这里compar的两个参数都是常量指针！！！是指针！！！不要用错
*/
