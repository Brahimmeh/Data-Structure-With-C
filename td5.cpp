#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct operateur
{
	char c;
	struct operateur* prec;
}pileO;

pileO* empilerOpt(pileO *p, char op)
{
	pileO *p1;
	p1=(struct operateur*)malloc(sizeof(pileO));
	p1->c=op;
	p1->prec=p;
	

	return p1;
}

char depilerOpt(pileO **p)
{
	if((*p)==NULL)
	return '0';
	else
	{
	
	char o;
	o= (*p)->c;
	pileO *p1;
	p1=*p;
	*p= (*p)->prec;
	free(p1);
	
	return o;
}}

char* coversion(char* expInf)
{
	char* expPost=(char*)malloc(sizeof(char));
	pileO* p1=NULL;
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
	    
	    else if (expInf[i]=='-' || expInf[i]=='+'||expInf[i]=='*')
	    p1=empilerOpt(p1,expInf[i]);
	    
	    else if(expInf[i]==')')
	    {
	    	op=depilerOpt(&p1);
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


pileR* empilerOpr(pileR* p,int v)
{
	pileR *p1=(pileR*)malloc(sizeof(pileR));
	p1->valeur=v;
	p1->prec=p;
	
	return p1;
}

int depilerOpr(pileR **p)
{
	if((*p)==NULL)
	return 0;
	
	else 
	{
		int v;
		v=(*p)->valeur;
		pileR* p1;
		p1=(*p);
		(*p)=(*p)->prec;
		free(p1);
		
		return v;
	}
}

int evaluer(char* expPost)
{
	pileR* p=NULL;
	int i,v1,v2,v3;
	
	int n=strlen(expPost);
	
	for(i=0;i<n;i++)
	{
		if(isdigit(expPost[i]))
		p=empilerOpr(p,expPost[i]-48);
		
		else if(expPost[i]=='-'){
			v1=depilerOpr(&p);
			v2=depilerOpr(&p);
			v3=v2-v1;
			p=empilerOpr(p,v3);
			
		}
		
		else if(expPost[i]=='+'){
		    v1=depilerOpr(&p);
			v2=depilerOpr(&p);
			v3=v2+v1;
			p=empilerOpr(p,v3);
			
		}
		else if(expPost[i]=='*'){
		    v1=depilerOpr(&p);
			v2=depilerOpr(&p);
			v3=v2*v1;
			p=empilerOpr(p,v3);
			
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
	
	ch2=coversion(ch1);
	puts(ch2);
	

	printf("le total est : %d \n",evaluer(ch2));
	
}

