
#include<stdio.h>
#include<stdlib.h> // pour malloc
// pile: last in first out

typedef struct
{

int *tab ; 
int sommet ; //sommet indice du dernier element
int capacite; 

}pile ; 


//on a 5 fonction init , vide ,pleine, sommet , empiler , depiler 
// intialisation d'une pile
void init ( pile * p , int c)
{
p->tab = (int*) malloc(c*sizeof(int));

p->capacite = c; 
p->sommet = -1;

}
// vérification si la pile est vide 

int vide(pile p )
{

return p.sommet == -1;
}


// verfication si la pile est pleine
int pleine (pile p )
{return p.sommet == p.capacite - 1;
}

// retourner la derniere valeur 
int sommet(pile p)
{return p.tab[p.sommet];}

//empiler 
void empiler(pile * p , int x)
{
p->tab[++p->sommet]=x;
}
//depiler 
int depiler(pile * p )
{
int x=p->tab[p->sommet --];
return x;
}

// inverser un tableau a l'aide d'une pile 
void Inversetab(int tab [] , int n )
{

int i;
pile  p ;
init(&p , n ) ;
printf("avant : \n");
for (i =0 ; i<n ; i++ )
{
empiler(&p,tab[i]);
printf("%d \t",tab[i]);}

printf("\n aprés : \n");


for (i =0 ; i<n ; i++ )
{
tab[i]= depiler(&p);
printf("%d \t",tab[i]);}

}



/// programme principale 

void main()
{
pile p ;
init(&p , 6);
printf("vide: %d \n",vide(p));
empiler(&p , 1);
empiler(&p , 2);
empiler(&p , 3);
empiler(&p , 4);
empiler(&p , 5);
empiler(&p , 6);
printf("pleine: %d \n",pleine(p));
printf("sommet: %d \n",sommet(p));
int tab[] = { 1, 2, 3 };
Inversetab(tab, 3 );
}






