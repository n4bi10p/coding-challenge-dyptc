#include <stdio.h>

// Function to find the first occurrence of x
int firstOccurrence(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return firstOccurrence(arr, mid + 1, high, x);
        else
            return firstOccurrence(arr, low, mid - 1, x);
    }
    return -1;
}

// Function to find the last occurrence of x
int lastOccurrence(int arr[], int low, int high, int x, int n) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return lastOccurrence(arr, low, mid - 1, x, n);
        else
            return lastOccurrence(arr, mid + 1, high, x, n);
    }
    return -1;
}

// Function to count occurrences of x
int countOccurrences(int arr[], int n, int x) {
    int first = firstOccurrence(arr, 0, n - 1, x);
    if (first == -1)
        return 0; // Element not found
    int last = lastOccurrence(arr, first, n - 1, x, n);
    return last - first + 1;
}

int main() {
    int arr[] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    // Taking input from user
    printf("Enter the number to count occurrences: ");
    scanf("%d", &x);

    int count = countOccurrences(arr, n, x);
    if (count > 0)
        printf("The number %d appears %d times in the array.\n", x, count);
    else
        printf("The number %d is not found in the array.\n", x);

    return 0;
}
