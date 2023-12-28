#include <iostream>

using namespace std;

void bubbleSort(int *arr, int size);

int main() {
    
    int myArray[] {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    cout << '\n';

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
     */
    
}

void bubbleSort(int *arr, int size)
{
    for (int i {size - 1}; i > 0; --i)
    {
        for (int j {0}; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
