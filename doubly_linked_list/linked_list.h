#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <iostream>

template<class T>
class LinkedList
{
    private:
        int length;
        Node<T>* head;
        Node<T>* tail;
    public:
        LinkedList();
        ~LinkedList();
        
        // get() operation
        Node<T>* get(int index);

        // insert() operation
        void insertHead(T value);
        void insertTail(T value);
        void insert(int index, T value);

        // search() operation
        int search(T value);

        // remove() operation
        void removeHead();
        void removeTail();
        void remove(int index);

        // Additional operation
        int getLength();
        void printList();
        void printListBackward();  
};

template<typename T>
LinkedList<T>::LinkedList() : length(0), head(nullptr), tail(nullptr){}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T>* temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
}

template<class T>
void LinkedList<T>::removeTail()
{
    // Do nothing if list is empty
    if (length == 0) return;

    // If list element is only one
    // just simply call removeHead()
    if (length == 1)
    {
        removeHead();
        return;
    }

    // Save the current tail
    // to a new node
    Node<T>* node = tail;

    // Point the tail pointer
    // to the element before the current tail
    tail = tail->prev;

    // Set the new next pointer of the new tail
    // to NULL since we are going to delete
    // the last element
    tail->next = nullptr;

    // Now it's safe to remove
    // the last element
    delete node;

    // One element is removed
    --length;
}

template<class T>
void LinkedList<T>::removeHead()
{
    // Do nothing if list is empty
    if (length == 0) return;

    // Save the current head
    // to a new node
    Node<T>* node = head;

    // Point the head pointer
    // to the element next to the current head
    head = head->next;

    // Now it's safe to remove
    // the first element
    delete node;

    // If there's still any element in the list,
    // the previous pointer of the head
    // should point to NULL
    if (head != nullptr) head->prev = nullptr;

    // One element is removed
    --length;
}

template<class T>
void LinkedList<T>::remove(int index)
{
    // Do nothing if list is empty
    if (length == 0) return;

    // Do nothing if index is out of bound
    if (index < 0 || index >= length) return;

    // If removing the current head
    if (index == 0)
    {
        removeHead();
        return;
    } else if (index == length - 1)
    {
        removeTail();
        return;
    }

    // Start to traverse the list
    // from the head
    Node<T>* prev = head;

    // Find the element before
    // the selected index
    for (int i {0}; i < index - 1; ++i) prev = prev->next;

    // The removed element is after
    // the previous node
    Node<T>* node = prev->next;

    // The next node will be the neighbor of
    // previous node if the node is removed
    Node<T>* next = node->next;

    // Link the previous node to next node
    prev->next = next;
    next->prev = prev;

    // It's now safe to remove
    // the selected index element
    delete node;

    // One element is removed
    --length;
}

template<class T>
void LinkedList<T>::insertHead(T value)
{
    // Create a new node
    Node<T>* node = new Node<T>(value);

    // The current head will no longer become a head
    // so the next pointer of the new node will
    // point to the current head
    node->next = head;

    // If the current head is exist,
    // the previous pointer of the current head
    // should point to the node
    if (head != nullptr) head->prev = node;

    // The new node now become the head
    head = node;

    // If the linked list is empty
    // the tail is also the head
    if (length == 0) tail = head;

    // One element is added
    ++length;
}

template<class T>
void LinkedList<T>::insertTail(T value)
{
    // If the linked list is empty
    // just simply invoke insertHead()
    if (length == 0)
    {
        insertHead(value);
        return;
    }

    // Create a new node
    Node<T>* node = new Node<T>(value);

    // The current tail will no longer become a tail
    // so the next pointer of the current tail will
    // point to the new node
    tail->next = node;

    // Also, the previous pointer of the new node
    // should point to the current tail
    node->prev = tail;

    // The new node now become the tail
    tail = node;

    // One element is added
    ++length;
}

template<class T>
void LinkedList<T>::insert(int index, T value)
{
    // Check if the index is out of bound
    if (index < 0 || index > length) return;

    // If inserting a new head
    if (length == 0)
    {
        insertHead(value);
        return;
    }
    // if inserting a new tail
    else if (index == length)
    {
        insertTail(value);
        return;
    }

    // Start to find previous node
    // from the head
    Node<T>* prev = head;

    // Traverse the elements until
    // the selected index is found
    for (int i {0}; i < index - 1; ++i) prev = prev->next;

    // Create the next node which is
    // the element after previous node
    Node<T>* next = prev->next;

    // Create a new node
    Node<T>* node = new Node<T>(value);

    // Insert this new node between
    // the previous node and next node
    node->next = next;
    node->prev = prev;
    prev->next = node;
    next->prev = node;

    // One element is added
    ++length;
}

template<class T>
Node<T>* LinkedList<T>::get(int index)
{
    // Check if the index is out of bound
    if (index < 0 || index > length) return nullptr;

    // Start from the head
    Node<T>* node = head;

    // Iterate through the linked list elements
    // until it finds the selected index
    for (int i {0}; i < index; ++i) node = node->next;

    // Simply return the node result
    return node;
}

template<class T>
int LinkedList<T>::search(T value)
{
    // If linkedList is empty,
    // just return Not Found
    if (length == 0) return -1;
    
    // Need to count the index
    int index {0};

    // Traverse from the head node
    Node<T>* node = head;

    // Traverse until the selected value
    // is matched with the value
    // of the current position
    while (node->value != value)
    {
        ++index;
        node = node->next;
        // This will happen
        // if the selected value
        // is not found
        if (node == nullptr) return -1;
    }

    return index;
}

template<class T>
int LinkedList<T>::getLength()
{
    return length;
}

template<class T>
void LinkedList<T>::printList()
{
    Node<T>* node = head;
    while (node != nullptr)
    {
        std::cout << node->value << " <-> ";
        node = node->next;
    }
    std::cout << "NULL" << '\n';
}

template<class T>
void LinkedList<T>::printListBackward()
{
    Node<T>* node = tail;
    while (node != nullptr)
    {
        std::cout << node->value << " <-> ";
        node = node->prev;
    }
    std::cout << "NULL" << '\n';
}

#endif //LINKED_LIST_H