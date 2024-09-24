#include <stdio.h>

int interpolationSearch(int arr[], int n, int num) {
    int low = 0, high = n - 1;
    while (low <= high && num >= arr[low] && num <= arr[high]) {
        int pos = low + (num - arr[low]) * (high - low) / (arr[high] - arr[low]);
        if (arr[pos] == num)
            return pos;
        if (arr[pos] < num)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n, num;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%d", &num);
    int result = interpolationSearch(arr, n, num);
    if (result != -1)
        printf("%d found at position %d\n", num, result + 1);
    else
        printf("%d not found\n", num);
    return 0;
}
