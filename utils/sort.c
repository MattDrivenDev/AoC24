#include <stdio.h>

void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void bubble_sort(int arr[], int n)
{
    int swapped, i, j;
    for (i = 0; i < n-1; i++)
    {
        swapped = 0;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void test_bubble_sort()
{
    int i;
    int test[10] = {7,4,2,1,3,9,10,8,6,5};

    printf("raw:\n");
    for (i = 0; i < 10; i++)
    {
        printf("  %d\n", test[i]);
    }

    bubble_sort(test, 10);
    
    printf("sorted:\n");
    for (i = 0; i < 10; i++)
    {
        printf("  %d\n", test[i]);
    }
}