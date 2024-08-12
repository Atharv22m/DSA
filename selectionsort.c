#include <stdio.h>

void main()
{
    int a[50], i, j, n, temp;

    printf("Enter number of elements in the array\n");
    scanf("%d", &n);

    printf("Enter %d elements\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("After sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
}