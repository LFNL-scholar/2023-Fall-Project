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

void ShellSort(SqList *L){
    int j;
    int increment=L->length;
    do{
        increment=increment/3+1; // incremental sequence 增量序列
        for(int i=increment+1;i<L->length;i++){
            if(L->arr[i]<L->arr[i-increment]){
                L->arr[0]=L->arr[i];
                for(j=i-increment;j>0 && L->arr[0]<L->arr[j];j-=increment){
                    L->arr[j+increment]=L->arr[j];
                }
                L->arr[j+increment]=L->arr[0];
            }
        }
    }while(increment>1);
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
    int arr[]={9,1,5,8,3,7,4,6,2};
    list.length=10;
    input(&list,arr);
    print(&list);

    ShellSort(&list);
    print(&list);
    
    return 0;
}
