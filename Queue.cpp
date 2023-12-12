#include "Queue.h"
#include "Node.h"
#include <iostream>
#include <cstddef>

template <typename T>
Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other) {
    head = NULL;
    tail = NULL;
    if (!other.head) {
        return; // Nothing to copy
    }
    Node<T>* current = other.head;
    while (current) {
        enqueue(current->data);
        current = current->next;
    }
}

template <typename T>
Queue<T>* Queue<T>::clone() const {
    Queue<T>* clonedQueue = new Queue<T>(*this);
    return clonedQueue;
}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        return T(); // Queue is empty, return default value.
    }
    Node<T>* temp = head;
    T dequeuedData = head->data;
    head = head->next;
    delete temp;
    if (!head) {
        tail = NULL;
    }
    return dequeuedData;
}

template <typename T>
const T Queue<T>::peek() const {
    if (isEmpty()) {
        return T(); // Queue is empty, return default value.
    }
    return head->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return head == NULL;
}