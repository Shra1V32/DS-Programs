#include <stdio.h>
#include <stdlib.h>
int cost[10][10], i, j, k, n, queue[10], front = 0, rear = 0, v, vist[10], visited[10], m;
int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("\nEDGES: ");
    for (k = 1; i <= m; i++)
    {
        scanf("%d %d", &i, &j);
        cost[i][j] = 1;
    }
    printf("Enter initial vertex: ");
    scanf("%d", &v);
    printf("Visited vertices in Breadth first search:\n");
    printf("%d", v);
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[v][j] != 0 && visited[j] != 1 && vist[j] != 1)
            {
                vist[j] = 1;
                queue[rear++] = j;
            }
        }
        v = queue[front++];
        printf(" %d", v);
        k++;
        visited[v] = 1;
    }
    return 0;
}