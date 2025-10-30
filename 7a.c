// bubble sort
#include <stdio.h>
void show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void bubble(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("After %d pass\n", i + 1);
        show(arr, n);
    }
}
void selection(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        printf("After %d pass\n", i + 1);
        show(arr, n);
    }
}
void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        printf("key= %d\n", key);
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("After %d pass\n", i + 1);
        show(arr, n);
    }
}
int main()
{
    int arr[] = {2, 6, 5, 1, 0, 4, 9, 7};
    int n = 8;
    show(arr, n);
    // bubble(arr, n);
    // selection(arr, n);
    insertion(arr, n);
}