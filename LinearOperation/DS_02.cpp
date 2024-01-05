#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 简单选择排序函数
void selectionSort(ListNode*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    ListNode* current = head;

    while (current != nullptr) {
        ListNode* minNode = current;
        ListNode* temp = current->next;

        while (temp != nullptr) {
            if (temp->val < minNode->val) {
                minNode = temp;
            }
            temp = temp->next;
        }

        // 交换当前节点和最小节点的值
        std::swap(current->val, minNode->val);

        current = current->next;
    }
}

// 生成新链表C=A∩B的函数
ListNode* getIntersection(ListNode* A, ListNode* B) {
    // 首先对两个链表进行排序
    selectionSort(A);
    selectionSort(B);

    // 创建新链表C的头节点
    ListNode* C = nullptr;
    ListNode* currentC = nullptr;

    // 使用两个指针分别指向链表A和链表B的头节点
    ListNode* currentA = A;
    ListNode* currentB = B;

    // 遍历两个链表，比较节点的值
    while (currentA != nullptr && currentB != nullptr) {
        if (currentA->val == currentB->val) {
            // 如果节点A和节点B的值相等，将该值添加到新链表C
            if (C == nullptr) {
                C = new ListNode(currentA->val);
                currentC = C;
            } else {
                currentC->next = new ListNode(currentA->val);
                currentC = currentC->next;
            }

            // 向前移动指针A和指针B
            currentA = currentA->next;
            currentB = currentB->next;
        } else if (currentA->val < currentB->val) {
            // 如果节点A的值小于节点B的值，移动指针A到下一个节点
            currentA = currentA->next;
        } else {
            // 如果节点B的值小于节点A的值，移动指针B到下一个节点
            currentB = currentB->next;
        }
    }

    return C;
}

// 释放链表内存的函数
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 创建并初始化链表A和B（假设已经有了这样的链表）
    ListNode* A = new ListNode(4);
    A->next = new ListNode(2);
    A->next->next = new ListNode(1);
    A->next->next->next = new ListNode(3);

    ListNode* B = new ListNode(2);
    B->next = new ListNode(4);
    B->next->next = new ListNode(1);

    // 调用生成新链表C的函数
    ListNode* C = getIntersection(A, B);

    // 输出新链表C的值
    std::cout << "Intersection of A and B: ";
    while (C != nullptr) {
        std::cout << C->val << " ";
        C = C->next;
    }

    // 释放链表A、B和C的内存
    deleteLinkedList(A);
    deleteLinkedList(B);
    deleteLinkedList(C);

    return 0;
}
