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
            while (current!=rear) {
                Node* temp=current;
                current=current->next;
                delete temp;
            }
            delete rear;
        }
    }

    void enqueue(const vector<int>& vec){
        for (const int& value:vec){
            Node* newNode=new Node(value);
            if(rear==NULL){
                newNode->next=newNode;
                rear=newNode;
            }else{
                newNode->next=rear->next;
                rear->next=newNode;
                rear=newNode;
            }
        }
    }

    void dequeue(){
        if(rear==NULL){
            cout<<"Queue is empty."<<endl;
        }else{
            Node* front=rear->next;
            if(rear==front){
                cout<<"Deque element: "<<front->data<<endl;
                delete rear;
                rear=NULL;
            } else {
                rear->next=front->next;
                cout<<"Deque element: "<<front->data<<endl;
                delete front;
            }
        }
    }

    void printQueue(){
        if(rear==NULL) {
            cout<<"Queue is empty."<< endl;
        }else{
            Node* current=rear->next;
            do{
                cout<<current->data << " ";
                current=current->next;
            }while(current!=rear->next);
            cout<<endl;
        }
    }

    void compare(){
        cout<<"Before queue: ";
        this->printQueue();
        this->dequeue();
        cout<<"After queue: ";
        this->printQueue();

    }
};

int main(){
    vector<int> vector={1,2,3,4,5,6,7};
    CircularQueue Queue;
    Queue.enqueue(vector);
    Queue.compare();
    return 0;
}
