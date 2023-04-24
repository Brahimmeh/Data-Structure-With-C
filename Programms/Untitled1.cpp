#include <stdlib.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char *add(const char *a, const char *b) {

    char *r;
    int n,n1,s,i=0;
  
  r=(char*)malloc(1000*sizeof(char));
  
  n=atoi(a);
  n1=atoi(b);
  
  s=n+n1;
  printf("%d \n",s);
  
  itoa(s,r,10);
  
return r;

}
  
main()
{
	char ch2[50],ch1[50];
	 char * chn;
	
	gets(ch2);
	gets(ch1);
	
	chn =add(ch2,ch1);

	
	puts(chn);
	
}
