#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
typedef enum boolean{false,true} bool;
bool visited_dfs[10];

//bfs starting

void bfs(int v) 
{ 
 for (i=1;i<=n;i++) 
 if(a[v][i] && !visited[i]) 
 q[++r]=i; 
 if(f<=r) 
 { visited[q[f]]=1; 
 bfs(q[f++]); 
 } 
} 
void bfs_sort(){
	int v; 
 printf("\n enter the number of vertices:"); 
 scanf("%d",&n); 
 for (i=1;i<=n;i++) 
 { 
 q[i]=0; 
 visited[i]=0; 
 } 
printf("\n enter graph data in matrix form:\n"); 
for (i=1;i<=n;i++) 
 for (j=1;j<=n;j++) 
 scanf("%d",&a[i][j]); 
 printf("\n Enter the starting vertex:"); 
 scanf("%d",&v); 
bfs(v); 
printf("\n The node which are reachable are:\n"); 
for (i=1;i<=n;i++) 
 if(visited[i]) 
 printf("%d\t",i); 
 else 
 printf("\n Bfs is not possible");
}

//bfs ending

//dfs starting

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
 visited_dfs[pop]=true; 
 } 
 else 
 continue; 
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
void dfs_sort(){
 	int i,j,v; 
printf("Enter the no. of nodes in the graph\n");scanf("%d",&n); 
printf("Enter the adjacency matrix \n"); 
for(i=1;i<=n;i++) 
{ 
 for(j=1;j<=n;j++) 
 { 
 scanf("%d",&a[i][j]); 
 } 
} 
printf("The adjacency matrix shown as\n"); 
for(i=1;i<=n;i++) 
{ 
 for(j=1;j<=n;j++) 
 { 
 printf("%d ",a[i][j]); 
 } 
 printf("\n"); 
} 
printf("Enter the starting node for Depth First search\n"); 
scanf("%d",&v); 
for(i=1;i<=n;i++) 
 visited_dfs[i]=false; 
dfs(v);
 }

//dfs ending

//topology sort starting

void top_sort(){
int i,j,k,n,a[10][10],indeg[10],flag[10],count=0; 
printf("Enter the no of vertices:\n"); 
scanf("%d",&n); 
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++){ 
printf("Enter row %d\n",i+1); 
for(j=0;j<n;j++) 
scanf("%d",&a[i][j]); 
} 
for(i=0;i<n;i++){ 
 indeg[i]=0; 
 flag[i]=0; 
 } 
 for(i=0;i<n;i++) 
 for(j=0;j<n;j++) 
 indeg[i]=indeg[i]+a[j][i]; 
 printf("\nThe topological order is:"); 
 while(count<n){ 
 for(k=0;k<n;k++){ 
 if((indeg[k]==0) && (flag[k]==0)){ 
 printf("%d ",(k+1)); 
 flag [k]=1; 
 } 
 for(i=0;i<n;i++){ 
 if(a[i][k]==1) 
 indeg[k]--; 
 } 
 } 
 count++; 
 } 		
}
//topology sort ending

void main(){
	int ch;
	do{
	printf("\n1)Toplogical sort\n2)Bfs\n3)Dfs\n4)Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	 case 1:
	 		top_sort();
	 		break;
	 case 2:
	 		bfs_sort();
	 		break;
	 case 3:
	 		dfs_sort();
	 		break;
	 case 4:
	 		printf("Exit");
	 		break;
	 default:
	 		printf("Enter a valid choice:");
	}
	}while(ch!=4);
}