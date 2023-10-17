//已知一棵二叉树采用二叉链表方式存储，编写算法把二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针为first，链接时用叶结点的右指针域来存放单链表指针
#include<iostream>
#include<cmath>
using namespace std;

struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
};

BiNode* first=nullptr;

void convertLeavesToLinkedList(BiNode* root,BiNode*& prev){
    if(root==nullptr){
        return;
    }
    if(root->lchild==nullptr && root->rchild==nullptr){
        if(prev==nullptr){
            first=root;
        }else{
            prev->rchild=root;
        }
        prev=root;

        // 重要：将左孩子置为nullptr，避免形成树中的环
        root->lchild=nullptr;
    }

    convertLeavesToLinkedList(root->lchild,prev);
    convertLeavesToLinkedList(root->rchild,prev);
}

int main(){
    BiNode* root = new BiNode();
    root->data = 1;
    root->lchild = new BiNode();
    root->lchild->data = 2;
    root->rchild = new BiNode();
    root->rchild->data = 3;
    root->lchild->lchild = new BiNode();
    root->lchild->lchild->data = 4;
    root->lchild->rchild = new BiNode();
    root->lchild->rchild->data = 5;
    
    BiNode* prev=nullptr;
    convertLeavesToLinkedList(root,prev);

    cout<<"Leaf node single linked list: ";
    BiNode* current=first;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->rchild;
    }
    cout<<endl;

    delete root->lchild->lchild;
    delete root->lchild->rchild;
    delete root->lchild;
    delete root->rchild;
    delete root;

    return 0;
}