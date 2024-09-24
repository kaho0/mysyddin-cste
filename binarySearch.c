#include <stdio.h>

int binarySearch(int arr[], int n, int num) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, num;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%d", &num);
    int result = binarySearch(arr, n, num);
    if (result != -1)
        printf("%d found at position %d\n", num, result + 1);
    else
        printf("%d not found\n", num);
    return 0;
}
