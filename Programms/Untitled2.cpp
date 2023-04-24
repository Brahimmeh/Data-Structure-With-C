#include<stdio.h>
#include<string.h>

void adrs(char n[50])
{
	int i;
	char c;
	
	for (i=strlen(n);i>=0;i--)
	{
		c=n[i];
		n[i]=n[i+1];
		n[i+1]=c;
	}
	
	n[0]='@';
	
	//return n;
}

main()
{
	
	char n[50];
	char c;
	
	printf("enter \n");
	gets(n);
	puts(n);
	
	printf("%d \n",strlen(n));
	
	adrs(n);
	
	
	puts(n);
}
