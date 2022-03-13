#include<stdio.h>
int a[20][20],visited[20],n,i,j;
typedef enum boolean{false,true} bool;
bool visited_dfs[10];
void dfs(int v) 
{ 
    int i,stack[10],top=-1,pop; 
    top++; 
    stack[top]=v; 
    while(top>=0) 
    { 
        pop=stack[top]; 
        top--;
        if(visited_dfs[pop]==false) 
        { 
            printf("%d",pop);
            if(top<1) printf(" -> ");
            visited_dfs[pop]=true; 
        } 
        else 
            continue; 
        // adding vertex to stack only if it is unvisited
        for(i=n;i>=1;i--) 
        { 
            if(a[pop][i]==1 && visited_dfs[i]==false) 
            { 
                top++; 
                stack[top]=i; 
            } 
        } 
    }
}
void read(){
    int i,j,v,inp; 
    printf("Enter the no. of vertices in the graph\n");
    scanf("%d",&n); 
    printf("\n Enter graph data for %d vertices in Ajacent matrix form:\n(Enter 1 if edge present else enter 0)\n",n*n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++){
            do{
                printf("\nIs there edge between %d and %d : ",i,j);
                scanf("%d", &inp);
            }while(inp<0 || inp>1);
            a[i][j] = inp;
        }

    printf("The adjacency matrix (1 to denote edge btw vertices, 0 for no edge) shown as\n"); 
    for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
            printf("%d ",a[i][j]); 
        printf("\n"); 
    } 
    printf("Enter the starting node for Depth First search : "); 
    scanf("%d",&v); 
    for(i=1;i<=n;i++) 
        visited_dfs[i]=false; 
    dfs(v);
}
void main(){
    read();
}
