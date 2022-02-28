#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <cstdlib>
#include <iostream>


template<class T>
struct NodeType {
    T data;
    NodeType<T> *next;
    NodeType<T> *back;
}; // node

template<class T>
class DoublyLinkedList {
public:
    /* Constructor for the doubly linked list. */
    DoublyLinkedList();
    /* Destructor for the doubly linked list. */  
    ~DoublyLinkedList();

    /* Inserts an item into its sorted position within the list. */
    void insertItem(T &item);

    /* Deletes an item from the list if it exists, otherwise prints the list
    as it currently exists.  */
    void deleteItem(T &item);

    /* Returns the length of the list as an instance variable. */
    int lengthIs() const;

    /* Prints the list as it currently exists in ascending order. */
    void print();

    /* Prints the list as it currently exists in descending order. */
    void printReverse();

    /* Provided a range from the user, any items that exist within that range will
    be deleted from the list. */
    void deleteSubsection();

    /* Returns the statistical mode of the list. */
    void mode();

    /* Swaps pairs of nodes, i.e. 1 and 2, 3 and 4, etc... */
    void swapAlternate();


private:
    /* Head of the doubly linked list. */
    NodeType<T> *head;
}; // dll

#endif