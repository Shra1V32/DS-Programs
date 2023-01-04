#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void front(), rear(), display(), Insertion(), deletion();
struct node *f = NULL, *r = NULL;
int main()
{
    int ch;
    while (1 != 0)
    {
        printf("\n1. Insert\n2. Deletion\n3. Front\n4. Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            Insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            front();
            break;
        case 4:
            rear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    }
}

void Insertion()
{
    int element;
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(element));
    printf("Enter the element: ");
    scanf("%d", &element);
    ptr->data = element;
    ptr->next = NULL;
    if (f == NULL && r == NULL)
    {
        f = ptr;
        r = ptr;
    }
    else
    {
        r->next = ptr;
        r = ptr; // r is already NULL, So assign
    }
}

void deletion()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (f == NULL && r == NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {
        printf("Deleted element is: %d", f->data);
        ptr = f;
        f = f->next;
        free(ptr);
    }
}

void front()
{
    // struct node *ptr;
    if (f == NULL && r == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element is: %d", f->data);
    }
}

void rear()
{
    // struct node *ptr;
    if (f == NULL && r == NULL)
        printf("Queue is empty\n");
    else
        printf("Rear element is: %d\n", r->data);
}

// Display all the elements
void display()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node*));
    if (f == NULL && r == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in the Queue are: \n");
        for (ptr = f; ptr != NULL; ptr = ptr->next)
        {
            printf("%d\t", ptr->data);
        }
    }
}