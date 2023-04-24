#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct CellContact
{
	char nom[50];
	char num[50];
	struct CellContact* suivant;
}* liste;

typedef struct CellContact cnt;

liste AjoutFin(char nm[50], char numtel[50], liste l)
{
	liste l1,l2;
	l1=l;
	l2=(cnt*)malloc(sizeof(cnt));
	strcpy(l2->nom,nm);
	strcpy(l2->num,numtel);
	l2->suivant=NULL;
	
	if(l==NULL)
		return l2;

	
else{

	while(l1->suivant!=NULL)
	{
		l1=l1->suivant;
	}
	
	l1->suivant=l2;

	
	return l;
}
}

void AfficheListe (liste l)
{
	
	if (l==NULL)
	{
		printf("\t \t END OF THE LISTE");
	}
	
	else{
	
	printf("/////// \n Contact Name : %s \n Contact Number : %s \n ",l->nom,l->num);
	
	return AfficheListe (l->suivant);}
}

liste SuppContactIter (char nm[50], liste l) 
{ 

liste l1,l2; l1=l; 
if(strcmp(l1->nom,nm)==0) 
{ 
 l1=l->suivant;
 free(l);
return l1;
} 
 
 
else{ 
 
while(strcmp(l1->suivant->nom,nm)!=0) 
{ 
l1=l1->suivant; 
} 
 
l2=l1->suivant; 
l1->suivant=l2->suivant; 
free(l2); 
 
return l; 
} 
} 
liste SuppContactIter1 (char nm[50], liste l)
{
	liste l1,l2;
	l1=l;
	if(strcmp(l1->nom,nm)==0 && l1->suivant !=NULL)
	{   
	    l1=l->suivant;
		free(l);
		return l1;
	}
	
	else if (strcmp(l1->nom,nm)==0 && l1->suivant ==NULL)
	{
		return l1;
	}
	
	else{
	
	while(strcmp(l1->suivant->nom,nm)!=0)
	{
		l1=l1->suivant;
	}
	
	l2=l1->suivant;
	l1->suivant=l2->suivant;
	free(l2);
	
	return l;
}
}

int CalculChiffreRec (liste l)
{
	int som=0;
	
	while(l!=NULL)
	{
		if (strchr(l->num,'5') != NULL)
		som++;
		
		l=l->suivant;
	}
	
	return som;
}

liste triliste( liste l)
{
	liste l1=l,l2,l3=NULL,l4;
	char ch[50],ch1[50];
	int i=0,n=3;
	
	while(l1!=NULL)
	{i=0;
	
		strcpy(ch,l1->nom);
		while(i<strlen(ch))
		{
			ch[i]=tolower(ch[i]);
			i++;
		}
		strcpy(l1->nom,ch);
        l1=l1->suivant;
	}
	

while (n>0)
{l2=l;
    strcpy(ch,l2->nom);
    strcpy(ch1,l2->num);
    
	while(l2!=NULL)
	{
		if(strcmp(l2->nom,ch)<=0)
		{
		strcpy(ch,l2->nom);
		strcpy(ch1,l2->num);
	    }
	    
		l2=l2->suivant;
		
	}

	l3=AjoutFin(ch,ch1,l3);
	l=SuppContactIter1 (ch,l);
    n--;    
    

    
}

return l3;
}

main()
{
	liste l=NULL,L1;
	
	char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50],ch6[50],ch7[50],ch8[50];
	
	gets(ch1);
	fflush(stdin);
	gets(ch2);
	fflush(stdin);
	gets(ch3);
	fflush(stdin);
	gets(ch4);
	fflush(stdin);
	gets(ch5);
	fflush(stdin);
	gets(ch6);
	fflush(stdin);
	gets(ch7);
	fflush(stdin);
	gets(ch8);
	
	l=AjoutFin(ch1,ch2, l);
	l=AjoutFin(ch3,ch4, l);
	l=AjoutFin(ch5,ch6, l);
	l=AjoutFin(ch7,ch8, l);
	
	
	AfficheListe (l);
	
	l=SuppContactIter (ch1,l);
	
	AfficheListe (l);
	
    printf("\n somme est %d \n",CalculChiffreRec (l));	
	
	l=triliste(l);
	AfficheListe (l);
}
