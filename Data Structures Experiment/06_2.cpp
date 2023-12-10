//设待排序的记录序列用单链表作存储结构，编写简单选择排序的程序
#include<iostream>
#include<vector>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int value):data(value),next(NULL) {}
};

class SelectionSort{
private:
    ListNode* head;

    ListNode* findMin(ListNode* start){
        ListNode* minNode=start;
        ListNode* current=start->next;
        while(current!=NULL){
            if(current->data<minNode->data){
                minNode=current;
            }
            current=current->next;
        }
        return minNode;
    }

    void swap(ListNode* node1,ListNode* node2){
        int temp=node1->data;
        node1->data=node2->data;
        node2->data=temp;
    }

public:
    SelectionSort():head(NULL) {}

    void insert(vector<int>& values){
        for(int value:values){
            ListNode* newNode=new ListNode(value);
            newNode->next=head;
            head=newNode;
        }
    }

    void sort(){
        if(head==NULL || head->next==NULL){
            return;
        }

        ListNode* current=head;
        
        while(current->next!=NULL){
            ListNode* minNode=findMin(current);
            swap(current,minNode);
            current=current->next;
        }
    }

    void display(){
        ListNode* current=head;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};

int main(){
    SelectionSort list;
    vector<int> values={5,2,8,1,3};
    list.insert(values);
    cout << "Original List: ";
    list.display();
    list.sort();

    cout << "Sorted List: ";
    list.display();
    
    return 0;
}
