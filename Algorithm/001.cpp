//制杖题
//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
const int MOD = 476544743;

int* creatArray(int size);
int CalCulatedSum(int know,int specialArr[],int m);

int main(){
    int knownNum;
    cin>>knownNum;
    int specialSet[knownNum];
    int mystery;
    cin>>mystery;
    for(int i=0;i<knownNum;i++){
        cin>>specialSet[i];
    }
    int sum=CalCulatedSum(knownNum,specialSet,mystery)%MOD;
    cout<<sum<<endl;
    
}

int CalCulatedSum(int know,int specialArr[],int m){
    int sum=0;
    int* mysterySet = creatArray(m);
    for(int i=0;i<m;i++){//question
        for(int j=0;j<know;j++){
            if(mysterySet[i]%specialArr[j]==0 || specialArr[j]%mysterySet[i]==0){
                sum+=specialArr[j];
            }
        }
    } 
    delete[] mysterySet;
    return sum;
}

int* creatArray(int size){
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        arr[i]=i+1;
    }
    return arr;
}