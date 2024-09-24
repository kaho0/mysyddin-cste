#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];  // Temporary array to hold merged values

    // Merging two halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from the right half
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the sorted values back into the original array
    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;  // Find the midpoint

        mergeSort(arr, left, mid);     // Sort the left half
        mergeSort(arr, mid + 1, right); // Sort the right half

        merge(arr, left, mid, right);  // Merge the two halves
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);  // Sort the entire array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
