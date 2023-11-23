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
};