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
        for(int j=L->length-1;j>=i;j--){
            if(L->arr[j]>L->arr[j+1]){
                swap(L,j,j+1);
            }
        }
    }
}


int main(){
    SqList list;
    int arr[]={9,1,5,8,3,7,4,6,2};
    for(int i=0;i<10;i++){
        list.arr[i]=arr[i-1];
    }
    //SwapSort(&list);
    BubbleSort(&list);
    for(int i=0;i<10;i++){
        cout<<list.arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
