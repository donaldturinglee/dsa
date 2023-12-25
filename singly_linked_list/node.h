#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
    public:
        T value;
        Node<T>* next;
        Node (T value);
};

template<class T>
Node<T>::Node(T value) : value(value), next(nullptr) {}

#endif // NODE_H