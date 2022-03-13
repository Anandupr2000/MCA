#include <stdio.h>
#include <stdbool.h>
int a[20][20],q[10], visited[20], n = 4, i, j, f = 0, r = -1;
// int a[4][4] = {
//     {0, 1, 1, 0},
//     {0, 0, 1, 0},
//     {1, 0, 0, 1},
//     {0, 0, 0, 1}
// };

void enqueue(int v)
{
    r++;
    q[r] = v;
}
int dequeue()
{
    return q[f++];
}
bool qIsEmpty(){
    if(r==9) return true;
    else return false;
}
void bfs(int v, int end)
{
    enqueue(v);
    visited[v] = 1;
    while (!qIsEmpty())
    {
        int w = dequeue();
        if (w == end)
            return;
        for (int i = 0; i < n; i++)
        {
            if (a[w][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
void bfs_sort()
{
    int vertex, inp;
    printf("\n enter the number of vertices:");
    scanf("%d", &n);
    printf("\n enter graph data for %d vertices in Ajacent matrix form:\n(Enter 1 if edge present else enter 0)\n",n*n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            do{
                printf("\nIs there edge between %d and %d : ",i,j);
                scanf("%d", &inp);
            }while(inp<0 || inp>1);
            a[i][j] = inp;
        }
    printf("\nGraph Ajacent matrix form:\n(1 denote edge is present else 0)\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n Enter the starting vertex:");
    scanf("%d", &vertex);
    for (i = 0; i < n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    printf("\n The node order in which reachable are : \n");
    bfs(vertex, n);
    printf("\n");
    for (int k = 0; k < n; k++)
            printf("%d ", q[k]);
}
void main()
{
    bfs_sort();
}
