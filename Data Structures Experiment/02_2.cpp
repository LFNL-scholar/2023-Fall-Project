//设以不带头结点的循环链表表示队列，并且只设一个指针指向队尾结点，但不设头指针。编写相应的入队和出队程序
#include<iostream>
#include<vector>
using namespace std;

class CircularQueue{
private:
    struct Node{
        int data;
        Node* next;
        Node(int value):data(value),next(NULL) {}
    };
    Node* rear;

public:
    CircularQueue():rear(NULL) {}
    ~CircularQueue(){
        if(rear!=NULL){
            Node* current=rear->next;
            while(current!=rear){
                Node* temp=current;
                current=current->next;
                delete temp;
            }
            delete rear;
        }
    }

    void enqueue(int value){
        Node* newNode=new Node(value);
        if(rear==NULL){
            newNode->next=newNode; // 将新节点的 next 指针指向自己
            rear=newNode; // 将 rear 指针指向新节点，形成一个只有一个节点的循环链表
        }else{
            newNode->next=rear->next;
            rear->next=newNode;
            rear=newNode;
        }
    }

    void dequeue(){
        if(rear==NULL){
            cout<<"Queue is empty."<<endl;
        }else{
            Node* front=rear->next;
            if(rear==front){
                delete rear;
                rear=NULL;
            }else{
                rear->next=front->next;
                delete front;
            }
        }
    }

    void printQueue(){
        if(rear==NULL){
            cout<<"Queue is empty."<<endl;
        }else{
            Node* current=rear->next;
            do{
                cout<<current->data<<" ";
                current=current->next;
            }while(current!=rear->next);
            cout<<endl;
        }
    }

    void input()
};

int main(){
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<"Queue: ";
    queue.printQueue();
    queue.dequeue();
    cout<<"Queue after dequeue: ";
    queue.printQueue();
    return 0;
}