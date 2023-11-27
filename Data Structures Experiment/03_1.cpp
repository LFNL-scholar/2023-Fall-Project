//建立一棵二叉树，所有值均为整数（采用二叉链表存储方式）；
//1．输出该二叉树的前序、中序、后序遍历序列；
//2. 把所有值为负数的结点修改为正数。
#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int value):data(value),lchild(NULL),rchild(NULL) {}
};

class BinaryTree{
private:
    TreeNode* root;

    void preOrderTraversal(TreeNode* node){
        if(node!=NULL){
            cout<<node->data<<" ";
            preOrderTraversal(node->lchild);
            preOrderTraversal(node->rchild);
        }
    }

    void inOrderTraversal(TreeNode* node){
        if(node!=NULL){
            inOrderTraversal(node->lchild);
            cout<<node->data<<" ";
            inOrderTraversal(node->rchild);
        }
    }

    void postOrderTraversal(TreeNode* node){
        if(node!=NULL){
            postOrderTraversal(node->lchild);
            postOrderTraversal(node->rchild);
            cout<<node->data<<" ";
        }
    }

    void convertNegativesToPositives(TreeNode* node){
        if(node!=NULL){
            if(node->data<0){
                node->data=-node->data;
            }
            convertNegativesToPositives(node->lchild);
            convertNegativesToPositives(node->rchild);
        }
    }

public:
    BinaryTree():root(NULL) {}

    void insert(const vector<int>& values){
        for(int value : values){
            root=insertRecursive(root,value);
        }
    }

    TreeNode* insertRecursive(TreeNode* node,int value){
        if(node==NULL){
            return new TreeNode(value);
        }
        if(value<node->data){
            node->lchild=insertRecursive(node->lchild,value);
        }else if(value>node->data){
            node->rchild=insertRecursive(node->rchild,value);
        }
        return node;
    }

    void preOrder(){
        cout<<"PreOrder Traversal: ";
        preOrderTraversal(root);
        cout<<endl;
    }

    void inOrder(){
        cout<<"InOrder Traversal: ";
        inOrderTraversal(root);
        cout<<endl;
    }

    void postOrder(){
        cout<<"PostOrder Traversal: ";
        postOrderTraversal(root);
        cout<<endl;
    }

    void convertNegatives(){
        convertNegativesToPositives(root);
    }

    void output(){
        this->preOrder();
        this->inOrder();
        this->postOrder();
        this->convertNegatives();
        cout<<"--------------";
        this->preOrder();
        this->inOrder();
        this->postOrder();
    }
};

int main(){
    BinaryTree tree;
    vector<int> values={6,3,8,-1,4,7,10};
    tree.insert(values);
    tree.output();
    return 0;
}