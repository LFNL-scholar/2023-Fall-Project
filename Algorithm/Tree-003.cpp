//设计算法交换二叉树中所有结点的左右子树
#include<iostream>
#include<cmath>
using namespace std;

struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
};

void swapLeftAndRight(BiNode* root){
    if(root==nullptr){
        return;
    }

    BiNode* temp=root->lchild;
    root->lchild=root->rchild;
    root->rchild=temp;

    swapLeftAndRight(root->lchild);
    swapLeftAndRight(root->rchild);
}

void inOrderTraversal(BiNode* root){
    if(root==nullptr){
        return; //自动返回到调用该函数的上一级
    }

    inOrderTraversal(root->lchild);
    cout<<root->data<<" ";
    inOrderTraversal(root->rchild);
}

int main(){
    BiNode* root=new BiNode();
    root->data=1;
    root->lchild=new BiNode();
    root->lchild->data=2;
    root->rchild=new BiNode();
    root->rchild->data=3;
    root->lchild->lchild=new BiNode();
    root->lchild->lchild->data=4;
    root->rchild->rchild=new BiNode();
    root->rchild->rchild->data=5;

    cout<<"Before Swap: ";
    inOrderTraversal(root);
    cout<<endl;

    swapLeftAndRight(root);

    cout<<"After Swap: ";
    inOrderTraversal(root);
    cout<<endl;

    delete root->lchild;
    delete root->rchild;
    delete root;

    return 0;
}