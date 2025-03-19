#include <stdio.h>

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {7, 2, 9, 1, 4, 10, 15, 8, 6, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    sortAscending(arr, n);
    printf("Ascending Order: ");
    printArray(arr, n);

    // Resetting the array to original for descending sort
    int originalArr[] = {7, 2, 9, 1, 4, 10, 15, 8, 6, 2, 5};
    for (int i = 0; i < n; i++) {
        arr[i] = originalArr[i];
    }

    sortDescending(arr, n);
    printf("Descending Order: ");
    printArray(arr, n);

    return 0;
}