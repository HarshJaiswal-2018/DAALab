#include<stdio.h>
#include<stdlib.h>
void DFS(int [10][10],int,int [10],int);

void main()
{
	int a[10][10],source,visited[10],n;

	printf("Enter the Number of Nodes\n");
	scanf("%d\n",&n);
	int i,j;
	printf("enter the adjacency matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d ",&a[i][j]);
		}
	}

	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}

	printf("Enter the source node: \n");
	scanf("%d\n",&source);

	DFS(a,source,visited,n);

	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("Graph is not connected\n");
			exit(0);
		}
	}
	printf("Graph is connected\n");
}

void DFS(int a[10][10],int u,int visited[10],int n)
{
	visited[u]=1;
	int v;
	for(v=1;v<=n;v++)
	{
		if(a[u][v]==1 && visited[v]==0)
		{
			DFS(a,v,visited,n);
		}
	}
}
