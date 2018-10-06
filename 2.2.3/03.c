#include <stdio.h>
#define MAXSIZE 50
/*
    ����˳��������ǰΪx
    �ҵ�ĩβ��һ����Ϊx��Ԫ�ظ��ǵ�ǰֵ
    �ʵ��޸�length��ֵ
*/
typedef struct{
    int data[MAXSIZE];
    int length;
}Sq;

void delx(Sq *L, int x){
    for(int i=0; i<L->length; i++){
        if(L->data[i] == x){
            int j=L->length-1;
            while(L->data[j] == x && j>i)
                j--;
            L->data[i] = L->data[j];
            L->length = L->length - 1 - (L->length-1-j); // L->length-1-j: ĩβֵΪx�ĸ���
        }
    }
}
/*
    ��kԪ�ؼ�¼��Ϊx�ĸ���
    ��˳��ɨ��˳�������Ϊx��Ԫ�طŵ�ǰ��k��λ��
    ����k��Ϊ��
*/
void delx1(Sq *L, int x){
    int k = 0; // ��¼��Ϊx�ĸ���
    for(int i=0; i<L->length; i++){
        if(L->data[i] != x){
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

/*
    ��k��¼x��Ԫ�ظ���
    Ԫ�ز�Ϊx��x��ǰ�ƶ�k��λ��
    ����length-k��Ϊ��
*/
void delx2(Sq *L, int x){
    int k = 0;
    for(int i=0; i<L->length; i++){
        if(L->data[i] == x)
            k++;
        else{
            L->data[i-k] = L->data[i];
        }
    }
    L->length = L->length - k;
}

int main(){
    Sq L;
    L.length = 10;
    L.data[0] = L.data[2] = L.data[4] = L.data[6] = L.data[8] = 1;
    L.data[1] = L.data[3] = L.data[5] = L.data[7] = L.data[9] = 0;
    for(int i=0; i<L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
    delx2(&L, 1);
    for(int i=0; i<L.length; i++)
        printf("%d ", L.data[i]);
    return 0;
}
/*
    note: ���û��1����ʾ������˼·Ӧ����
    ��Ϊɾ����Ԫ�صĿռ��ܿ�����������һ��Ԫ��֮ǰ�����Կ��Ǽ�¼ɾ��Ԫ�ػ���Ԫ�صĸ��������в���
*/
