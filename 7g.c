// merge sort
#include <stdio.h>

void show(int arr[], int low, int high)
{
    for (int i = low; i <= high; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
    printf("merging of arr[%d:%d] and arr[%d:%d]\n", low, mid, mid + 1, high);
    printf("Before Merge\n");
    show(arr, low, high);
    int i, j, k;
    int temp[high - low + 1];
    i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    k = 0;
    for (int i = low; i <= high; i++)
        arr[i] = temp[k++];
    printf("After Merge\n");
    show(arr, low, high);
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {9, 3, 7, 5, 6, 4, 8, 2};

    mergesort(arr, 0, 7);
}