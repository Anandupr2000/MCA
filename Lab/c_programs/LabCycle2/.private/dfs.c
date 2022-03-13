#include <stdio.h>
#include <stdbool.h>
int visited[20], n = 4, i, j, stack[10], top = -1, popElement;
int a[4][4] = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 0, 0, 1}};
// bool found(int element){
//     for(int i=0;i<n;i++)
//         if(stack[i]==element) return true;
//     return false;
// }
void push(int element)
{
    stack[++top] = element;
    printf("\n%d is element pushed",element);
    printf("\nS => ");
        for (int i = 0; i < 6; i++)
            printf("%d ", stack[i]);
    printf("\n");
}
int pop()
{
    return stack[top--];
}
// void dfs(int v)
// {
//     int count = 0;
//     push(v);

//     // for (int i = 0; i < n; i++)
//     //     printf("%d ", stack[i]);
//     // printf("\n");
//     while (top >= 0)
//     {
//         // adding vertex to stack only if it is unvisited
//         for (i = 0; i < n; i++)
//         {
//             if (a[stack[top]][i] == 1 && visited[i] == 0)
//             {
//                 // if(!found(i)) push(i);
//                 visited[i] = 1;
//                 push(i);
//             }
//         }
//         // if(top==n) break;
//         for (i = n; i >=0; i--)
//         {
//             if (a[stack[top]][i] == 1 && visited[i] == 1)
//             {
//                 // popElement=;
//                 printf("%d -> ", pop());
//                 // visited[popElement]=1;
//             }
//         }
//     }
//     printf("\n");
//     for (int i = 0; i < n; i++)
//         printf("%d ", stack[i]);
//     // popElement=pop();
//     // if(visited[popElement]==0)
//     // {
//     //     printf("%d",popElement);
//     //     if(top<1) printf(" -> ");
//     //     visited[popElement]=1;
//     // }
//     // // else
//     // //     continue;
//     // // adding vertex to stack only if it is unvisited
//     // for(i=0;i<n;i++)
//     //     if(a[popElement][i]==1 && visited[i]==0)
//     //         push(i);
// }
void dfs(int i)
{
    int j;
    visited[i]=1;
    printf(" %d -> ",i);
    for(j=0;j<n;j++)
    {
        if(a[i][j]==1 && visited[j]==0)
            dfs(j);
    }
}
void read()
{
    int i, j, v, inp;
    // printf("Enter the no. of vertices in the graph\n");
    // scanf("%d",&n);
    // printf("\n Enter graph data for %d vertices in Ajacent matrix form:\n(Enter 1 if edge present else enter 0)\n",n*n);
    // for (i = 1; i <= n; i++)
    //     for (j = 1; j <= n; j++){
    //         do{
    //             printf("\nIs there edge between %d and %d : ",i,j);
    //             scanf("%d", &inp);
    //         }while(inp<0 || inp>1);
    //         a[i][j] = inp;
    //     }

    printf("The adjacency matrix (1 to denote edge btw vertices, 0 for no edge) shown as\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("Enter the starting node for Depth First search : ");
    scanf("%d", &v);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    dfs(v);
}
void main()
{
    read();
}
