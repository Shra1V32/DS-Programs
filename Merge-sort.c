#include <stdio.h>
int a[50], n;
int main()
{
    int i;
    printf("Enter the n value: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting the elements are: ");
    display();
    msortdiv(0, n - 1);
    printf("Afer sorting elements are: ");
    display();
    scanf("%d", &n);
}

void display()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}

void msortdiv(int low, int high)
{
    int mid;
    if (low != high)
    {
        mid = ((low + high) / 2);
    }
    msortdiv(low, mid);
    msortdiv(mid + 1, high);
    mergesort(low, mid, high);
}