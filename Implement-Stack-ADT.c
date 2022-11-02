#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void push();
void pop();
int arr[MAX], x, ch, top = 0, i;
int main()
{
    int choice;
    int pos, element;
    while (1 != 0)
    {
        printf("\033[H\033[2J");
        printf("\n Current Array: [");
        for (i = top; i > 0 ; i--)
        {
            if (i !=  top)
                printf(",");
            printf("%d", arr[i]);
        }
        printf("]\n");
        printf("Length of the Array: %d\n", top);
        printf("\n1. Push\n2. Pop\n3. Exit");
        printf("\n Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            exit(1);
        default:
            break;
        }
    }
}
void push()
{
    if (top > MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter element to be inserted into the stack: ");
        scanf("%d", &x);
        arr[++top] = x;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The deleted element is %d", arr[top--]);
    }
}