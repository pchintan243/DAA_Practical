#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void merge(int arr[], int lb, int mid, int ub)
{
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 = ub - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[lb + i];
    }

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = lb;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;

        mergeSort(arr, lb, mid);

        mergeSort(arr, mid + 1, ub);

        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int i, n, arr[20000];
    int t1, t2;
    struct timeval tv;
    struct timezone tz;

    printf("Enter the Numbers You Want : ");
    scanf("%d", &n);

    printf("Enter The Numbers : ");
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000; //  Random
                                // arr[i] = n - i; //  Worstcase
                                // arr[i] = i + 1; // Best case
    }
    gettimeofday(&tv, &tz);
    t1 = tv.tv_usec;
    mergeSort(arr, 0, n - 1);
    gettimeofday(&tv, &tz);
    t2 = tv.tv_usec;

    printf("\n Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n The time required for execution of algo is %d", t2 - t1);

    return 0;
}
