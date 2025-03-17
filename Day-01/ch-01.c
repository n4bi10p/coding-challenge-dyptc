#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort array in descending order
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to find the Kth largest element
int findKthLargest(int arr[], int n, int k) {
    if (k > 0 && k <= n) {
        sortDescending(arr, n);
        return arr[k - 1]; // Kth largest element
    }
    return -1; // Invalid K
}

int main() {
    int arr[] = {1, 4, 3, 8, 4, 9, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;

    printf("Enter the value of K to find the Kth largest element: ");
    scanf("%d", &k);

    int result = findKthLargest(arr, n, k);
    if (result != -1) {
        printf("The %dth largest element is %d\n", k, result);
    } else {
        printf("Invalid K value\n");
    }
    
    return 0;
}
