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



}// File FIFO (First In First Out)

#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un élément de la file
typedef struct Element {
    int val;
    struct Element *next;
} Element;

// Structure pour représenter la file elle-même
typedef struct {
    Element *tete; // Pointeur vers le premier élément de la file
    Element *queue; // Pointeur vers le dernier élément de la file
} file;

// Fonction pour initialiser une file vide
void init(file *f) {
    f->tete = NULL;
    f->queue = NULL;
}

// Fonction pour vérifier si une file est vide
int vide(file f) {
    return f.tete == NULL;
}

// Fonction pour retourner le contenu de la tête de la file
int tete(file f) {
    return (f.tete)->val;
}

// Fonction pour retourner le contenu de la queue de la file
int queue(file f) {
    return (f.queue)->val;
}

// Fonction pour enfiler un élément dans la file
void enfiler(file *f, int x) {
    Element *p = (Element*) malloc(sizeof(Element)); // Allouer un nouvel élément
    p->val = x; // Initialiser sa valeur
    p->next = NULL;
    if (vide(*f) == 1) { // Si la file est vide, le nouvel élément devient à la fois la tête et la queue
        f->tete = p;
        f->queue = p;
    } else { // Sinon, ajouter le nouvel élément à la fin de la file
        f->queue->next = p;
        f->queue = p;
    }
}

// Fonction pour défiler un élément de la file
int defiler(file *f) {
    int x = f->tete->val; // Récupérer la valeur de l'élément à défiler
    Element *p = f->tete; // Stocker l'adresse de l'élément à supprimer
    f->tete = f->tete->next; // Mettre à jour la tête de la file
    free(p); // Libérer la mémoire allouée à l'élément à supprimer
    if (f->tete == NULL) { // Si la file est maintenant vide, mettre à jour la queue
        f->queue = NULL;
    }
    return x;
}

// Fonction pour afficher le contenu de la file
void afficher(file f) {
    Element *e = f.tete;
    while (e != NULL) {
        printf("%d \t", e->val);
        e = e->next;
    }
}

// Fonction principale pour tester les fonctions de la file
void main() {
    file f;
    init(&f);
    printf("vide : %d \n", vide(f));
    enfiler(&f, 1);
    enfiler(&f, 2);
    enfiler(&f, 3);
    enfiler(&f, 4);
    enfiler(&f, 5);
    enfiler(&f, 6);
    printf("afficher file après remplissage\n");
    afficher(f);
    printf("\n vide : %d \n", vide(f));
    printf("\n tete : %d \n", tete(f));
    printf("\n queue : %d \n", queue(f));
    printf("valeur defilés : %d \n", defiler(&f));
    printf("afficher file aprés avoir défilé (first in first out)\n");
    afficher(f);
    printf("\n");
}



