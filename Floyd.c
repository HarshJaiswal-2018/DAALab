#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[10][10],n,i,j;
	printf("Enter the value of n: \n");
	scanf("%d",&n);
	
	printf("Enter the matrix:\n");

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);

	floyd(a,n);
	
	printf("The required shortest path matrix:\n");

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	
}

void floyd(int a[10][10],int n)
{
	int i,j,k;
	
	for(k=1;k<=n;k++)
		for(j=1;j<=n;j++)
			for(i=1;i<=n;i++)
				if(a[i][j]==0 && a[i][k]==1 && a[k][j]==1)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
			

