#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   // return index where found
    }
    return -1;  // not found
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // not found
}

int main() {
    int arr[] = { 10, 23, 45, 70, 90, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 45;

    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Linear Search
    int result1 = linearSearch(arr, n, key);
    if (result1 != -1)
        printf("\nLinear Search: Element found at index %d\n", result1);
    else
        printf("\nLinear Search: Element not found\n");

    // Binary Search
    int result2 = binarySearch(arr, n, key);
    if (result2 != -1)
        printf("Binary Search: Element found at index %d\n", result2);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}
