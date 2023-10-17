//冰雹猜想
#include<iostream>
#include<cmath>
using namespace std;
void Calculate(int n);
int main()
{
	int n;
	cin>>n;
	Calculate(n);
	return 0;
}

void Calculate(int n){
	int a[500];
	int top=0;
	int temp=n;
	while(n!=1){
		if(n%2==0){
			n/=2;
		}else{
			n=n*3+1;
		}
		top++;
		a[top]=n;
	}
	while(top!=0){
		cout<<a[top]<<" ";
		top--;
	}
	cout<<temp<<" ";
}
