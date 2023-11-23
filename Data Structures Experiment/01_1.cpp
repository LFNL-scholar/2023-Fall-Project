//以单链表作为存储结构，实现线性表的就地逆置
#include<iostream>
#include<vector>
using namespace std;

class LinkList{
private:
    struct Node{
        int data;
        Node* next;
        Node(int value):data(value),next(NULL) {}
    };
    Node* head;

public:
    LinkList():head(NULL) {}
    ~LinkList(){
        Node* current=head;
        while(current!=NULL){
            Node* temp=current;
            current=current->next;
            delete temp;
        }
    }

    void insert(int value){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=newNode;
        }else{
            Node* current=head;
            while(current->next!=NULL){
                current=current->next;
            }
            current->next=newNode;
        }
    }

    void reverse(){
        Node* prev=NULL;
        Node* current=head;
        Node* next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }

    void input(const vector<int>& vec){
        for (int value : vec) {
            insert(value);
        }
    }

    void printList(){
        Node* current=head;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

    void compare(){
        cout<<"Before List: ";
        this->printList();
        this->reverse();
        cout<<"After List: ";
        this->printList();
    }
};

int main(){
    vector<int> vector={1,2,3,4,5,6,7,8,9,10};
    LinkList List;
    List.input(vector);
    List.compare();

    return 0;
}