#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"

template<class T>
class Deque {
    private:
        int length;
        Node<T>* head;
        Node<T>* tail;
    public:
        Deque();
        ~Deque();
        T front();
        T back();
        bool isEmpty();
        void enqueue_front(T value);
        void enqueue_back(T value);
        void dequeue_front();
        void dequeue_back();
};

template<class T>
Deque<T>::Deque() : length(0), head(nullptr), tail(nullptr) {}

template<class T>
Deque<T>::~Deque()
{
    Node<T>* temp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<class T>
bool Deque<T>::isEmpty()
{
    return length <= 0;
}

template<class T>
T Deque<T>::back()
{
    // Just return the value
    // of tail node
    return tail->value;
}

template<class T>
T Deque<T>::front()
{
    // Just return the value
    // of head node
    return head->value;
}

template<class T>
void Deque<T>::enqueue_front(T value)
{
    // Create a new node
    Node<T>* node = new Node<T>(value);

    // The current head will no longer become a head
    // so the next pointer of the new node will
    // poiunt to the current head
    node->next = head;

    // If the current head is exist,
    // the previous pointer of the current head
    // should point to the node
    if (head != nullptr)
        head->prev = node;
    
    // The new node now become the head
    head = node;

    // If the deque is empty
    // The tail is also the head
    if (length == 0) tail = head;

    // One element is added
    ++length;
}

template<class T>
void Deque<T>::enqueue_back(T value)
{
    // If the deque is empty
    // just simply invoke enqueue_front()
    if (length == 0)
    {
        enqueue_front(value);
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
void Deque<T>::dequeue_front()
{
    // Do nothing if deque is empty
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

    // If there's still any element in the deque,
    // the previous pointer of the head
    // should point to nullptr
    if (head != nullptr) head->prev = nullptr;

    // One element is removed
    --length;
}

template<class T>
void Deque<T>::dequeue_back()
{
    // Do nothing if deque is empty
    if (length == 0) return;

    // If deque element is only one
    // just simply call dequeue_front()
    if (length == 1)
    {
        dequeue_front();
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

#endif // DEQUE_H