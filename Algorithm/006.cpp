#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++){
        count+=i;
    }
    int sum=0;
    int a=n;
    for(int i=1;i<=count;i++){
        if(i/10==0){
            cout<<"0"<<i;
            sum++;
        }else{
            cout<<i;
            sum++;
        }
        if(sum==n){
            cout<<endl;
            a--;
            n=sum+a;
        }
    }
    return 0;
}