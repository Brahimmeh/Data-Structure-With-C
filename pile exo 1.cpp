#include<stdio.h>
#include<stdlib.h>

typedef struct cellule{
	
	struct cellule* prec;
	int v;
}*pile;


pile creerPile ()
{
	return NULL;
}

void Sommet(pile p)
{
	if(p==NULL)
	printf("NULL \n");
	
	else
	printf("[%d] \n",p->v);
	
	
}

int Vide(pile p)
{
	if (p==NULL)
	return 1;
	
	else 
	return 0;
}

pile empiler(pile p, int x)
{
	pile p1;
	p1=malloc(sizeof(pile));
	p1->v=x;
	
	if (p==NULL)
	{
		p1->prec=NULL;
		p=p1;
		return p1;
	}
	
	else
	{
		p->prec=p1;
		return p1;
	}
}

pile depiler (pile p)
{
		if (p==NULL)
	{
		return NULL;
	}
	
	else if (p->prec==NULL)
	{
		free(p);
		return NULL;
	}
	
	else{
		
	      pile p1;
	      p1=p->prec;	      
	      free(p);
	      
	      return p1
	}
}

void afficher(pile p)
{
		if(p==NULL)
	printf("NULL \n");

	
	else{

	while(p!=NULL)
	{
		printf("[%d] \n",p->v);
		p=p->prec;
	}
	
}
}
