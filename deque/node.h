#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
class Node {
    public:
        T value;
        Node<T>* prev;
        Node<T>* next;
        Node(T value);
};

template<class T>
Node<T>::Node(T value) : value(value), prev(nullptr), next(nullptr) {}

#endif // NODE_H