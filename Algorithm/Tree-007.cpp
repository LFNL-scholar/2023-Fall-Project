//设有一棵中/后序线索二叉树采用二叉链表方式存储。编写算法查找树中给定结点*p的前趋结点
//在中序线索二叉树中，节点的 lchild 和 rchild 分别用于存储其前趋和后继节点，如果一个节点没有前趋或后继，那么相应的指针将指向自身。
#include<iostream>
#include<cmath>
using namespace std;

struct BiNode{
    int data;
    BiNode* lchild; // 左线索标记
    BiNode* rchild; // 右线索标记
};

// 查找给定节点p的前趋节点
BiNode* findPredecessor(BiNode* root, BiNode* p) {
    if (root == nullptr || p == nullptr) {
        return nullptr; // 无法找到前趋节点
    }

    // 初始化前趋节点为nullptr
    BiNode* predecessor = nullptr;
    
    // 从根节点开始遍历中序线索二叉树
    while (root != nullptr) {
        if (root->ltag) {
            // 如果左孩子是线索，表示前趋节点
            if (root->lchild == p) {
                return predecessor;
            }
            predecessor = root->lchild;
        }
        root = root->lchild;
    }

    return nullptr; // 无法找到前趋节点
}

int main() {
    // 构建中序线索二叉树
    BiNode* root = new BiNode();
    root->data = 1;
    root->ltag = false; // 左线索标记
    root->rtag = false; // 右线索标记
    root->lchild = new BiNode();
    root->lchild->data = 2;
    root->lchild->ltag = true; // 左线索标记
    root->lchild->rtag = false; // 右线索标记
    root->lchild->lchild = new BiNode();
    root->lchild->lchild->data = 3;
    root->lchild->lchild->ltag = true; // 左线索标记
    root->lchild->lchild->rtag = true; // 右线索标记
    root->lchild->rchild = root; // 右孩子指向自身

    BiNode* p = root->lchild->lchild; // 需要查找前趋的节点

    BiNode* predecessor = findPredecessor(root, p);

    if (predecessor != nullptr) {
        cout << "节点 " << p->data << " 的前趋节点是 " << predecessor->data << endl;
    } else {
        cout << "找不到节点 " << p->data << " 的前趋节点" << endl;
    }

    // 释放内存
    delete root->lchild->lchild;
    delete root->lchild;
    delete root;

    return 0;
}