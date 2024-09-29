#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void menu() {
    printf("1.PUSH\n2.POP\n3.PRINT\n4.EXIT\n");
}

void PUSH() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &newNode->data);
    newNode->next = top;
    top = newNode;
}

void POP() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Pop element: %d\n", top->data);
    top = top->next;
    free(temp);
}

void PRINT() {
    if (top == NULL) {
        printf("No Element in Stack\n");
        return;
    }
    struct Node* temp = top;
    printf("Elements in stack are:\n");
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

int main() {
    char ch;
    do {
        menu();
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
