#include "Stack.h"
#include <iostream>
template <typename T>
Stack<T>::Stack() {
    top = NULL;
}
  
// template <typename T>
// Stack<T>::Stack(const Stack<T>& other) {
//     top = NULL;
//     if (!other.top) {
//         return; // Nothing to copy
//     }
//     Node<T>* current = other.top;
//     while (current) {
//         push(current->data);
//         current = current->next;
//     }
// }
template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
    top = NULL;
    if (!other.top) {
        return; // Nothing to copy
    }
    
    // Create a temporary stack to reverse the order of elements.
    Stack<T> tempStack;
    Node<T>* current = other.top;
    
    while (current) {
        tempStack.push(current->data);
        current = current->next;
    }

    // Now, copy the elements from the temporary stack to the new stack.
    while (!tempStack.isEmpty()) {
        push(tempStack.pop());
    }
}
template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(T data) {
    top = new Node<T>(data, top);
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        return T(); // Stack is empty, return default value.
    }
    Node<T>* temp = top;
    T poppedData = top->data;
    top = top->next;
    delete temp;
    return poppedData;
}

template <typename T>
const T Stack<T>::peek() const {
    if (isEmpty()) {
        return T(); // Stack is empty, return default value.
    }
    return top->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == NULL;
}