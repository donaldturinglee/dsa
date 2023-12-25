#ifndef STACK_H
#define STACK_H

#include "node.h"

template<class T>
class Stack
{
    private:
        int height;
        Node<T>* head;
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        T top();
        void push(T value);
        void pop(); 
        void printStack();
};

template<class T>
Stack<T>::Stack() : height(0), head(nullptr) {}

template<class T>
Stack<T>::~Stack()
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
T Stack<T>::top()
{
    // Just return the value
    // of top node
    return head->value;
}

template<class T>
bool Stack<T>::isEmpty()
{
    // return true if there are no items
    // otherwise, return false
    return height <= 0;
}

template<class T>
void Stack<T>::push(T value)
{
    // Create a new node
    Node<T>* node = new Node<T>(value);

    // The next pointer of this new node
    // will point to current top node
    node->next = head;
    
    // The new node now becomes the top node
    head = node;

    // One item is added
    ++height;
}

template<class T>
void Stack<T>::pop()
{
    // Do nothing if stack is empty
    if (isEmpty()) return;

    // Prepare the current top
    // to remove
    Node<T>* node = head;

    // The new top node will be
    // the next pointer of the current top node
    head = head->next;

    // Now it's safe to remove
    // the first element
    delete node;

    // One item is removed
    --height;
}

template<class T>
void Stack<T>::printStack()
{
    Node<T>* node = head;
    while (node != nullptr)
    {
        std::cout << node->value << '\n';
        std::cout << "↓" << '\n';
        node = node->next;
    }
    std::cout << "NULL" << '\n';
}

#endif // STACK_H