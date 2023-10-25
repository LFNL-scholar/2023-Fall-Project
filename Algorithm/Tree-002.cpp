//设计计算二叉树中所有结点值之和的算法
#include<iostream>
#include<cmath>
using namespace std;

struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
};

int sumAllNodes(BiNode* root){
    if(root==nullptr){
        return;
    }else{
        return root->data+sumAllNodes(root->lchild)+sumAllNodes(root->rchild);
    }
}

int main(){
    BiNode* root=new BiNode();
    root->data=1;
    root->lchild=new BiNode();
    root->lchild->data=2;
    root->rchild=new BiNode();
    root->rchild->data=3;

    int totalSum=sumAllNodes(root);
    cout<<totalSum<<endl;

    delete root->lchild;
    delete root->rchild;
    delete root;

    return 0;
}