#include "stack.h"

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // NULL
    Stack<int> stack = Stack<int>();

    // Store several numbers to the stack
    stack.push(32);
    stack.push(47);
    stack.push(18);
    stack.push(59);
    stack.push(88);
    stack.push(91);

    // List the element of stack
    while (!stack.isEmpty())
    {
        // Get the top element
        cout << stack.top() << " - ";

        // Remove the top element
        stack.pop();
    }

    cout << "END" << '\n';

    return 0;
}