// 这是一道时间跨度整个国庆完成的题目，我要保留着，100%自力更生！
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int compare(int n,int arr[3][2]);
int main() {
    int n;
    cin>>n;
    int pen[3][2];
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin>>pen[i][j];
        }
    }
    cout<<compare(n,pen);
    return 0;
}

int compare(int n,int arr[3][2]){
    int Bag[3];
    for(int i=0;i<3;i++){
        Bag[i]=n/arr[i][0];
        if(n%arr[i][0]!=0){
            Bag[i]++;
        }
    }
    int Cost[3];
    for(int i=0;i<3;i++){
        Cost[i]=Bag[i]*arr[i][1];
    }
    for(int j=0;j<2;j++){
        for(int i=0;i<2;i++){
            if(Cost[i]>Cost[i+1]){
                int temp=Cost[i+1];
                Cost[i+1]=Cost[i];
                Cost[i]=temp;
            }
        }
    }
    return Cost[0];
    
}