#include<stdio.h>
#include<string.h>

int table[128];

void shiftTable(char pattern[])
{
	int m=strlen(pattern);
	int i,j;
	for(i=0;i<128;i++)
	{
		table[i]=m;
	}

	for(j=0;j<m-1;j++)
	{
		table[pattern[j]]=m-1-j;
	}
}

int horspool(char pattern[],char text[])
{
	int i,j,k,m,n;
	shiftTable(pattern);
	m=strlen(pattern);
	n=strlen(text);

	i=m-1;

	while(i<n)
	{
		k=0;
		while(k<m && text[i-k]==pattern[m-1-k])
		{
			k++;
		}
		if(k==m)
		{
			return i-m+1;
		}
		else
		{
			i+=table[text[i]];
		}
	}

	return -1;
}

main()
{
	char text[128],pattern[10];
	int pos;
	printf("Enter the text in which the pattern is to be searched\n");
	gets(text);

	printf("Enter the pattern to be serached\n");
	gets(pattern);

	pos=horspool(pattern,text);

	if(pos==-1)
	{
		printf("Pattern NOT found\n");
	}
	else
	{
		printf("Pattern found\n");
	}
}
