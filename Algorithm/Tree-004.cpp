//已知一棵二叉树采用二叉链表方式存储，编写算法按从左到右的顺序把叶结点的值(整型)存放到数组A[]中
#include<iostream>
#include<cmath>
using namespace std;

struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
};

void collectLeftValues(BiNode* root,int A[],int& index){
    if(root==nullptr){
        return;
    }
    // 递归遍历左子树
    collectLeftValues(root->lchild,A,index);

    if(root->lchild==nullptr && root->rchild==nullptr){
        A[index]=root->data;
        index++;
    }
    // 递归遍历右子树
    collectLeftValues(root->rchild,A,index);
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

    int A[100];
    int index=0;

    collectLeftValues(root,A,index);
    cout<<"Leaves_Node: ";
    for(int i=0;i<index;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    delete root->lchild->lchild;
    delete root->lchild->rchild;
    delete root->lchild;
    delete root->rchild;
    delete root;

    return 0;
}