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




int main(){
    SqList list;
    int arr[]={7,1,2,8,4,7,4,6,2};
    list.length=10;
    input(&list,arr);
    print(&list);

    
    return 0;
}
