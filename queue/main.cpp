#include "queue.h"

#include <iostream>

using namespace std;

int main()
{
    // NULL
    Queue<int> queue = Queue<int>();

    // Enqueue several numbers to the queue
    queue.enqueue(35);
    queue.enqueue(91);
    queue.enqueue(26);
    queue.enqueue(78);
    queue.enqueue(44);
    queue.enqueue(12);

    while (!queue.isEmpty())
    {
        // Get the head element
        cout << queue.front() << " - ";

        // Remove the head element
        queue.dequeue();
    }

    cout << "END" << '\n';

    return 0;
}