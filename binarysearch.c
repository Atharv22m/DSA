#include <stdio.h>

void main()
{
    int i, j, n, mid, low, high, item, found = 0;

    printf("Enter number of elements in the array\n");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d elements in ascending order:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element you want to search: \n");
    scanf("%d",&item);

    low = 0,high = n-1;
    
    for(i=0;i<(n+1)/2;i++){
        mid=(low + high)/2;
        if(item == a[mid]){
            printf("Element found at %d position\n",mid+1);
            found = 1;
            break;
        }
        else if(item < a[mid]){
            high = mid -1;
        }
        else if(item > a[mid]){
            low = mid + 1;
        }
    }
    if(found != 1){
        printf("Element not found :(\n");
    }
    
}