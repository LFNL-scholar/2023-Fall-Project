//建立一棵二叉树，所有值均为整数（采用二叉链表存储方式）；
//1．输出该二叉树的前序、中序、后序遍历序列；
//2. 把所有值为负数的结点修改为正数。
#include<iostream>
using namespace std;

class BinaryTree{
public:
    class TreeNode{
    public:
        int data;
        TreeNode* lchild;
        TreeNode* rchild;
        TreeNode(int value):data(value),lchild(NULL),rchild(NULL) {}
    };
    TreeNode* root;

    BinaryTree():root(NULL) {}

    void insert(int value){
        
    }

private:
    TreeNode* insertNode(TreeNode* node,int value){
        if(node==NULL){
            return new TreeNode(value);
        }
        if(value<node->data){
            node->lchild=insertNode(node->lchild,value); // 递归将新值插入到当前节点的左子树
        }else{
            node->rchild=insertNode(node->rchild,value);
        }
        return node;
    }
};
