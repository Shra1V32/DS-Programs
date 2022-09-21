#include <stdio.h>
#include <stdlib.h>
int a[30], len = 0;
int i;
int insertion()
{
    int ins, i = 0;
    printf("Enter the element to insert: ");
    scanf("%d", &ins);
    a[len] = ins;
    len++;
    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}

int InsertAtPos(int element, int postion)
{
    int i;
    for (i = len; i > postion; i--)
    {
        a[i] = a[i - 1];
    }
    a[postion] = element;
    len++;
}

int deletion()
{
    if (len == 0)
    {
        printf("The element cannot be deleted\n");
    }
    else
    {
        a[--len] = 0;
    }
}

int deletionAtPos()
{
    int del, pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    for (i = pos - 1; i < len - 1; i++)
    {
        a[i] = a[i + 1]; // assign arr[i+1] to arr[i]
    }
    len--;
    // a[0] = 0;
}

int main()
{
    int choice;
    int pos, element;
    while (1 != 0)
    {
        printf("\033[H\033[2J");
        printf("\n Current Array: [");
        for (i = 0; i < len; i++)
        {
            printf("%d", a[i]);
            if (i != len - 1)
                printf(",");
        }
        printf("]\n");
        printf("Length of the Array: %d\n",len);
        printf("\n1. Insert an element\n2. Insert at a position\n3. Deletion\n4. Deletion at position\n5. Exit");
        printf("\n Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            printf("Enter the Element & Position respectively: ");
            scanf("%d %d", &element, &pos);
            InsertAtPos(element, pos);
            break;
        case 3:
            deletion();
            break;
        case 4:
            deletionAtPos();
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
}
