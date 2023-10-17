//计算最大公约数
#include <iostream>
#include <cmath>
using namespace std;

int calculateGCD(int a,int b);
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int min,max;
    if(a>b && a>c) max=a;
    if(b>a && b>c) max=b;
    if(c>b && c>a) max=c;
    if(a<b && a<c) min=a;
    if(b<a && b<c) min=b;
    if(c<b && c<a) min=c;

    int gcd=calculateGCD(min,max);
    min /= gcd;
    max /= gcd;

    cout<<min<<"/"<<max<<endl;

    return 0;
}

int calculateGCD(int a,int b){
    if(b==0){
        return a;
    }
    return calculateGCD(b, a%b);
}