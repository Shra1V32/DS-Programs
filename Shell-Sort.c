/*
Shell Sorting
    Step 1 − Start
    Step 2 − Initialize the value of gap size. Example: h
    Step 3 − Divide the list into smaller sub-part. Each must have equal intervals to h
    Step 4 − Sort these sub-lists using insertion sort
    Step 5 – Repeat this step 2 until the list is sorted.
    Step 6 – Print a sorted list.
    Step 7 – Stop.
*/

#include <stdio.h>
#include <stdlib.h>
void accept(), sort(), display();
int i, j, a[20], n;
void accept()
{
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter the elements into the array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void sort()
{
    int gap = n / 2, temp, swap;
    do
    {
        do
        {
            swap = 0;
            for (i = 0; i < n - gap; i++)
            {
                if (a[i] > a[i + gap])
                {
                    temp = a[i];
                    a[i] = a[i + gap];
                    a[i + gap] = temp;
                    swap = 1;
                }
            }
        } while (swap);
        gap = gap / 2;
    } while (gap);
}

void display()
{
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

int main()
{
    accept();
    sort();
    display();
}