// file fifo first in first out 
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
}file;

// fonction init vide tete enfiler defiler
//initialisation d'une file 
void init(file *f)
{f->tete = NULL;
f-> queue =NULL;}


// verifier si elle est vide 
int vide(file f)
{
return f.tete == NULL;
}

// retourner le contenue de la tete
int tete (file f)
{
return (f.tete)->val;

}
// retourner le contenue de la queue
int queue (file f)
{
return (f.queue)->val;

}

// enfiler 
void enfiler (file *f , int x)
{
Element * p = (Element*)malloc(sizeof(Element));
p->val = x;
p->next=NULL;
if(vide(*f)==1)
 {f->tete=p;
  f->queue=p;
 }
 else{
 f->queue->next=p;
 f->queue=p;
 }
}
//défiler
int defiler(file * f)
{
int x = f->tete->val ;
Element *p = f->tete;
f->tete=f->tete->next;
free(p);
if(f->tete == NULL)
f->queue = NULL ;
return x;


}

void afficher(file f)
{Element * e=f.tete;
while(e!=NULL)
{printf("%d \t",e->val);
e=e->next;
}



}

void main()
{
file f;
init(&f);
printf("vide : %d \n",vide(f));
enfiler(&f,1);

enfiler(&f,2);
enfiler(&f,3);
enfiler(&f,4);
enfiler(&f,5);
enfiler(&f,6);
printf("afficher file aprés remplissage\n");
afficher(f);
printf("\n vide : %d \n",vide(f));
printf("\n tete : %d \n",tete(f));
printf("\nqueue : %d \n",queue(f));
printf("valeur defilés : %d \n", defiler(&f));
printf("afficher file aprés avoir défilé (first in first out)\n");
afficher(f);
printf("\n");
}



