#include "linked_list.h"

#include <iostream>

using namespace std;

int main()
{

    // NULL
    LinkedList<int> linkedList = LinkedList<int>();

    // It will be printed backwardly
    // 43 -> NULL
    linkedList.insertHead(43);
    // 43 -> 76 -> NULL
    linkedList.insertHead(76);
    // 15 -> 43 -> 76 -> NULL
    linkedList.insertTail(15);
    // 44 -> 15 -> 43 -> 76 -> NULL
    linkedList.insertTail(44);

    // Print the list element
    cout << "First printed: " << '\n';
    linkedList.printListBackward();
    cout << "======================================\n";

    // 100 -> 44 -> 15 -> 43 -> 76 -> NULL
    linkedList.insert(4, 100);
    // 100 -> 44 -> 48 -> 15 -> 43 -> 76 -> NULL
    linkedList.insert(3, 48);
    // 100 -> 44 -> 48 -> 15 -> 43 -> 76 -> 22 -> NULL
    linkedList.insert(0, 22);

    // Print the list element
    cout << "Second printed: " << '\n';
    linkedList.printListBackward();
    cout << "======================================\n";

    return 0;
}