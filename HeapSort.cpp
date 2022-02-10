#include <stdio.h>
#include <iostream>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void maxheapify(int *arr, int i, int size)
{
    int largest = i, left, right;
    left = (2 * i) + 1;
    right = (2 * i) + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        maxheapify(arr, largest, size);
    }
}
void createandbuildheap(int *arr, int size)
{
    int i;

    for (i = (size - 2) / 2; i >= 0; i--)
        maxheapify(arr, i, size);
}

void heapsort(int *arr, int size)
{
    createandbuildheap(arr, size);
    while (size > 1)
    {
        swap(&arr[0], &arr[size - 1]);
        --size;
        maxheapify(arr, 0, size);
    }
}

int main()
{
    int i, arr[100], n;
    char again;

    printf("Enter number of elements in an array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    heapsort(arr, n);
    printf("The given elements in sorted order are:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    printf("Do you want use other type of Sorting Algorithm? (Y/N)\n");
            scanf("%s", again);

    return 0;
}
