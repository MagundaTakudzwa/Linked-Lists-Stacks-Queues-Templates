#include "List.h"
#include <iostream>
#include <sstream>

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this == &other) {
        // Self-assignment check
        return *this;
    }

    // Clear  list
    clear();

    // Copy elements from the other list using provided functions
    int len = other.length();
    for (int i = 0; i < len; i++) {
        append(other[i]->data);
    }
    // Node<T>* otherNode = other.head;
    // while (otherNode != nullptr) {
    //     append(otherNode->data);
    //     otherNode = otherNode->next;
    // }

    return *this;
}