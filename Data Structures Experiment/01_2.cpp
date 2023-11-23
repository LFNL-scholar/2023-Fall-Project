//创建一个递增序（有重复值）的单链表，实现删除值相同的多余结点
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
		if(head==NULL||head->data>value){
			newNode->next=head;
			head=newNode;
		}else{
			Node* current=head;
			while(current->next!=NULL && current->next->data<value){
				current=current->next;
			}
			newNode->next=current->next;
			current->next=newNode;
		}
	}

	void removeDuplicates(){
		Node* current=head;
		while(current!=NULL && current->next!=NULL){
			if(current->data==current->next->data){
				Node* temp=current->next;
				current->next=current->next->next;
				delete temp;
			}else{
				current=current->next;
			}
		}
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
        this->removeDuplicates();
        cout<<"After List: ";
        this->printList();
    }
};

int main(){
    vector<int> vector={1,2,2,3,3,3,4,5,5,6,7};
    LinkList List;
    List.input(vector);
	List.compare();

    return 0;
}