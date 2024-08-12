#include <stdio.h>

int main()
{
    int arr[50], pos, i, n, value;
    
    printf("Enter number of elements in the array\n");
    scanf("%d", &n);
    
    printf("Enter %d elements\n", n);
    
    for (i = 0; i < n; i++){    
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the location where you want to insert new element\n");
    scanf("%d", &pos);
    
    printf("Enter the value\n");
    scanf("%d", &value);
    
    for (i = n - 1; i >= pos - 1; i--){    
        arr[i+1] = arr[i];
    }
    
    arr[pos-1] = value;
    
    printf("Resultant array is\n");
    
    for (i = 0; i <= n; i++){    
        printf("%d\n", arr[i]);    
    }
    
    return 0;
}