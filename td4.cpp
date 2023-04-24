#include<stdio.h>
#include<stdlib.h>

typedef struct cellule
{
	int val;
	struct cellule* prec;
	
}cellule, *pile;

pile empiler(int v, pile p)
{
	pile p1=(cellule*)malloc(sizeof(cellule));
	p1->val=v;
	p1->prec=p;
	return p1;
	}
	
int depiler (pile *p)
{
	pile p1= *p;
	int v;
	
	if(p==NULL)
	return 0;
	
	else{
	v=(*p)->val;
	(*p)=(*p)->prec;
	free(p1);
     }
     
	return v;

}

int calcnmbr (pile p, int n)
{
	pile p1=p;
	
	if(p==NULL)
	return 0;
	
	else if(p->val>n)
	return 1+calcnmbr (p->prec,n);
	
	else
	return 0+calcnmbr (p->prec,n);

}

int longeur(pile p)
{
	int cmpt=0;
	
	while(p!=NULL)
	{
		cmpt++;
		p=p->prec;
	}
	
	return cmpt;
}

pile depilerP (pile p)
{
	if(p==NULL)
	return NULL;
	
	else {
		pile p1=p;
		
		while(p1->prec->prec!=NULL)
		p1=p1->prec;
		
		pile p2;
		p2=p1->prec;
		p1->prec=NULL;
		free(p2);
		
		return p;
		
	}
}

void affiche (pile p)
{
	while(p!=NULL)
	{
		printf("[%d]->",p->val);
		p=p->prec;
	}
	
	printf("NULL \n");
}

pile permute(pile p)
{
	pile p1=p;
	int v;
	
	v=p1->val;
	p1->val=p1->prec->val;
	p1->prec->val=v;
	
	return p;
}

pile permuteP(pile p)
{
	pile p1=p;
	int v;
	
	v=p1->val;
	
	while(p1->prec!=NULL)
	p1=p1->prec;
	
	p->val=p1->val;
	p1->val=v;

	
	return p;
}

pile renverser (pile p)
{
	pile p2=NULL;;
	
	while(p)
	p2=empiler(depiler(&p),p2);
	
	return p2;
}

pile permutePP(pile p, int n)
{
	pile p1,p2,p3;
	p1=p2=p3=NULL;
	
	if (p==NULL && p->prec==NULL) 
	return p;
	
	else {
	int r=n%longeur(p);
	
	if(r==0)
	return p;
	
	else{
	
	while(r>0)
	{
		p1=empiler(depiler(&p),p1);
		r--;
		
	}
	p=renverser(p);
		
	while(p1)
	{
		p3=empiler(depiler(&p1),p3);
		
	}
	
		while(p)
	{
		p3=empiler(depiler(&p),p3);
		
	}
}
	
	return p3;}
}










main()
{
	pile p=NULL;
	int v;
//	pile* p1=&p;
	
	p=empiler(1, p);
	p=empiler(19, p);
	p=empiler(36, p);
	p=empiler(4, p);
//	v=depiler (&p);
	p=empiler(15, p);
//	p=depilerP (p);
	
	affiche (p);
	printf("le nombre est %d \n" ,calcnmbr (p,4));
	printf("la longueur est %d \n" ,longeur(p));
//	printf("%d \n",(*p1)->val);
	
//	p=permute(p);
//	affiche (p);
	
//	p=permuteP(p);
//	affiche (p);
	
	p=permutePP(p,3);
	affiche (p);
	
}
