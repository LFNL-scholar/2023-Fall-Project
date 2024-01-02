#include <iostream>

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

void revise(ListNode* &head) {
    ListNode* left = head;
    ListNode* right = head->next;  // 初始时，right 指向第二个节点
    ListNode* tmp = nullptr;

    while (right && right->next) {
        if (left->value % 2 == 0 && right->next->value % 2 == 1) {
            tmp = left->value;
            left->value = right->next->value;
            right->next->value = tmp;
            left = left->next;
            right = left->next->next;  // 更新 right 为 left 的下两个节点
        } else if (left->value % 2 == 0 && right->next->value % 2 == 0) {
            right = right->next;
        } else if (left->value % 2 == 1 && right->next->value % 2 == 1) {
            left = left->next;
        } else {
            left = left->next;
            right = right->next;
        }
    }
}

// 打印链表
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 释放链表内存
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 构建链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    // 调用 revise 函数
    revise(head);

    std::cout << "Modified Linked List: ";
    printLinkedList(head);

    // 释放链表内存
    deleteLinkedList(head);

    return 0;
}
