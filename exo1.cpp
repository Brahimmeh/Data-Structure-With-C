#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct cellContact{
	
   char nom[50],num[20];
   struct cellContact* suivant;
   
} cellContact, *liste;


liste AjoutDebut (char nm[50],char nmt[20], liste l)
{
	liste l1;
	l1=(cellContact*)malloc(sizeof(cellContact));
	strcpy(l1->nom,nm);
	strcpy(l1->num,nmt);
	
	l1->suivant=l;
	
	return l1;
}

liste AjoutFin (char nm[50],char nmt[20], liste l)
{
	liste l1=(cellContact*)malloc(sizeof(cellContact));
	strcpy(l1->nom,nm);
	strcpy(l1->num,nmt);
	l1->suivant=NULL;
	
	if(l==NULL)
	{
		
		return l1;
	}
	
	else if(l->suivant==NULL)
	{
		l->suivant=l1;
		return l;
	}
	
	else {
		liste l2=l;
		
		while(l2->suivant!=NULL)
		l2=l2->suivant;
		
		l2->suivant=l1;
		
		return l;
	}
}
int i =1;
void affichListe(liste l,int i)
{ 
   if (l!=NULL){
   
	printf("contact num %d \n",i);
	printf("le nom : %s\n",l->nom);
	printf("le num de tel : %s\n",l->num);
	affichListe(l->suivant,i=i+1);
}

else 
printf("FIN \n");
}

liste SuppContact (char nm[50],liste l)
{
	liste l1,l2;
	
	if(l==NULL)
	return l;
	
	
	else if(strcmp(l->nom,nm)==0 )
	{
		
		l1=l->suivant;
		free(l);
		return l1;
	}
	

	else
	{   l2=l;
		while(l2->suivant!=NULL && strcmp(l2->suivant->nom,nm)!=0)
		l2=l2->suivant;
		
		
		l1=l2->suivant;
		l2->suivant=l1->suivant;
		free(l1);
		return l;
	}

}

int contactchiffre(liste l,char n)
{
	if(l==NULL)
	return 0;
	
	else if (strchr(l->num,n)!=NULL)
	return 1+contactchiffre(l->suivant,n);
}

liste triliste(liste l)
{
	int k=0;
	liste l1;
	
	do{
		k=0;
		l1=l;
		char nom[50],num[20];
		
		while(l1->suivant!=NULL)
		{
			if(strcmp(l1->nom,l1->suivant->nom)>0)
			{
				strcpy(nom,l1->nom);
				strcpy(num,l1->num);
				strcpy(l1->nom,l1->suivant->nom);
				strcpy(l1->num,l1->suivant->num);
				strcpy(l1->suivant->nom,nom);
				strcpy(l1->suivant->num,l1->num);
				k++;
			}
			
			l1=l1->suivant;
		}
	}while(k!=0);
	
	return l;
}
main()
{
	liste l=NULL;
	l= AjoutDebut ("ahmed","053562",l);
	l= AjoutDebut ("salma","053785",l);
	l= AjoutFin ("abdo","053785",l);
	l= AjoutFin ("brahim","053785",l);
	
	affichListe(l,i);
	
/*	l=SuppContact ("ahmed",l);
	l=SuppContact ("abdo",l);
	
	affichListe(l,i);
	
	printf("le nombre est : %d \n",contactchiffre(l,'5'));*/
	
	
	l=triliste(l);
	affichListe(l,i);
}
