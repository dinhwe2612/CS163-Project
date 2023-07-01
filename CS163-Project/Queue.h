#include <iostream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    string word;
    Node* next;
};

void removeANode(Node* pHead, string s);

struct MyQueue {
    Node* head = nullptr;
    Node* tail = nullptr;

    void enqueue(string key);
    Node* dequeue();
    bool isEmpty();
};

#endif