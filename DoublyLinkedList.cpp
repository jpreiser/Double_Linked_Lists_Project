#include <iostream>
#include <cstdlib>
#include "DoublyLinkedList.h"

/* Initializer */
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {    
    head = nullptr;
} // constructor

/* Destructor for the doubly linked list. */  
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    NodeType<T>* del = nullptr;
    while (del != nullptr) {
        del = head;
        head = head->next;
        delete(del);
    }
} // ~dll

/* Inserts an item into its sorted position within the list. */
template<class T>
void DoublyLinkedList<T>::insertItem(T item) {
    NodeType<T>* newNode = new NodeType<T>;
    newNode->next = nullptr;
    newNode->back = nullptr;
    NodeType<T>* loc = new NodeType<T>;
    loc->next = nullptr;
    loc->back = nullptr;
    if (head == nullptr) {
        newNode->data = item;
        head = newNode;
    } else if (head->data >= item) {
        newNode->data = item;
        newNode->next = head;
        newNode->next->back = newNode;
        head = newNode;
    } else {
        newNode->data = item;
        loc = head;
        while (loc->next != nullptr && loc->next->data < newNode->data) {
            loc = loc->next;
        }
        newNode->next = loc->next;
        if (loc->next != nullptr) {
            newNode->next->back = newNode;
        }
        loc->next = newNode;
        newNode->back = loc;
    }
    delete(newNode);
    delete(loc);
}

/* Deletes an item from the list if it exists, otherwise prints the list
as it currently exists. */
template<class T>
void DoublyLinkedList<T>::deleteItem(T item) {
    NodeType<T>* loc;
    if (head == nullptr) { // delete from an empty list
        std::cout << "You cannot delete from an empty list." << std::endl;
        return;
    }  

    if (head->data == item) { // delete from a list of one item
        loc = head;
        head = loc->next;
        free(loc);
        return;
    }

    loc = head;
    while (loc->next != nullptr) {
        if (loc->data != item) {
            loc = loc->next;
        }
        if (loc->data == item) {
            if (loc->next != nullptr) {
                loc->next->back = loc->back;
            }
            if (loc->back != nullptr) {
                loc->back->next = loc->next;
            }
            free(loc);
            return;
        }
    }
    std::cout << "Item not in list!" << std::endl;
} // delete

/* Returns the length of the list as an instance variable. */
template<class T>
int DoublyLinkedList<T>::lengthIs() const {
    int len = 0;
    NodeType<T>* temp = head;
    while(temp != nullptr) {
        temp = temp->next;
        len = len + 1;
    }
    return len;
}

/* Prints the list as it currently exists in ascending order. */
template<class T>
void DoublyLinkedList<T>::print() {
    NodeType<T>* printer = head;
    while(printer != nullptr) {
        std::cout << printer->data << " ";
        printer = printer->next;
    }
    std::cout << '\n'; 
}

/* Prints the list as it currently exists in descending order. */
template<class T>
void DoublyLinkedList<T>::printReverse() {
    NodeType<T>* revPrinter = head;
    while (revPrinter->next != nullptr) {
        revPrinter = revPrinter->next;
    }
    while (revPrinter != head) {
        std::cout << revPrinter->data << " ";
        revPrinter = revPrinter->back;
    }
    std::cout << revPrinter->data << std::endl;
}

/* Provided a range from the user, any items that exist within that range will
be deleted from the list. */
template<class T>
void DoublyLinkedList<T>::deleteSubsection(T lower, T upper) {
    NodeType<T>* deleter;
    deleter = head; 
    while(deleter->next != nullptr) {
        if(deleter->data >= lower && deleter->data <= upper) {
           deleteItem(deleter->data); 
        } else {
            deleter = deleter->next;
        }
    }
}

/* Returns the statistical mode of the list. */
template<class T>
void DoublyLinkedList<T>::mode() {
    NodeType<T>* most = head;
    int total, max = 0;
    T res;
    while (most!= nullptr) {
        int count = 1;
        NodeType<T>* temp = most->next;
        while (temp!= nullptr) { // check all occurences of currently tracked value
            if (most->data == temp->data) {
                count++;
            }
            temp = temp->next;
        }
        //update max if a new max occurs
        if (count > max) {
            max = count;
            res = most->data;
        }
        most = most->next;
        total++;
    }
    if (max > 1) {
        std::cout << res << std::endl;
        return;
    }
    // Print if no mode is reached and returned.
    std::cout << "No mode detected." << std::endl;
}

/* Swaps pairs of nodes, i.e. 1 and 2, 3 and 4, etc... */
template<class T>
void DoublyLinkedList<T>::swapAlternate() {
    NodeType<T>* temp = head;
    T even, odd;
    while (temp!= nullptr && temp->next != nullptr) {
        even = temp->data;
        odd  = temp->next->data;
        temp->data = odd;
        temp->next->data = even;
        temp = temp->next->next;
    }
} // swapAlt

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;