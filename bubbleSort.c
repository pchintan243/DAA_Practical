#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void bubbleSort(int a[], int n)
{
    int temp;
    int flag;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("Your array is already sorted\n");
            break;
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
    bubbleSort(a, n);
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