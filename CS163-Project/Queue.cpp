#include "Queue.h"

void removeANode(Node* pHead, string s) {
    if (!pHead) return;
    if (pHead->word == s) {
        delete pHead;
        pHead = nullptr;
        return;
    }
    for (Node* cur = pHead; cur->next; cur = cur->next) {
        if (cur->next->word == s) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            return;
        }
    }
}

void MyQueue::enqueue(string key) {
    Node* pNew = new Node;
    pNew->word = key;
    pNew->next = nullptr;

    if (tail)
        tail->next = pNew;
    else head = pNew;
    tail = pNew;
}

Node* MyQueue::dequeue() {
    if (!head)
        return head;
    Node* tmp = head;
    head = head->next;
    if (!head) tail = nullptr;
    return tmp;
}

bool MyQueue::isEmpty() {
    return !head;
}