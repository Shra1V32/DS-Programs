#include <stdio.h>
#include <stdlib.h>

void push(),disptop(),display(), pop();
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void main()
{
    int ch;
    while (1 != 0)
    {
        printf("1. Push\t2. Pop\t3. Top\t4. Display\t5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            disptop();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
}

void push()
{
    int x;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the element: ");
    scanf("%d", &(ptr->data));
    ptr->next = top;
    top = ptr;
}

void pop()
{
    struct node *ptr;
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("Deleted element is %d\n", top->data);
        ptr = top;
        top = ptr->next;
        free(ptr);
    }
}

void disptop()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element:%d\n", top->data);
}

void display()
{
    struct node *ptr;
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("Elements in the stack are: \n");
        for (ptr = top; ptr != NULL; ptr = ptr->next)
        {
            printf("%d\n", ptr->data);
        }
    }
}