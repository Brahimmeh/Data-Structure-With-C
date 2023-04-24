#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct wagon
{
	char code[50],classe[20];
	int npl;
	struct wagon* suiv;
	struct wagon* prec;
}wagon, *liste;

liste Ajoutdeb(char code[50], char classe[20], int npl, liste l)
{
	liste l1=(wagon*)malloc(sizeof(wagon));
	strcpy(l1->code,code);
	strcpy(l1->classe,classe);
	l1->npl=npl;
	l1->prec=NULL;
	l1->suiv=l;
	l->prec=l1;
	
	return l1;
}

liste Ajoutfin(char code[50], char classe[20], int npl, liste l)
{
	liste l1=(wagon*)malloc(sizeof(wagon));
	strcpy(l1->code,code);
	strcpy(l1->classe,classe);
	l1->npl=npl;
    l1->suiv=NULL;
    
    if(l==NULL)
    {
    	l1->prec=NULL;
		
    	return l1;
	}
	
	else
	{
		liste l2=l;
		
		while(l2->suiv!=NULL)
		l2=l2->suiv;
		
		l1->prec=l2;
		l2->suiv=l1;
		
		return l;
	}
}

liste SuppWagon(liste l)
{
    liste l1=l,l2;
    
    if(l1==NULL)
    return l1;
    
    else
    {
    	while(l1!=NULL)
    	{
    		if(strstr(l1->code,"Q5")!=NULL)
    		{
    			l2=l1;
    			if(l1->prec==NULL)
    			{
    				
    				l1->suiv->prec=NULL;
    				l1=l1->suiv;
    				l=l1;
				}
				
				else{
					l1->prec->suiv=l1->suiv;
					
					if(l1->suiv!=NULL)
					{
						l1->suiv->prec=l1->prec;
					}
				}
				
				free(l2);
			}
			
			l1=l1->suiv;
		}
		
		return l;
	}}
	


void afflist (liste l)
{
	if(l==NULL)
	printf("FIN \n");
	
	else
	{
		printf("code : %s\n",l->code);
		printf("classe : %s\n" ,l->classe);
		printf("nombre de places : %d \n //////////////////////////////// \n ",l->npl);
		return afflist(l->suiv);
	}
}

liste triliste(liste l)
{
	int k=0;
	liste l1=l;
	
	do{
		k=0;
		l1=l;
		char code[50],classe[20];
		int nb;
		
		while(l1->suiv!=NULL)
		{
			if(l1->npl > l1->suiv->npl)
			{
				strcpy(code,l1->code);
				strcpy(classe,l1->classe);
				nb=l1->npl;
				
				strcpy(l1->code,l1->suiv->code);
				strcpy(l1->classe,l1->suiv->classe);
				l1->npl=l1->suiv->npl;
				
				strcpy(l1->suiv->code,code);
				strcpy(l1->suiv->classe,classe);
				l1->suiv->npl=nb;
				
				k++;
			}
			
			l1=l1->suiv;
		}
	}while(k!=0);
	
	return l;
}

main()
{
	liste l=NULL;
	
	l=Ajoutdeb("Q512", "1ER", 10, l);
	l=Ajoutdeb("Q712", "2EM", 4, l);
	l=Ajoutdeb("Q8512", "1ER", 12, l);
	
	l=Ajoutfin("Q5712", "1ER", 28, l);
	l=Ajoutfin("Q4512", "1ER", 25, l);
	l=Ajoutfin("Q1512", "1ER", 16, l);
	
	
	 afflist (l);
	 
	 
	 
	 l= triliste(l);
	 
	 afflist (l);
	 
	 l=SuppWagon(l);
	 
	 printf("\n\n");
	 afflist (l);

	 
	
}
