#include "linked_list.h"
#include <iostream>

using namespace std;
int main()
{
    LinkedList<int> linkedList = LinkedList<int>();
    // 43 -> NULL
    linkedList.insertHead(43);
    // 76 -> 43 -> NULL
    linkedList.insertHead(76);
    // 76 -> 43 -> 15 -> NULL
    linkedList.insertTail(15);
    // 76 -> 43 -> 15 -> 44 -> NULL
    linkedList.insertTail(44);
    // Print the list element
    cout << "First printed: " << '\n';
    linkedList.printList();
    cout << "======================================" << '\n';

    // 76 -> 43 -> 15 -> 44 -> 100 -> NULL
    linkedList.insert(4, 100);

    // 76 -> 43 -> 15 -> 48 -> 44 -> 100 -> NULL
    linkedList.insert(3, 48);

    // 22 -> 76 -> 43 -> 15 -> 48 -> 44 -> 100 -> NULL
    linkedList.insert(0, 22);

    // Print the list element
    cout << "Second printed: " << '\n';
    linkedList.printList();
    cout << "======================================" << '\n';

    // Get value of the second index
    // It should be 43
    cout << "Get value of the second index: " << '\n';
    Node<int>* node = linkedList.get(2);
    if (node != nullptr) cout << node->value;
    else cout << "Not Found";
    cout << '\n';
    cout << "======================================" << '\n';

    // Find the position of value 15
    // It must be 3
    cout << "The position of value 15: " << '\n';
    int pos = linkedList.search(15);
    cout << pos << '\n';
    cout << "======================================" << '\n';

    // Remove first element
    cout << "Remove the first element: " << '\n';
    linkedList.remove(0);
    // 76 -> 43 -> 15 -> 48 -> 44 -> 100 -> NULL
    linkedList.printList();
    cout << "======================================" << '\n';

    // Remove fifth element
    cout << "Remove the fifth element: " << '\n';
    linkedList.remove(4);
    // 76 -> 43 -> 15 -> 48 -> 100 -> NULL
    linkedList.printList();
    cout << "======================================" << '\n';

    // Remove tenth element
    cout << "Remove the tenth element: " << '\n';
    linkedList.remove(9);
    // 76 -> 43 -> 15 -> 48 -> 100 -> NULL
    linkedList.printList();
    cout << "======================================" << '\n';

    return 0;
}