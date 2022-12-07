// Follows FIFO
// Why? Element always gets added first, and first element always gets deleted

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void del(), insert();
int queue[MAX], x, ch, rear = 0, front = 0, i, choice;
void main()
{
    while (1 != 0)
    {
        printf("\033[H\033[2J");
        printf("\n Current Array: [");
        for (i = front; i < rear; i++)
        {
            if (i != front)
                printf(",");
            printf("%d", queue[i]);
        }
        printf("]\n");
        printf("Length of the Array: %d\n", rear);
        printf("\n1. Push\n2. Pop\n3. Exit");
        printf("\n Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            exit(1);
        default:
            break;
        }
    }
}

void insert()
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("Enter the element to be inserted into the queue: ");
        scanf("%d", &x);
        queue[rear++] = x;
    }
}

void del()
{
    if (front == rear)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("%d is deleted\n", queue[front++]);
    }
}