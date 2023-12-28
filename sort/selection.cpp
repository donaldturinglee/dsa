#include <iostream>

using namespace std;

void selectionSort(int *arr, int size);

int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    selectionSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
     */
    
}

void selectionSort(int *arr, int size)
{
    for (int i {0}; i < size; ++i)
    {
        int minIndex {i};
        for (int j {i + 1}; j < size; ++j)
        {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
