#include "deque.h"

#include <iostream>

using namespace std;

int main()
{
    // NULL
    Deque<int> deque = Deque<int>();

    // Enqueue several numbers to the deque
    // 26
    deque.enqueue_front(26);
    // 26 -> 78
    deque.enqueue_back(78);
    // 26 -> 78 -> 44
    deque.enqueue_back(44);
    // 91 -> 26 -> 78 -> 44
    deque.enqueue_front(91);
    // 35 -> 91 -> 26 -> 78 -> 44
    deque.enqueue_front(35);
    // 35 -> 91 -> 26 -> 78 -> 44 -> 12
    deque.enqueue_back(12);

    // List the element of queue
    while (!deque.isEmpty())
    {
        // Get the head element
        cout << deque.back() << " - ";
        // Remove the head element
        deque.dequeue_back();
    }

    cout << "END" << '\n';

    return 0;
}