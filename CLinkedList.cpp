#include "CLinkedList.h"
#include <iostream>
#include <sstream>
#include <string>
#include "List.h"
#include "Node.h"

template <typename T>
CLinkedList<T>::CLinkedList() {
    head = NULL;
}



template <typename T>
CLinkedList<T>::~CLinkedList() {
    if (!head) {
        // The list is already empty, no need to do anything.
        return;
    }

    Node<T>* current = head;
    Node<T>* next;

    do {
        next = current->next;
        delete current;
        current = next;
    } while (current != head);

    // Make sure to set the head to NULL to indicate an empty list.
    head = NULL;
}



template <typename T>
void CLinkedList<T>::prepend(T data) {

    Node<T>* newNode = new Node<T>(data);

    if (!head) {
        // If the list is empty, set the new node as the head.
        head = newNode;
        head->next = head; // For a circular linked list, the head points to itself.
    } else {
        Node<T>* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head; // Make the new node circular.
        head = newNode; // Update the head to the new node.
    }


   
}



template <typename T>
void CLinkedList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (!head) {
        // If the list is empty, set the new node as both head and the next node (circular list).
        head = newNode;
        head->next = head;
    } else {
        Node<T>* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head; // Make the new node circular.
    }
}




template <typename T>
void CLinkedList<T>::remove(int index) {

        if (index < 0 || index >= length()) {
       
        return;
    }

    if (index == 0) {
        // Special case: Remove the head node.
        if (length() == 1) {
            // If the list has only one element, set head to NULL.
            delete head;
            head = NULL;
        } else {
            Node<T>* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            Node<T>* temp = head;
            head = head->next;
            lastNode->next = head;
            delete temp;
        }
    } else {
        // General case: Remove a node at the specified index.
        Node<T>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T>* toRemove = current->next;
        current->next = toRemove->next;
        delete toRemove;
    }
    
}

template <typename T>
void CLinkedList<T>::removeElements(T data) {
    Node<T>* current = head;
    int index = 0;

    while (current != NULL && index <length()-1) {
        if (current->data == data) {
            remove(index); // Remove the current occurrence of the data.
        } else {
            current = current->next;
            index++;
        }
    }
}



