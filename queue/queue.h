#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template<class T>
class Queue
{
    private:
        int length;
        Node<T>* head;
        Node<T>* tail;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        T front();
        void enqueue(T value);
        void dequeue();
};

template<class T>
Queue<T>::Queue() : length(0), head(nullptr), tail(nullptr) {}

template<class T>
Queue<T>::~Queue()
{
    Node<T>* node = head;
    while (head != nullptr)
    {
        head = head->next;
        delete node;
        node = head;
    }
}

template<class T>
T Queue<T>::front()
{
    // Just return the value
    // of head node
    return head->value;
}

template<class T>
bool Queue<T>::isEmpty()
{
    return length <= 0;
}

template<class T>
void Queue<T>::enqueue(T value)
{
    // Create a new node
    Node<T>* node = new Node<T>(value);

    if (length == 0)
    {
        // If the queue is empty
        // the new node will be
        // head and tail
        node->next = nullptr;
        head = node;
        tail = head;
    }
    else
    {
        // If there's at least one element
        // in the queue, the current tail element
        // won't be the back element anymore
        // so the next pointer of the current tail
        // point to the new node
        tail->next = node;

        // The new node now become the back position
        tail = node;
    }

    // One element is added
    ++length;
}

template<class T>
void Queue<T>::dequeue()
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

    // One element is removed
    --length;
}

#endif // QUEUE_H