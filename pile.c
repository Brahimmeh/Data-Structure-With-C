#include<stdio.h>
#include<stdlib.h>

typedef struct cellule
{
	struct cellule* prec;
	int v;
}*pile;

pile creerPile()
{
	return NULL;
}

void affiche (pile p)
{
	if(p==NULL)
	printf("NULL \n");
	
	else
	{
	      while (p!=NULL)
	      {
		  
	printf("[%d]\n",p->v);
	p=p->prec;
         }
}
}

pile empiler (pile p, int x)
{
	pile p1;
	p1=malloc(sizeof(pile));
	p1->v=x;
	

		p1->prec=p;
		return p1;
	
}

pile depiler (pile p)
{
	if(p==NULL)
	return NULL;
	
	else if (p->prec==NULL)
	{
		free(p);
		return NULL;
	}
	
	else 
	{
		pile p1;
		p1=p->prec;
		free(p);
		return p1;
	}
}

int taille (pile p)
{
	int i=0;
	
	if(p==NULL)
	return i;
	
	else
	{
	      while (p!=NULL)
	      {
		  
	i++;
	p=p->prec;
         }
         
         return i;
}
}

pile permuter (pile p,int n)
{
	pile p1,p2;
	p1=NULL;
	p2=NULL;
 int i = taille (p);
 int v1;
	
	if (i==0)
	return NULL;
	
	else if (i==1)
	return p;
	
	else {
		int cmpt=0;
		
		while(p!=NULL && cmpt<i)
		{
			if(cmpt<n)
			{
		p1=empiler (p1,p->v);
		p=p->prec;
		cmpt++;
			}
			
			else
			{
				p2=empiler (p2,p->v);
		        p=p->prec;
		        cmpt++;
			}
	    }
	    
	    pile p3=NULL;
	    
	    while (p1!=NULL)
	    {
	    	v1=p1->v;
	    	p1=depiler (p1);
	    	p3=empiler (p3,v1);
	    	
		}
	    
	    	    while (p2!=NULL)
	    {
	    	v1=p2->v;
	    	p2=depiler (p2);
	    	p3=empiler (p3,v1);
	    	
		}
	    
	    
	    
		return p3;
	}
}

main()
{
	pile p;
	
	p=creerPile();
	p=empiler (p, 1);
	p=empiler (p, 2);
	p=empiler (p, 3);
	p=empiler (p, 4);
	p=empiler (p, 5);
	p=empiler (p, 6);
	affiche (p);
	
	int t;
	t= taille (p);
	printf("taille : %d \n",t);
	printf("Apres la permutation circulaire \n");
	
	 p=permuter (p,2);
	affiche (p);
}
