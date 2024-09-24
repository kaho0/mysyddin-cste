#include <stdio.h>

void linearSearch(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            printf("%d found at position %d\n", num, i + 1);
            return;
        }
    }
    printf("%d not found in the array\n", num);
}

int main() {
    int n, num;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to search: ");
    scanf("%d", &num);
    linearSearch(arr, n, num);
    return 0;
}
