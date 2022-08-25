#include <stdio.h>
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
int main()
{
    int data[100];
    int n;

    printf("Enter the size of an array:\n");
    scanf("%d", &n);
    printf("Enter the element of an array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("Unsorted Array\n");
    printArray(data, n);
    quickSort(data, 0, n - 1);
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}