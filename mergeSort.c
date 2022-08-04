#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i, lo, mi, k, temp[50];
    i = low;
    lo = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (arr[lo] <= arr[mi])
        {
            temp[i] = arr[lo];
            lo++;
        }
        else
        {
            temp[i] = arr[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
            temp[i] = arr[k];
            i++;
        }
    }

    for (k = low; k <= high; k++)
    {
        arr[k] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[50];
    int i, size;

    printf("Enter total number of elements:");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, size - 1);
    printf("After merge sort:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d   ", arr[i]);
    }

    return 0;
}