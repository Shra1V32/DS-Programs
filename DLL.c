#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *first = NULL;
int len = 0;
void insert(), insertAtPos(int), display(), deletion(), deletionAtPos(int);
void display()
{
    struct node *ptr;
    ptr = first;
    printf("\n Current Array: [");
    for (ptr = first; ptr != NULL; ptr = ptr->next)
    {
        printf("%d", ptr->data);
        // ptr = ptr->next;
        if (ptr->next != NULL)
            printf(",");
    }
    printf("]\n");
}

void insert()
{
    struct node *temp, *ptr;
    int x;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("Enter a value: ");
    scanf(" %d", &x);
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if (first == NULL)
    {
        first = temp;
        len++;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        len++;
    }
}

void insertAtPos(int position)
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node *));
    if (position > len)
        printf("Invalid position\n");
    else
    {
        int x;
        printf("Enter the value: ");
        scanf("%d", &x);
        temp->data = x;
        temp->next = NULL;
        if (position == 0)
        {
            temp->next = first;
            first = temp;
            len++;
        }
        else
        {
            ptr = first;
            for (int i = 0; i < position; i++)
            {
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
            len++;
        }
    }
}

void deletion()
{
    struct node *ptr;
    ptr = first;
    if (len == 1)
    {
        printf("Element deleted is: %d", first->data);
        free(first);
        first = NULL;
        len--;
    }
    else
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("Element deleted is %d\n", ptr->next->data);
        free(ptr->next);
        len--;
    }
}

void deletionAtPos(int position)
{
    struct node *ptr1, *ptr2;
    if (position > len)
    {
        printf("Invalid Position\n");
    }
    else
    {
        ptr1 = first;
        ptr2 = first;
        for (int i = 0; i < position; i++)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        printf("Element deleted is %d\n", ptr2->data);
        ptr1->next = ptr2->next;
        free(ptr2);
        len--;
    }
}
void main()
{
    int choice, pos;
    while (1)
    {
        printf("\033[H\033[2J");
        display();
        printf("1. Insert\n2. Insert at position\n3. deletion\n4. deletion at position\n5.Exit\n6.Display");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertAtPos(pos);
            break;
        case 3:
            deletion();
            break;
        case 4:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deletionAtPos(pos);
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        default:
            break;
        }
    }
}
