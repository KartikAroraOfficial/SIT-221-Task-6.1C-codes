#include <bits/stdc++.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (l > r) return -1;
    
    int mid = l + (r - l) / 2;

    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    else if (arr[mid] == x) return mid;
    else return binarySearch(arr, mid + 1, r, x);
}

void swap(int n, int x)
{
    int temp = n;
    n = x;
    x = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) 
        if (arr[i] <= pivot) count++;
 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    if (start >= end) return;
 
    int p = partition(arr, start, end);
    
    // sorting the left half
    quickSort(arr, start, p - 1);
 
    // Sorting the right half
    quickSort(arr, p + 1, end);
}



bool algorithm (int arr[], int n, int x)
{
    quickSort(arr, 0, n-1);

    for (int i(0); i < n/2; i++)
    {
        if (binarySearch(arr, 0, n-1, x-arr[i]) != -1) return true; 
    }
    return false;
}

int main()
{
    int arr[] = {5, 2, 20, 25, 578, 5792, 189};

    int x;
    std::cout << "Enter the resulting sum:" << std::endl;
    std::cin >> x;

    if (algorithm(arr, 7, x))
    {
        std::cout << "Found the numbers that lead to the sum" << std::endl;
    }
    else 
    {
        std::cout << "Couldn't find the numbers that lead to the sum!" << std::endl;
    }
}
