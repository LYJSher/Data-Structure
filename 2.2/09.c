#include <stdio.h>
#define MAXSIZE 50
typedef struct{
    int data[MAXSIZE];
    int length;
}Sq;
/*
    ����˳������ֲ��ҷ�
    ���м�Ԫ�رȽϣ���С���м�Ԫ�أ�ȡǰ��������м�Ԫ�رȴ�С
    ����Ƿ��ҵ�x,���ҵ�x��midΪx������
    ��û�ҵ�x��midΪxӦ�ò����λ��
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
    if(A->data[mid] == x && mid!=A->length-1){ // �ҵ��Ҳ�Ϊ���һ��Ԫ��
        int temp;
        temp = A->data[mid];
        A->data[mid] = A->data[mid+1];
        A->data[mid+1] = temp;
        return 1;
    }
    else if(A->data[mid]!=x && A->length+1<=MAXSIZE){ // δ�ҵ����Ҽ���󲻳�����
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
// ע���±�任
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
    �±�仯����Ϥ������̫��
*/
