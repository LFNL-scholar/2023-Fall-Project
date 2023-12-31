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

void SelectSort(SqList *L){
    int min;
    for(int i=0;i<L->length-1;i++){
        min=i;
        for(int j=i+1;j<=L->length;j++){
            if(L->arr[min]>L->arr[j]){
                min=j;
            }
        }
        if(i!=min){ //  If min is not equal to i, it means that the minimum value is found, exchange
            swap(L,i,min);
        }
    }
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

    SelectSort(&list);
    print(&list);
    
    return 0;
}
