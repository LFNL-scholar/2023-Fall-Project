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

    void Input(const vector<int>& vec){
        for (int value : vec) {
            append(value);
        }
    }

    void append(int value){
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

    void printList(){
        Node* current=head;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }

    void reverse(){
        Node* prev=NULL;
        Node* current=head;
        Node* next=NULL;
        while(current!=NULL){
            next=current->next; // 将 next 指针指向当前节点的下一个节点
            current->next=prev; // 反转当前节点的指针，指向前一个节点
            prev=current;
            current=next;
        }
        head=prev;
    }
};

int main(){
    vector<int> vector={1,2,3,4,5,6,7,8,9,10};
    LinkList List;
    List.Input(vector);

    cout<<"Before List: ";
    List.printList();
    List.reverse();
    cout<<"After List: ";
    List.printList();

    return 0;
}