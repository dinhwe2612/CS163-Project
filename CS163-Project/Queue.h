#include <iostream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    string word;
    Node* next;
};

struct MyQueue {
    Node* head = nullptr;
    Node* tail = nullptr;

    void enqueue(string key);
    Node* dequeue();
};

#endif