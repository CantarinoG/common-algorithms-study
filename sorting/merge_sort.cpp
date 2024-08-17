#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{                            // Merge two subarrays.
    int n1 = mid - left + 1; // Number of elements on the left subarray.
    int n2 = right - mid;    // Number of elements on the right.

    int *L = new int[n1];
    int *R = new int[n2];

    // Copy data to the temporary arrays L and R.
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    // Merge the temporary arrays back into arr.
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remainig elements of L
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) // Basically, only if there is more than one element.
    {
        int mid = left + (right - left) / 2; // Getting middle index.

        mergeSort(arr, left, mid);      // Run for the left half of the array.
        mergeSort(arr, mid + 1, right); // Run for the right half of the array.

        merge(arr, left, mid, right); // Merge the sorted halves
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
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}