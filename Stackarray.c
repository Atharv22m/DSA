#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

void menu()
{
    printf("1.PUSH\n2.POP\n3.PRINT\n4.EXIT\n");
}

void PUSH()
{
    if(top > MAX) 
    {
        printf("Stack Overflow\n");
        return;
    }
    top += 1;
    printf("Enter value to push: ");
    int a;
    scanf("%d", &a);
    stack[top] = a;

}

void POP()
{
    if(top < 0) 
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Pop element: %d\n", stack[top]);
    top -= 1;

}

void PRINT()
{
    if(top == -1) 
    {
        printf("No Element in Stack\n");
        return;
    }
    printf("Elements in stack are:\n");
    for(int i = top;i >= 0; i--){
        printf("%d \n", stack[i]);
    }
}

int main()
{
    char ch;
    do
    {
    
    menu();
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        PUSH();
        break;
    case 2:
        POP();
        break;
    case 3:
        PRINT();
        break;
    case 4:
        return 0;
    default:
        printf("Invalid Choice\n");
        break;
    }

    printf("\nDo you want to continue(Y/N): ");
    scanf(" %c", &ch);    
    
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
