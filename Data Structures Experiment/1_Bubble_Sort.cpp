#include<iostream>
using namespace std;
#define MAXSIZ 10

struct SqList{
    int arr[MAXSIZ+1];
    int length;
};

void swap(SqList *L,int i,int j){
    int temp=L->arr[i];
    L->arr[i]=L->arr[j];
    L->arr[j]=temp;
}

//最简单的交换排序
void SwapSort(SqList *L){
    for(int i=1;i<L->length;i++){
        for(int j=i+1;j<L->length;j++){
            if(L->arr[i]>L->arr[j]){
                swap(L,i,j);
            }
        }
    }
}

//冒泡排序
void BubbleSort(SqList *L){
    for(int i=1;i<L->length;i++){
        for(j=L->length-1;j>=i;j--){
            if(L->arr[j]>L->arr[j+1]){
                swap(L,j,j+1);
            }
        }
    }
}


int main(){

}
