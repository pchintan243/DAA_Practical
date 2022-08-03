#include <stdio.h>
#include <sys/time.h>
void selectionSort(int a[], int n)
{
    int temp;
    int position;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[position] > a[j])
            {
                position = j;
            }
        }
        if (position != i)
        {
            temp = a[position];
            a[position] = a[i];
            a[i] = temp;
        }
    }
}
int main()
{
    int i, a[100000], n;

    int t1, t2;
    struct timeval tv;
    struct timezone tt;

    printf("Enter the size of array:\n");
    scanf("%d", &n);
    printf("Enter the element:\n");
    for (i = 0; i < n; i++)
    {
        // a[i] = rand() % 10000; // average case
        a[i] = i + 1; // best case
        // a[i] = n - i       // worst case
    }
    gettimeofday(&tv, &tt);
    t1 = tv.tv_usec;
    selectionSort(a, n);
    gettimeofday(&tv, &tt);
    t2 = tv.tv_usec;
    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    printf("Time complexity: %d", t2 - t1);
    return 0;
}