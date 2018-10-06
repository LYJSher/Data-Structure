#include <stdio.h>
#define MAXSIZE 50
/*
    如果表中只有一个元素，直接return
    当i<length/2时，互换L.data[i]和L.data[length-i-1]的值
*/

// 注意下标变化，请一次写正确！！！！！
// length是L的成员，记得用L->length

typedef struct{
    int data[MAXSIZE];
    int length;
}Sq;

void rev(Sq *L){
    int temp;
    if(L->length == 1)
        return;
    for(int i=0; i < (L->length)/2; i++){
        temp = L->data[i];
        L->data[i] = L->data[L->length-i-1];
        L->data[L->length-i-1] = temp;
    }
}

int main(){
    Sq L1, L2;
    L1.length = 5;
    L2.length = 4;
    for(int i=0; i<5; i++)
        L1.data[i] = i;
    for(int i=0; i<4; i++)
        L2.data[i] = i;
    rev(&L1);
    rev(&L2);
    for(int i=0; i<5; i++)
        printf("%d ", L1.data[i]);
    printf("\n");
    for(int i=0; i<4; i++)
        printf("%d ", L2.data[i]);
}
