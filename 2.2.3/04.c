#include <stdio.h>
#define MAXSIZE 50
/*
    ���s>t����return0
    ��������˳�����¼С��s�����һ���±�p�ʹ���t�ĵ�һ���±�q
    ��q�����Ժ�����ĩβ��Ԫ��˳���ƶ���p��
    �޸ı�
*/

// �Ȼ���ͼ����ֽ�������д����
typedef struct {
    int data[MAXSIZE];
    int length;
}Sq;

int del_s_t(Sq *L, int s, int t){
    if(L->length == 0 || s>t)
        return 0;
    int count = 0;
    int p, q = -1; // ��¼���һ��С��sֵ���±�͵�һ������tֵ���±�
    for(int i=0; i<L->length; i++){
        if(L->data[i] < s)
            p = i;
        if(L->data[i] > t){
            q = i;
            count = q-p-1;
            while(i<L->length){
                L->data[p+1] = L->data[i];
                p++;
                i++;
            }
        }
    }
    L->length = L->length - count;
    return 1;
}

int del_s_t2(Sq *L, int s, int t){
    int i, j;
    if(s>t || L->length == 0)
        return 0;
    for(i=0; L->data[i] < s; i++); // Ѱ�ҵ�һ����С��s��ֵ
    if(i>=L->length)
        return 0; // s����L�е�����ֵ������
    for(j=i; L->data[j] <= t; j++); // Ѱ�ҵ�һ������t��ֵ ע�⣺��Ϊ��һ������t������<=
    while(j<L->length){
        L->data[i++] = L->data[j++];
    }
    L->length = i; // iΪ���һ��Ԫ���±�
}
int main(){
    Sq L1, L2;
    L2.length = 0;
    L1.length = 10;
    for(int i=0; i<10; i++){
        L1.data[i] = i;
        printf("%d ",L1.data[i]);
    }
    printf("\n");
    if(del_s_t2(&L1, 5, 8))
        for(int i=0; i<L1.length; i++)
            printf("%d ",L1.data[i]);
    else{
        printf("error\n");
    }
    return 0;
}

