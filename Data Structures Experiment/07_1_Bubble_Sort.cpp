#include<iostream>
using namespace std;

#define MAXSIZ 10
typedef bool Status;

struct SqList{
    int arr[MAXSIZ];
    int length;
};

void swap(SqList *L,int i,int j){
    int temp=L->arr[i];
    L->arr[i]=L->arr[j];
    L->arr[j]=temp;
}

//最简单的交换排序
void SwapSort(SqList *L){
    for(int i=0;i<L->length;i++){
        for(int j=i+1;j<L->length;j++){
            if(L->arr[i]>L->arr[j]){
                swap(L,i,j);
            }
        }
    }
}

//冒泡排序
void BubbleSort(SqList *L){
    for(int i=0;i<L->length-1;i++){
        for(int j=L->length-1;j>=i;j--){
            if(L->arr[j]>L->arr[j+1]){
                swap(L,j,j+1);
            }
        }
    }
}

//经过优化的冒泡排序
void BubbleSort2(SqList *L){
    Status flag=true;
    for(int i=0;i<L->length-1 && flag;i++){
        flag=false;
        for(int j=L->length-1;j>=i;j--){
            if(L->arr[j]>L->arr[j+1]){
                swap(L,j,j+1);
                flag=true;
            }
        }
    }
}

void input(SqList *L,int arr[]){
    for(int i=0;i<L->length;i++){
        L->arr[i]=arr[i];
    }
}

void print(SqList *L){
    for(int i=0;i<L->length;i++){
        cout<<L->arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    SqList list;
    int arr[]={7,1,2,8,4,7,4,6,2};
    list.length=10;
    input(&list,arr);
    print(&list);

    SwapSort(&list);
    print(&list);
    
    BubbleSort(&list);
    print(&list);

    BubbleSort2(&list);
    print(&list);
    return 0;
}
