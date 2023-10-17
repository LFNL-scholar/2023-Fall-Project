//ISBN码的识别
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    string ISBN;
    cin>>ISBN;
    int lastNum=0;
    int count=0;
    for(int i=0;i<12;i++){
        if(ISBN[i]=='-'){
            count++;
            continue;
        }else{
            
            lastNum+=(ISBN[i]-'0')*(i+1-count);
        }
    }
    lastNum=lastNum%11;
    if(lastNum==10){
        if(ISBN[12]=='X'){
            cout<<"Right";
        }else{
            for(int i=0;i<12;i++){
                cout<<ISBN[i];
            }
            cout<<'X';
        }
    }
    else if(lastNum==(ISBN[12]-'0')){
        cout<<"Right"<<endl;
    }else{
        for(int i=0;i<12;i++){
            cout<<ISBN[i];
        }
        cout<<lastNum;
    }
    return 0;
}