template <typename T>
void CLinkedList<T>::insert(T data, int index) {
    if (index < 0 || index > length()) {
        
        return;
    }

    Node<T>* newNode = new Node<T>(data);

    if (!head) {
        // If the list is empty and the index is 0 set the new node as the head.
        if (index == 0) {
            head = newNode;
            head->next = head; 
        }
    } else {
        if (index == 0) {
            // Special case: Insert at the beginning.
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        } else {
            // General case: Insert at the specified index.
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}





template <typename T>
void CLinkedList<T>::print() const {
    if (!head) {
       
       std::cout << "Empty" << std::endl;
        return;
    }

    Node<T>* current = head;

    do {
        std::cout << current->data;
        current = current->next;

        if (current != head) {
            std::cout << "->";
        }
    } while (current != head);

    std::cout << std::endl;
}



template <typename T>
void CLinkedList<T>::reverse() {
    if (!head || head->next == head) {
    
        return;
    }

    Node<T>* current = head;
    Node<T>* nextNode = NULL;
    Node<T>* previous = NULL;

    do {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    } while (current != head);

    // After the loop, 'previous' will point to the new last node.
    // Update the head to point to the new first node (previous).
    head->next = previous;  // Update the circular reference.

    // Update the head to the new last node (previous).
    head = previous;
}






template <typename T>
void CLinkedList<T>::clear() {
        while (head) {
        Node<T>* temp = head;
        if (head->next == head) {
            // If there's only one node, set head to NULL.
            head = NULL;
        } else {
            // Otherwise, update head to the next node.
            head = head->next;
            Node<T>* lastNode = head;
            while (lastNode->next != temp) {
                lastNode = lastNode->next;
            }
            lastNode->next = head;
        }
        delete temp;
    }
}



template <typename T>
int CLinkedList<T>::length() const {
     if (!head) {
        return 0; // The list is empty.
    }

    int count = 1; // Start with 1 for the head node.

    Node<T>* current = head->next;
    while (current != head) {
        count++;
        current = current->next;
    }

    return count;
}



template <typename T>
T CLinkedList<T>::get(int index) const {

        if (index < 0 || index >= length() || !head) {
        // Invalid index or an empty list, return the default value.
        return T();
    }

    Node<T>* current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
    
}



template <typename T>
T CLinkedList<T>::operator[](int index) const {
       return get(index);
}

///
template <typename T>
void CLinkedList<T>::filter(std::string op, T query) {
    if (head == NULL || (op != ">" && op != "<" && op != "==" && op != "!=" && op != ">=" && op != "<=")) {
        return; }

    int index = 0;
    int size = length();

    for (int i = 0; i < size; i++) {
        T currentData = get(index); // Use the get function to access the data at the current index.

        if ((op == ">" && currentData <= query) || (op == "<" && currentData >= query) ||
            (op == "==" && currentData != query) ||(op == "!=" && currentData == query) ||
            (op == ">=" && currentData < query) ||  (op == "<=" && currentData > query)) {

            remove(index);

        } else {
            index++;
        }
    }
}



template <typename T>
void CLinkedList<T>::swap(int index1, int index2) {
    int listSize = length();

    if (index1 < 0 || index2 < 0 || index1 >= listSize || index2 >= listSize || !head || index1 == index2) {
        // Invalid indices, empty list, or indices are the same, do nothing.
        return;
    }

    // Initialize the current node and its index
    Node<T>* current = head;
    int currentIndex = 0;

    Node<T>* node1 = NULL;
    Node<T>* node2 = NULL;

    while (currentIndex != index1 && current->next != head) {
        current = current->next;
        currentIndex++;
    }
    node1 = current;

    // Reset current node to head and index to 0
    current = head;
    currentIndex = 0;

    while (currentIndex != index2 && current->next != head) {
        current = current->next;
        currentIndex++;
    }
    node2 = current;

    if (node1 && node2) {
        // Swap the data between the two nodes.
        T tempData = node1->data;
        node1->data = node2->data;
        node2->data = tempData;
    }
}


template <typename T>
void CLinkedList<T>::slice(int start, int end) {
    if (start > end || head == NULL) {
        return;
    }
    
   
    if (start == end) {
    
        int size = length()+1;
        for (int i = 0; i < start; i++) {
            remove(0);
        }
        for (int i = 1; i < size; i++) {
            remove(1);
        }
    } else {
   
        int slice_length = end - start + 1;

     
        for (int i = start + slice_length; i < length()+1; i++) {
            remove(start + slice_length);
        }

        for (int i = 0; i < start; i++) {
            remove(0);
        }
    }
}


template <typename T>
void CLinkedList<T>::RRotate(int k) {
    if (k <= 0 || !head) {
        
        return;
    }

    int listSize = length();
    // Ensure k is within the range 
    k %= listSize;  

    if (k == 0) {
       
        return;
    }

    Node<T>* current = head;
    Node<T>* newHead = NULL;
    Node<T>* previous = head;  // Initialize previous to head.

    int currentIndex = 0;

    while (current != head || currentIndex == 0) {
        if (currentIndex == listSize - k) {
            // The node at this position will become the new head.
            newHead = current;
        }
        previous = current;
        current = current->next;
        currentIndex++;
    }

    // Update the pointers to achieve the rotation.
    previous->next = head;
    head = newHead;
}

template <typename T>
void CLinkedList<T>::LRotate(int k) {
    if (k <= 0 || !head) {
        // If k is negative or the list is empty, do nothing.
        return;
    }

    int listSize = length();
    k %= listSize;  // Ensure k is within the range of the list size.

    if (k == 0) {
        // No need to rotate if k is a multiple of the list size.
        return;
    }

    Node<T>* current = head;
    Node<T>* newHead = NULL;
    Node<T>* previous = head;  // Initialize previous to head.

    int currentIndex = 0;

    while (current != head || currentIndex == 0) {
        if (currentIndex == k) {
            // The node at this position will become the new head.
            newHead = current;
        }
        previous = current;
        current = current->next;
        currentIndex++;
    }

    // Update the pointers to achieve the rotation.
    previous->next = head;
    head = newHead;
}




template <typename T>
CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList<T>& other) {
    if (this == &other) {
      
        return *this;
    }

  
    clear();

    Node<T>* otherCurrent = other.head;

    if (otherCurrent) {
       
        head = new Node<T>(otherCurrent->data);
        head->next = head;

        Node<T>* current = head;

        otherCurrent = otherCurrent->next;

        while (otherCurrent != other.head) {
            
            current->next = new Node<T>(otherCurrent->data, head);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

    return *this;

}

template <typename T>
bool CLinkedList<T>::operator==(const CLinkedList<T>& other) const {
    if (this == &other) {
        return true;
    }
  if (this->head == NULL || other.head == NULL) {
        return false;  // One of the lists is empty or has a null head.
    }
    if (this->length() != other.length()) {
        return false;
    }

    Node<T>* thisCurrent = head;
    Node<T>* otherCurrent = other.head;

    do {
        if (thisCurrent->data != otherCurrent->data) {
            return false;  // Elements at the same position are different, so the lists are not equal.
        }
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    } while (thisCurrent != head);

    return true;  // Lists are equal if we reach this point.
}


template <typename T>
void CLinkedList<T>::operator+=(const CLinkedList<T>& other) {
    if (this == &other || other.head == NULL) {
        return;
    }

    Node<T>* otherCurrent = other.head;
    
    do {
        this->append(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    } while (otherCurrent != other.head);
}



template <typename T>
CLinkedList<T>* CLinkedList<T>::operator-(const CLinkedList<T>& other) const {
    CLinkedList<T>* result = new CLinkedList<T>;

    if (this == &other) {
        return result;
    }

    Node<T>* thisCurrent = head;

    if (thisCurrent) {
        do {
            bool foundInOther = false;
            Node<T>* otherCurrent = other.head;

            do {
                if (thisCurrent->data == otherCurrent->data) {
                    foundInOther = true;
                    break;
                }
                otherCurrent = otherCurrent->next;
            } while (otherCurrent != other.head);

            if (!foundInOther) {
              
                result->append(thisCurrent->data);
            }

            thisCurrent = thisCurrent->next;
        } while (thisCurrent != head);
    }

    return result;
}


template <typename T>
void CLinkedList<T>::removeDuplicates() {
    if (!head) {
      
        return;
    }

    Node<T>* current = head;

    do {
        Node<T>* runner = current;

        while (runner->next != head) {
            if (current->data == runner->next->data) {
                // Duplicate found
                //remove the duplicate node.
                Node<T>* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    } while (current != head);
}




template <typename T>
void CLinkedList<T>::consume(CLinkedList<T>& other) {
    if (this == &other) {
        return;
    }

    if (!other.head) {
        return;
    }

    if (!head) {
       
        head = other.head;
    } else {
        // Find the last node of the current list
        Node<T>* current = head;
        while (current->next != head) {
            current = current->next;
        }

        // Find the last node of the other list
        Node<T>* otherCurrent = other.head;
        while (otherCurrent->next != other.head) {
            otherCurrent = otherCurrent->next;
        }

        // Append the nodes from the other list to the current list
        current->next = other.head;
        otherCurrent->next = head;
    }

    // Set other's head to null to indicate it's now empty
    other.head = NULL;
}

