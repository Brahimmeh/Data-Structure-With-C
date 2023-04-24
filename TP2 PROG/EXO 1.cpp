#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct cellule {
	
	int val;
	struct cellule* suivant;
}*liste;
//1
liste CreerListe()
{
	return NULL;
}
//2
int TestListe (liste l)
{
	if (l == NULL)
	return 0;
	
	return 1;
}
//3
liste AjoutDeb(int v, liste l)
{
	liste l1;
	l1=(liste)malloc(sizeof(l1));
	
	l1->val = v;
	l1->suivant=l;
	
	return l1;
}
//4
liste AjoutFin (int v, liste l)
{
	liste l1,l2;
	l1=(liste)malloc(sizeof(l1));
	
	l1->val = v;
	l1->suivant=NULL;
	
	if (l == NULL)
	return l1;
	
	else{
		l2=l;
		
		while(l2->suivant!=NULL)
		l2=l2->suivant;
		
		l2->suivant=l1;
		return l;	
	}
}
//5
void AfficheListe (liste l)
{
	while(l!=NULL)
	{
		printf("[%d]",l->val);
		l=l->suivant;
	}
}
//6-2
liste SuppDeb(liste l)
{
	liste l1;
	l1=l;
	
	if (l == NULL)
	return NULL;
	
else{

l=l1->suivant;
free(l1);
	
	return l;}
}
//7-2
liste SuppFin(liste l)
{
	liste l1,l2;
	l1=l;
	
	if (l == NULL || l->suivant==NULL)
	return NULL;
	
else{
while(l1->suivant->suivant!=NULL)
{
	l1=l1->suivant;

}
l2=l1->suivant;
l1->suivant=NULL;
free(l2);
	
	return l;}
}
//8-2
int LongListe (liste l)
{   int i=0;

while(l!=NULL)
{
	i++;
	l=l->suivant;	
}
	return i;
	
}
main()
{
	liste LISTE1 = CreerListe();
	int i=TestListe (LISTE1);
	if (i==0)
	printf("liste vide \n");
	else
	printf("liste non vide \n");
	LISTE1 = AjoutDeb(5, LISTE1);
	LISTE1 = AjoutDeb(4, LISTE1);
	LISTE1 = AjoutDeb(3, LISTE1);
	LISTE1 = AjoutDeb(2, LISTE1);
	
	LISTE1 = AjoutFin(10, LISTE1);
	LISTE1 = AjoutFin(11, LISTE1);
	LISTE1 = AjoutFin(12, LISTE1);
	LISTE1 = AjoutFin(13, LISTE1);
	
	AfficheListe (LISTE1);
	printf("\n la longueur de la liste avant est : %d \n\n\n",LongListe (LISTE1));
	LISTE1= SuppFin(LISTE1);
	LISTE1= SuppDeb(LISTE1);
	
	printf("\t Apres Mod \n");
	AfficheListe (LISTE1);

	printf("\n la longueur de la liste apres est : %d \n",LongListe (LISTE1));
	
	
}
