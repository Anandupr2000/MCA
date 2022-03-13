#include <stdio.h>
#include <stdbool.h>
int a[20][20], visited[20], n, i, j,indeg[10];
void top_sort()
{
    int count = 0, inp, noOfDisplayedVertex=0;
    // reading graph
    printf("Enter the no of vertices:\n");
    scanf("%d", &n);
    printf("\n Enter graph data for %d vertices in Ajacent matrix form:\n(Enter 1 if edge present else enter 0)\n", n * n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            do
            {
                printf("\nIs there edge between %d and %d : ", i+1, j+1);
                scanf("%d", &inp);
            } while (inp < 0 || inp > 1);
            a[i][j] = inp;
        }
    // printing entered adjacency matrix
    printf("\nEnter adjacency matrix is : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // intializing array
    for (int i = 0; i < n; i++)
    {
        indeg[i] = 0;
        visited[i] = 0;
    }
    // calculating indegree of each vertex
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            indeg[i] += a[j][i];
        }
    }
    // printing sorted order
    printf("\nThe topological order is:");
    while (count<n) // loop must executed untill all unvisited vertex is travesed 
    {
        for (int k = 0; k < n; k++)
        {
            if ((indeg[k] == 0) && (visited[k] == 0))
            {
                printf(" %d", (k + 1));
                if (noOfDisplayedVertex != n - 1)
                    printf(" ->");
                visited[k] = 1;
                noOfDisplayedVertex++;
            }
            for (int i = 0; i < n; i++){
                if (a[k][i] == 1)
                    if(indeg[i]>0) indeg[i]--;
            }
        }
        count++;
    }
}
void main()
{
    top_sort();
}
