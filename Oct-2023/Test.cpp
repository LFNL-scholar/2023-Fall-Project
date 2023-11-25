#include<iostream>

using namespace std;

int main(){
    int array[12];
    for(int i=0;i<12;i++){
        cin>>array[i];
    }

    int remain=0;
    int mom=0;
    for(int i=0;i<12;i++){
        if(array[i]<=300+remain){
            int last=300+remain-array[i];
            if(last/100>=1){
                mom+=last/100;
                remain=last%100;
            }else{
                remain=last;
            }
         
        }else{
            cout<<"-"<<i+1<<endl;
            return 0;
        }
    }

    cout<<remain+mom*120<<endl;
    return 0;
}
