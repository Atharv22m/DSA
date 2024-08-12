#include <stdio.h>

void main()
{
    int i, j, n, item, found = 0;

    printf("Enter number of elements in the array\n");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element you want to search: \n");
    scanf("%d", &item);

    for (i = 0; i < n; i++)
    {
        if (item == a[i])
        {
            printf("Element found at %d position\n", i + 1);
            found = 1;
        }
    }
    if (found != 1)
    {
        printf("Element not found :(\n");
    }
}