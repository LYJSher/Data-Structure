#include <stdio.h>
#define MAXSIZE 50
/*
    �������ֻ��һ��Ԫ�أ�ֱ��return
    ��i<length/2ʱ������L.data[i]��L.data[length-i-1]��ֵ
*/

// ע���±�仯����һ��д��ȷ����������
// length��L�ĳ�Ա���ǵ���L->length

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
