#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function that selectes a pivot and arragens elements around it.
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as the pivot
    int smallerElementIndex = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot) // If current element is smaller or equal to the pivot.
        {
            smallerElementIndex++;
            swap(arr[smallerElementIndex], arr[j]);
            // Basically, I run through the array and if an element is smaller to the array, I swap it with the first element of the array(or second, if the first was already swapped and so on).
        }
    }

    swap(arr[smallerElementIndex + 1], arr[high]); // Swap the pivot element with the element at i + 1 position;
    // This way, the pivot will be at the right position in the sortes array. Every element on the left will be smaller than it. Every element on the right will be bigger than it.
    return (smallerElementIndex + 1); // Return the pivot so the quicksort() function know where the subarrays start and end and is able to call it recursively.
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitioningIndex = partition(arr, low, high);
        quickSort(arr, low, partitioningIndex - 1);
        quickSort(arr, partitioningIndex + 1, high);
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
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}