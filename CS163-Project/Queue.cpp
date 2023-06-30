#include "Queue.h"

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