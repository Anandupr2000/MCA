#include <stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
typedef enum boolean
{
    false,
    true
} bool;
bool visited_dfs[10];
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
            q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}
void bfs_sort()
{
    int v,inp;
    printf("\n enter the number of vertices:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    printf("\n enter graph data for %d vertices in Ajacent matrix form:\n(Enter 1 if edge present else enter 0)\n",n*n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++){
            do{
                printf("\nIs there edge between %d and %d : ",i,j);
                scanf("%d", &inp);
            }while(inp<0 || inp>1);
            a[i][j] = inp;
        }

    printf("\nGraph Ajacent matrix form:\n(1 denote edge is present else 0)\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    bfs(v);
    printf("\n The node which are reachable are:\n");
    for (i = 1; i <= n; i++)
        if (visited[i])
            printf("%d\t", i);
        else{
            printf("\n Bfs is not possible\n");
            break;
        }
}
void main()
{
    bfs_sort();
}
