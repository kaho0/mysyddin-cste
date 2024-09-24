#include <stdio.h>
#include <math.h> // for sqrt()

// Function implementing Jump Search
int jumpSearch(int arr[], int n, int num) {
    int step = sqrt(n);  // Block size is the square root of the array size
    int prev = 0;  // Tracks the start of the current block

    // Finding the block where the element may be present
    while (step < n && arr[step - 1] < num) {
        prev = step;
        step += sqrt(n);  // Move to the next block
        if (prev >= n)    // If we exceed the array size, the element isn't present
            return -1;
    }

    // Linear search within the found block
    for (int i = prev; i < step && i < n; i++) {
        if (arr[i] == num)
            return i;  // Return the index if found
    }

    return -1;  // Return -1 if not found
}

int main() {
    int n, num;
    
    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input sorted elements of the array
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the number to search for
    printf("Enter number to search: ");
    scanf("%d", &num);
    
    // Perform Jump Search
    int result = jumpSearch(arr, n, num);
    
    // Output the result
    if (result != -1)
        printf("%d found at position %d\n", num, result + 1);
    else
        printf("%d not found\n", num);

    return 0;
}
