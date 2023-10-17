//编写函数计算二叉树（采用二叉链表存储）中叶结点的个数
#include<iostream>
#include<cmath>
using namespace std;

struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
};

int countLeafNodes(BiNode* root){
    if(root==nullptr){
        return 0;
    }
    if(root->lchild==nullptr && root->rchild==nullptr){
        return 1;
    }

    int leftLeafCount=countLeafNodes(root->lchild);
    int rightLeafCount=countLeafNodes(root->rchild);

    return leftLeafCount+rightLeafCount;
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
    root->lchild->rchild=new BiNode();
    root->lchild->rchild->data=5;

    int leafNodeCount=countLeafNodes(root);
    cout<<leafNodeCount<<endl;

    delete root->lchild->lchild;
    delete root->lchild->rchild;
    delete root->lchild;
    delete root->rchild;
    delete root;

    return 0;
}