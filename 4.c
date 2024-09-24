/*4. Write a program to search an element in an array using jump search.*/

#include <stdio.h>
#include <math.h>

#define MAX 20

int jump_search(int a[], int low, int high, int val, int n)
{
    int step, i;
    step = sqrt(n);

    // Jumping through the array in blocks of size 'step'
    for (i = 0; i < n; i += step)
    {
        if (val <= a[i])
        {
            high = i;
            break;
        }
        low = i;
    }

    // Linear search within the identified block
    for (i = low; i <= high && i < n; i++)
    {
        if (a[i] == val)
            return i;
    }

    return -1;
}

int main()
{
    int arr[MAX], i, n, val, pos;

    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\nEnter the elements in sorted order : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter the value to be searched: ");
    scanf("%d", &val);

    pos = jump_search(arr, 0, n - 1, val, n);

    if (pos == -1)
        printf("\n%d is not found in the array.\n", val);
    else
        printf("\n%d is found at position %d.\n", val, pos);

    return 0;
}
