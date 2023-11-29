//构造一棵二叉排序树，从小到大输出树中所有值大于x的结点值
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

class BinarySearchTree{
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node,int value){
        if(node==NULL){
            return new TreeNode(value);
        }
        if(value<node->data){
            node->lchild=insert(node->lchild,value);
        }else if(value>node->data){
            node->rchild=insert(node->rchild,value);
        }
        return node;
    }

    void printGreaterValues(TreeNode* node,int x){
        if(node==NULL){
            return;
        }
        printGreaterValues(node->rchild,x);
        if(node->data>x){
            cout<<node->data<<" ";
        }
        printGreaterValues(node->lchild,x);
    }

public:
    BinarySearchTree():root(NULL) {}

    void insert(int value){
        root=insert(root,value);
    }

    void printGreaterValues(int x){
        printGreaterValues(root,x);
        cout<<endl;
    }

    void insertValues(const vector<int>& values){
        for(int value:values){
            insert(value);
        }
    }
};

int main(){
    vector<int> values={8,3,10,1,6,14,4,7,13};
    BinarySearchTree bst;
    bst.insertValues(values);
    int x=6;
    cout<<"树中所有值大于 "<<x<<" 的节点是：";
    bst.printGreaterValues(x);
    return 0;
}