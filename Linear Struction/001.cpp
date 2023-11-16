//以单链表作为存储结构，实现线性表的就地逆置
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void reverseLinkedList(Node*& head) {
    Node* prev=NULL;
    Node* current=head;
    Node* next=NULL;

    while (current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

    head=prev;
}

int main() {
    Node* head=new Node{1, NULL};
    head->next=new Node{2, NULL};
    head->next->next=new Node{3, NULL};

    cout<<"原始链表：";
    Node* current=head;
    while (current!=NULL) {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;

    reverseLinkedList(head);

    cout<<"逆置链表：";
    current=head;
    while (current!=NULL) {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;

    while (head!=NULL) {
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    return 0;
}
