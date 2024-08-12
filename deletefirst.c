#include <stdio.h>
void main()
{
    int a[5], i,n;

    printf("Enter number of elements in the array\n");
    scanf("%d", &n);

    printf("Enter %d elements\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array Elements are : \n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }

    for (i = 0; i < 5; i++)
    {
        a[i] = a[i + 1];
    }

    printf("After Deleting first position, New array is : \n");
    for (i = 0; i < 4; i++)
    {
        printf("%d\n", a[i]);
    }
}