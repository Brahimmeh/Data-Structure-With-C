#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct operateur
{
	char op;
	struct operateur* prec;
}pileO;

pileO* empilerOPT(pileO* p,char op)
{
	pileO* p1=(pileO*)malloc(sizeof(pileO));
	p1->op=op;
	p1->prec=p;
	
	return p1;
}

char depiler(pileO **p)
{
	if((*p)==NULL)
	return '0';
	
	else
	{
		char op1;
		pileO *p1;
		
		op1=(*p)->op;
		p1=(*p);
		(*p)=(*p)->prec;
		free(p1);
		
		return op1;
		
		
	}
}

char* conversion(char* expInf)
{
	pileO* p=NULL;
	char* expPost=(char*)malloc(30*sizeof(char));
	char op;
	
	int n=strlen(expInf);
	
	int i,j;
	j=0;
	
	for(i=0;i<n;i++)
	{
		if(isdigit(expInf[i]))
		{
			expPost[j]=expInf[i];
			j++;
		}
		
		else if (expInf[i]=='-' || expInf[i]=='*' || expInf[i]=='+')
		p=empilerOPT(p,expInf[i]);
		
		else if(expInf[i]==')')
		{
			op=depiler(&p);
			expPost[j]=op;
			j++;
		}
	}
	
	return expPost;
}


typedef struct operande
{
	int valeur;
	struct operande* prec;
}pileR;

pileR* empilerOP(pileR* p, int v)
{
	pileR* p1=(pileR*)malloc(sizeof(pileR));
	p1->valeur=v;
	p1->prec=p;
	
	return p1;
}

int depilerOP(pileR **p)
{
	if((*p)==NULL)
	return 0;
	
	else
	{
		int v;
		pileR* p1;
		
		p1=(*p);
		v=(*p)->valeur;
		(*p)=(*p)->prec;
		free(p1);
		return v;
	}
}

int evaluerr (char* expPost)
{
	pileR* p=NULL;
	int v1,v2,v3;
	
	int n=strlen(expPost);
	
	int i;
	
	for(i=0;i<n;i++)
	{
		if(isdigit(expPost[i]))
		p=empilerOP(p,expPost[i]-48);
		
		else if(expPost[i]=='-')
		{
			v1=depilerOP(&p);
			v2=depilerOP(&p);
			v3=v2-v1;
			p=empilerOP(p,v3);
		}
		
		else if(expPost[i]=='+')
		{
			v1=depilerOP(&p);
			v2=depilerOP(&p);
			v3=v2+v1;
			p=empilerOP(p,v3);
		}
		
		else if(expPost[i]=='*')
		{
			v1=depilerOP(&p);
			v2=depilerOP(&p);
			v3=v2*v1;
			p=empilerOP(p,v3);
		}
		
	}
	
	return p->valeur;
}

main()
{
	char ch1[50],*ch2;
	
	printf("entrer l'expression \n");
	fflush(stdin);
	gets(ch1);
	
	ch2=conversion(ch1);
	puts(ch2);
	

	printf("le total est : %d \n",evaluerr(ch2));
	
}
