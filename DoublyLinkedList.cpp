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
    NodeType<T>* temp = new NodeType<T>;
    temp->next = nullptr;
    temp->back = nullptr;
    if (head == nullptr) {
        temp = head;
        std::cout << "First Insert" << std::endl;
        temp->data = item;
        std::cout << "Data assigned to temp->data" << std::endl;
        head = temp;
        std::cout << "Inserted at front" << std::endl;
    } else {
        std::cout << "To Do" << std::endl;
    }

}

/* Deletes an item from the list if it exists, otherwise prints the list
as it currently exists. */
template<class T>
void DoublyLinkedList<T>::deleteItem(T item) {
    NodeType<T>* loc = head;
    if (loc == nullptr) {
        std::cout << "You cannot delete from an empty list." << std::endl;
        return;
    } else if (lengthIs() == 1) {
        if(loc->data == item) {
            delete loc;
            head = nullptr;
            return;
        } else {
            std::cout << "Item not found." << std::endl;
        }
    }

    while (loc != nullptr) {
        if (loc == nullptr) {
            std::cout << "Item not found." << std::endl;
            return;
        } else if (loc->data == item) {
            loc->back->next = loc->next;
            delete loc;
            return;
        } else {
            loc = loc->next;
        }
    }
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
}

/* Prints the list as it currently exists in descending order. */
template<class T>
void DoublyLinkedList<T>::printReverse() {
    NodeType<T>* revPrinter = head;
    while (revPrinter != nullptr) {
        revPrinter = revPrinter->next;
    }
    while (revPrinter != nullptr) {
        std::cout << revPrinter->data << " ";
        revPrinter = revPrinter->back;
    }
}

/* Provided a range from the user, any items that exist within that range will
be deleted from the list. */
template<class T>
void DoublyLinkedList<T>::deleteSubsection() {

}

/* Returns the statistical mode of the list. */
template<class T>
void DoublyLinkedList<T>::mode() {

}

/* Swaps pairs of nodes, i.e. 1 and 2, 3 and 4, etc... */
template<class T>
void DoublyLinkedList<T>::swapAlternate() {
    NodeType<T>* oddSwap = head->next;
    NodeType<T>* evenSwap = head;
    while (oddSwap != nullptr) {
        evenSwap->next = oddSwap->next;
        oddSwap->next = evenSwap;
        oddSwap->back = evenSwap->back;
        evenSwap->back = oddSwap;
        oddSwap = oddSwap->next->next;
        evenSwap = evenSwap->next->next;
        break;
    }

} // swapAlt

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;