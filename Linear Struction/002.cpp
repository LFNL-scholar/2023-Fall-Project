//以单链表作为存储结构，实现线性表的就地逆置
#include<iostream>
using namespace std;
const int MaxSize=100;
class SeqList{	
private:
	int data[MaxSize];
    int length;
public:
	SeqList() { length=0;}
	SeqList(int a[],int n);
	void print();
	void Reverse();
};

SeqList::SeqList(int a[],int n){	
    if(n>MaxSize)  throw"参数非法";
	for(int i=0;i<n;i++){ 
        data[i]=a[i];
	}
	length=n;
}

void SeqList::print(){	
    for(int i=0;i<length;i++){	 
        cout<<data[i]<<" ";
	}
	cout<<endl;
}
void SeqList::Reverse(){
	int temp=0;
	for(int i=0;i<length/2;i++)
	{	temp=data[i];
        data[i]=data[length-1-i];
        data[length-1-i]=temp;
	}
}

int main(){	
    int a[10]={1,2,3,4,5,6,7,8,9,10};
	SeqList m(a,10);
	m.print();
	m.Reverse();
	m.print();	
    return 0;
}
