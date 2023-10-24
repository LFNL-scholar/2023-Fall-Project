#include<iostream>
#include<cmath>
// #include<stack>
using namespace std;

class Stack{
private:
    static const int MAX_SIZE=100;
    int data[MAX_SIZE];
    int topIndex;

public:
    Stack():topIndex(-1){} // 初始化列表

    // 将元素压入栈
    void push(int value){
        if(topIndex<MAX_SIZE-1){
            data[++topIndex]=value;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }

    // 弹出栈顶元素
    void pop(){
        if(!isEmpty()){
            --topIndex;
        }else{
            cout<<"Stack is empty"<<endl;
        }
    }

    // 获取栈顶元素
    int top(){
        if(!isEmpty()){
            return data[topIndex];
        }
        return -1;
    }

    // 检查栈是否为空
    bool isEmpty(){
        return topIndex==-1;
    }

    // 获取栈的大小
    int size(){
        return topIndex+1;
    }
};

int main(){
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout<<"Top of the stack: "<<myStack.top()<<endl;

    myStack.pop();
    cout<<"Top of the stack after pop: "<<myStack.top()<<endl;

    cout<<myStack.size()<<endl;
    return 0;
}