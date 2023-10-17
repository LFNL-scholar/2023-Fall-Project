//设计一个在二叉链表存储结构上统计二叉树中结点个数的算法
#include<iostream>
#include<cmath>
using namespace std;

struct BiNode{
    int data;
    BiNode* lchild;
    BiNode* rchild;
};

int countNodes(BiNode* root){
    if(root==nullptr){
        return 0;
    }else{
        return 1+countNodes(root->lchild)+countNodes(root->rchild);
    }
}

int main(){
    BiNode* root=new BiNode();
    root->data=1;
    root->lchild=new BiNode();
    root->lchild->data=2;
    root->rchild=new BiNode();
    root->rchild->data=3;

    int nodeCount=countNodes(root);
    cout<<nodeCount<<endl;

    delete root->lchild;
    delete root->rchild;
    delete root;

    return 0;
}
