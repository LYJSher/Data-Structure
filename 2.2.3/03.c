#include <stdio.h>
#define MAXSIZE 50
/*
    遍历顺序表如果当前为x
    找到末尾第一个不为x的元素覆盖当前值
    适当修改length的值
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
            L->length = L->length - 1 - (L->length-1-j); // L->length-1-j: 末尾值为x的个数
        }
    }
}
/*
    用k元素记录不为x的个数
    并顺序扫描顺序表，将不为x的元素放到前面k个位置
    最终k即为表长
*/
void delx1(Sq *L, int x){
    int k = 0; // 记录不为x的个数
    for(int i=0; i<L->length; i++){
        if(L->data[i] != x){
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

/*
    用k记录x的元素个数
    元素不为x则将x向前移动k的位置
    最终length-k即为表长
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
    note: 如果没有1的提示，正常思路应该是
    因为删除的元素的空间总可以用且在下一个元素之前，所以考虑记录删除元素或保留元素的个数来进行操作
*/
