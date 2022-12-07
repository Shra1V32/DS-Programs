/*
Quick Sort:
    
*/
#define MAX 256
#include <stdio.h>
#include <stdlib.h>
int n, a[MAX];
void quicksort(int low, int high)
{
    int i = low, j = high, pivot = low, temp;
    if (low < high)
    {
        while (i < j)
        {
            while (a[i] <= a[pivot] && i < high)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(low, j - 1);
        quicksort(j + 1, high);
    }
}

void accept()
{
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    printf("Enter the elements into the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // Sort based on low,high
    quicksort(0, n - 1);
}

void display()
{
    printf("Displaying the elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void main()
{
    accept();
    display();
}
