#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void Knapsack(int m,int n,int w[],int p[])
{
	int i,j,x[10],v[10][10],sum=0;
	
	for(i=0;i<=m;i++)
		v[i][0]=0;
	for(j=0;j<=n;j++)
		v[0][j]=0;

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(j>=w[i])
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
			else
				v[i][j]=v[i-1][j];

	for(i=1;i<=n;i++)
		x[i]=0;
	i=n;
	j=m;
		
	while(i>0 && j>0)
	{
		if(v[i][j] != v[i-1][j])
		{
			//x[i]!=0
			x[i]=1;
			j=j-w[i];
			//sum+=p[i];		
		}
		i--;
	}

	printf("The Optimal set of Items: \n");

	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
		{
			printf("%d\t",i);
			sum+=p[i];
		}
	}
	printf("Total Profit is: %d",sum);
}

void main()
{
	int n,m,p[10],w[10],i;

	printf("Enter the value of n ie the total no. of items: \n");
	scanf("%d\n",&n);

	printf("Enter the weights:\n");
	for(i=1;i<=n;i++)
		scanf("%d\n",&w[i]);
		
	printf("Enter the profits: \n");
	for(i=1;i<=n;i++)
		scanf("%d\n",&p[i]);
		
	printf("Enter the capacity of the Knapsack: \n");
		scanf("%d\n",&m);
	Knapsack(m,n,w,p);
}
	
