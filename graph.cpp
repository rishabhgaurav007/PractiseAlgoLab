#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int rear=-1,front=0;
void insert_queue(int v)
{
	if(rear==MAX-1)
	printf("\nQueue Overflow");
	else
	queue[++rear]=v;
}

int Empty_queue()
{
	if(front-rear==1)
	return 1;
	else
	return 0;
}

int delete_queue()
{
	if(front-rear==1)
	printf("\nQueue is Empty");
	else
	return queue[front++];
}

void construct_directed(int n)
{
	int max_edge,i,j,origin,destination;
	max_edge=n*(n-1);
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	adj[i][j]=0;
	for(i=1;i<=max_edge;i++)
	{
	printf("\nEnter origin and destination of edge %d (-1 -1 to quit)",i);
	scanf("%d%d",&origin,&destination);
	if(origin==-1 && destination==-1)
	break;
	if(origin>=n || destination>=n || origin<0 || destination<0)
	{
	printf("\nInvalid vertex");
	i--;
	}
	else
	{
	adj[origin][destination]=1;
	}
	}
}

void construct_undirected(int n)
{
	int max_edge,i,j,origin,destination;
	max_edge=n*(n-1)/2;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	adj[i][j]=0;
	for(i=1;i<=max_edge;i++)
	{
	printf("\nEnter origin and destination of edge %d (-1 -1 toquit)",i);
	scanf("%d%d",&origin,&destination);
	if(origin==-1 && destination==-1)
	break;
	if(origin>=n || destination>=n || origin<0 || destination<0)
	{
	printf("\nInvalid vertex");
	i--;
	}
	else
	{
	adj[origin][destination]=1;
	adj[destination][origin]=1;
	}
	}
}

void DFS(int v,int n)
{
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<n;i++)
	{
	if(adj[v][i]==1 && visited[i]==0)
	DFS(i,n);
	}
}

void DF_Traversal(int n)
{
	int v;
	for(v=0;v<n;v++)
	visited[v]=0;
	printf("\nEnter the 1st vertex");
	scanf("%d",&v);
	DFS(v,n);
	for(v=0;v<n;v++)
	{
	if(visited[v]==0)
		DFS(v,n);
	}
	printf("\n");
}

void display(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",adj[i][j]);
	printf("\n");
	}
}
void BFS(int v,int n)
{
	int i;
	insert_queue(v);
	while(!Empty_queue())
	{
	v=delete_queue();
	if(!visited[v])
	{
	visited[v]=1;
	printf("%d ",v);
	for(i=0;i<n;i++)
	{
	if(adj[v][i]==1)
	{
	insert_queue(i);
	}
	}
	}
	}
}

void BF_Traversal(int n)
{
	int v;
	for(v=0;v<n;v++)
	visited[v]=0;
	printf("\nEnter the starting vertex:");
	scanf("%d",&v);
	BFS(v,n);
	for(v=0;v<n;v++)
	{
	if(visited[v]==0)
	BFS(v,n);
	}
printf("\n");
}
void main()
{
int option,n;
printf("1.Construct Undirected Graph");
printf("\n2.Construct Directed Graph");
printf("\n3.Display Adjecancy Matrix");
printf("\n4.Depth First Search");
printf("\n5.Breath First Search");
printf("\n6.Exit");
while(1)
{
	printf("\nEnter Your Option :");
	scanf("%d",&option);
	switch(option)
	{
	case 1 :
	printf("\nEnter Number of Vertices :");
	scanf("%d",&n);
	construct_undirected(n);
	break; 
	case 2 : 
	printf("\nEnter Number ofVertices :");
	scanf("%d",&n); 
	construct_directed(n); 
	break; 
	case 3 : 
	display(n); 
	break; 
	case 4 : 
	DF_Traversal(n); 
	break; 
	case 5 : 
	BF_Traversal(n); 
	break; 
	case 6 : 
	exit(1);
	 }
	}
}
