#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=0;
    for(int j=0;j<n-count;j++){
        for(int i=0;i<n;i++){
            if(n<9){
                cout<<"0"<<i+1;
            }else{
                cout<<i+1;
            }
        }
        count++;
    }
    return 0;
}