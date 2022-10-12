#include <stdio.h>
#include <string.h>
#define MSIZE 256
void insert(char *s1, char *s2, int n)
{
    int l1, l2, i, j;
    l1 = strlen(s1);
    l2 = strlen(s2);
    if (n > 11)
        n = 11;
    i = 11;
    j = l1 + l2;
    while (i > n - 1)
        s1[j--] = s2[i--];
    i = n;
    j = 0;
    while (s2[j])
        s1[i++] = s2[j++];
}

void delete (char *s, int p, int n)
{
    int l, i, j;
    l = strlen(s);
    i = p - 1;
    j = i + n;
    while (j <= 1)
        s[i++] = s[j++];
}

void main()
{
    char str[MSIZE], sub[MSIZE];
    int n, p;
    printf("Enter the string: ");
    gets(str);
    fflush(stdin);
    printf("Enter substring: ");
    gets(sub);
    printf("Enter position: ");
    scanf("%d", &n);
    insert(str, sub, n);
    printf("After insertion: %s\n", str);
    printf("Enter the position to delete from: ");
    scanf("%d", &p);
    printf("Enter number of characters to delete: ");
    scanf("%d", &n);
    delete (str, p, n);
    printf("\n After deletion: %s\n", str);
}