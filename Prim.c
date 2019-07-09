#include<stdio.h>
#include<stdlib.h>

void main()
{
	int cost[10][10],visited[10],n,i,j,source,ne=1,min=9999,u,v,a,b,cost_min=0;

	printf("Enter the number of nodes: \n");
	scanf("%d\n",&n);

	printf("Enter the adjacency matrix: \n");
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	
	printf("Enter the source node: \n");
	scanf("%d\n",&source);

	for(i=1;i<=n;i++)
		visited[i]=0;

	visited[source]=1;
	
	while(ne<n)
	{
		min=9999;
		
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
					if(visited[i]==0)
						continue;
				else
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n%d\t%d->%d\t%d",ne++,a,b,min);
			cost_min+=min;
			visited[v]=1;
		}
		cost[a][b]=cost[b][a]=9999;
	}
	printf("\nMin cost is %d\n",cost_min);
}
					

	
