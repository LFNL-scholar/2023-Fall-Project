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

// ----------------------------------------------------------------------------------
// IMPORTANT NOTE: This function plays a crucial role in the program's functionality.
// ----------------------------------------------------------------------------------

void InsertSort(SqList *L){
    int j;
    for(int i=2;i<L->length;i++){   //Assuming arr[1] has been placed in position
        if(L->arr[i]<L->arr[i-1]){
            L->arr[0]=L->arr[i]; //Setting up sentries 哨兵
            for(j=i-1;L->arr[j]>L->arr[0];j--){
                L->arr[j+1]=L->arr[j];
            }
            L->arr[j+1]=L->arr[0];
        }
    }
    L->arr[0]=0;
}

void input(SqList *L,int arr[]){
    L->arr[0]=0;
    for(int i=1;i<L->length;i++){
        L->arr[i]=arr[i-1];
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
    int arr[]={5,3,4,6,2};
    list.length=6;
    input(&list,arr);
    print(&list);

    InsertSort(&list);
    print(&list);
    
    return 0;
}
