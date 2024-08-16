#include <iostream>
#include <vector>

using namespace std;

// https://www.youtube.com/watch?v=8mJ-OhcfpYg - Best explanation I've found.
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    cout << "Array: [";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\b]" << endl;
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
    return 0;
}