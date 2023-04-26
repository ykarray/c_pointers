// pile last in first out 
#include<stdio.h>
#include<stdlib.h>
typedef struct Element
{
int val;
struct Element *next;

}Element;
typedef struct 
{
Element *tete ; 
Element *queue;
}pile;

// fonction init vide tete enpiler depiler afficher
// initialisation de la pile 
void init(pile * p )
{
p->tete=NULL;
p->queue=NULL;

}
// verfier si elle est vide 
int vide (pile p )
{
return p.tete == NULL ;
}

// retourner la valeur de la tete
int tete(pile p )
{
return p.tete->val;
}

//retourner la valeur de la queue 
int queue(pile p )
{
return p.queue->val;

}

//enplier
void enpiler(pile * p,int x) 
{
Element * e = (Element*)malloc(sizeof(Element));
e->val=x;
e->next=NULL;
if(vide(*p))
{p->tete=e;
p->queue=e;}
else{
p->queue->next=e;
p->queue=e;

}


}

//depiler
int depiler(pile * p) 
{
int x = p->queue->val;
Element * eq = p->queue; 
if (p->tete == p->queue) { 
        p->tete = NULL;
        p->queue = NULL;
} else {
        Element * et = p->tete;
        while (et->next != eq) {
            et = et->next;
        }
        p->queue = et;
        p->queue->next = NULL;
    }
    
    free(eq); 
    return x;
}




//afficher
void afficher(pile p)
{Element * e=p.tete;
while(e!=NULL)
{printf("%d \t",e->val);
e=e->next;
}

}
void main()
{
pile p;
init(&p);
printf("vide : %d \n",vide(p));
enpiler(&p,1);

enpiler(&p,2);
enpiler(&p,3);
enpiler(&p,4);
enpiler(&p,5);
enpiler(&p,6);
printf("afficher pile aprés remplissage\n");
afficher(p);
printf("\n vide : %d \n",vide(p));
printf("\n tete : %d \n",tete(p));
printf("\nqueue : %d \n",queue(p));
printf("valeur depilée: %d \n", depiler(&p));
printf("afficher pile aprés avoir dépilé (last in first out)\n");
afficher(p);
printf("\n");
}









