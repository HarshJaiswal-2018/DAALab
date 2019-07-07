#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	clock_t start,end;
	double time;
	int a[100000],n,i,r,j,temp;

	printf("Enter the size of the array:\n");
	scanf("\n%d",&n);
	
	for(i=0;i<n;i++)
	{
		r=rand();
		a[i]=r;
	}

	start=clock();

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%f",time);
	printf("Sorted Array: \n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}
