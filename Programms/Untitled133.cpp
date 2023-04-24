#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

typedef struct station

{

 int num,duree;

 char nom[50];

 struct station* suivant;

} station, *liste;

 

liste AjoutFin (int num, char nom[50], int duree, liste l)

{

    liste L1;

 L1 = (station*)malloc(sizeof(station));

strcpy(L1->nom,nom);

L1->num=num;

L1->duree=duree;

 L1 -> suivant = NULL;

    if(l==NULL)

    return L1;

    else if(l->suivant==NULL)

    { l->suivant=L1;

        return l;}

    else

    {

        liste l2;

        l2=l;

        while(l2->suivant!=NULL)

        {

            l2=l2->suivant;

        }

        l2->suivant=L1;

        return l;

        

    }

}

void AfficheStation(liste l){

    if(l==NULL)

        printf("NULL\n");

    

    else

    {
    	if(l->duree<=2)

        printf("[%s/ %d/ %d]->",l->nom,l->num,l->duree);
        
        
      return AfficheStation(l->suivant);

    }
    
    

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


liste Trilist(liste l)

{

if(l==NULL)

return NULL;

if(l->suivant==NULL)

return l;

int test;

char Nom[50];

int Num1,Duree1;

do {

    test=0;

    liste  l1=l;

    while(l1->suivant!=NULL)

    {

        if(strcmp(l1->nom,l1->suivant->nom)>0)

        {

            strcpy(Nom,l1->nom);
            strcpy(l1->nom,l1->suivant->nom);
            strcpy(l1->suivant->nom,Nom);
            
            Num1=l1->num;
            l1->num=l1->suivant->num;
            l1->suivant->num=Num1;
            
            Duree1=l1->duree;
            l1->duree=l1->suivant->duree;
            l1->suivant->duree=Duree1;

            test=1;

        }

        l1=l1->suivant;

    }

}

while(test==1);

return l;

}


 

int main(){

    liste l=NULL;

    l=AjoutFin(1,"La poste",3,l);
   

    l=AjoutFin(2,"Tabriquet", 2,l);

    l=AjoutFin(3,"Hay Karima", 0,l);

    AfficheStation(l);

  l=SuppContactIter("Tabriquet",l);

    AfficheStation(l);

    l=Trilist(l);

    AfficheStation(l);

    return 0;

    

}
