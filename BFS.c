#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[10][10],n,source,visited[10],i,j;
	
	printf("Enter the number of nodes: \n");
	scanf("%d\n",&n);
	
	printf("Enter the adjacency matrix: \n");

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	
	printf("Enter the source node: \n");
	scanf("%d\n",&source);
	
	visited[source]=1;
	
	BFS(a,source,visited,n);

	for(i=1;i<=n;i++)
	{
		if(visited[i] !=0)
		{
			printf("Node %d is reachable \n",i);
		}
		else
		{
			printf("Node %d is not reachable \n",i);
		}	
	}
}

void BFS(int a[10][10],int source,int visited[10],int n)
{
	int u,v,f=0,r=-1,queue[10];

	queue[++r]=source;

	while(f<=r)
	{
		u=queue[f++];

		for(v=1;v<=n;v++)
		{
			if(a[u][v]==1 && visited[v]==0)
			{
				queue[++r]=v;
				visited[v]=1;
			}
		
		}
	}
}
	
