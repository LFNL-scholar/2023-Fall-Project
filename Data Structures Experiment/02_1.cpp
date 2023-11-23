//设从键盘输入一个整数序列：a1, a2, …，an，编写程序实现：采用链栈结构存储输入的整数，当ai ≠-1时，将ai进栈；当ai=-1时，输出栈顶整数并出栈
#include<iostream>
#include<vector>
using namespace std;

class LinkStack{
private:
    struct Node{
        int data;
        Node* next;
        Node(int value):data(value),next(NULL) {}
    };
    Node* top;

public:
    LinkStack():top(NULL) {}
    ~LinkStack(){
        while(top!=NULL){
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    void push(int value){
        Node* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
    }

    void pop(){
        if(top!=NULL){
            Node* temp=top;
            top=top->next;
            cout<<"Pop: "<<temp->data<<endl;
            delete temp;
        }else{
            cout<<"Stack is empty."<<endl;
        }
    }

    void printStack(){
        Node* current=top;
        cout<<"Stack: ";
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

    void input(){
        int input;
        while(true){
            cin>>input;
            if(input==-1){
                this->pop();
                this->printStack();
            }else{
                this->push(input);
            }
            if(input==-1){
                break;
            }
        }
    }
};

int main(){
    LinkStack Stack;
    Stack.input();
    
    return 0;
}