/*
    To sort an array of size N in ascending order: 

    Iterate from arr[1] to arr[N] over the array. 
    Compare the current element (key) to its predecessor. 
    If the key element is smaller than its predecessor,
            compare it to the elements before. 
        Move the greater elements one position up to make space for the swapped element.
*/

#include <stdio.h>
#include <stdlib.h>
int accept(), sort(), display();
int i, j, a[30], n;
int accept()
{
    printf("Enter number of element to insert: ");
    scanf("%d", &n);
    printf("Enter the element to the array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

int sort()
{
    int temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && temp < a[j]; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

int display()
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