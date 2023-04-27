#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int val;
    struct Element *next;
} Element;

typedef Element *Liste;

// Ajout en début de liste
void ajouterDebut(Liste *l, int x) {
    printf("Ajout de l'élément %d au début de la liste\n", x);
    Liste elt = (Element*) malloc(sizeof(Element));
    elt->val = x;
    elt->next = *l;
    *l = elt;
}

// Ajout en fin de liste
void ajouterFin(Liste *l, int x) {
    printf("Ajout de l'élément %d à la fin de la liste\n", x);
    Liste elt = (Element*) malloc(sizeof(Element));
    elt->val = x;
    elt->next = NULL;
    if (*l == NULL) {
        *l = elt;
        return;
    }
    Liste k = *l;
    while (k->next != NULL) {
        k = k->next;
    }
    k->next = elt;
}

// Ajout à la position k
void ajouterK(Liste *l , int x , int k) {
    printf("Ajout de l'élément %d à la position %d\n", x, k);
    if (k <= 0) {
        ajouterDebut(l, x);
        return; 
    }
    Liste t = *l;
    int c = 0;
    while (t != NULL && c < k - 1) {
        t = t->next;
        c++;
    }
    if (t == NULL) { // Si on atteint la fin de la liste, on ajoute à la fin
        ajouterFin(l, x);
        return;
    }
    ajouterDebut(&(t->next), x); // On ajoute juste après l'élément à l'indice k-1
}

// Afficher la liste
void affiche(Liste l) { 
    printf("Affichage de la liste : ");
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

// Supprimer début
void supDebut(Liste *l) {
    if (*l != NULL) {
        printf("Suppression du premier élément de la liste\n");
        Liste q = *l;
        *l = (*l)->next;
        free(q);
    }
}

// Supprimer fin
void supFin(Liste *l) {
    if (*l == NULL) {
        return;
    }
    if ((*l)->next == NULL) { // S'il n'y a qu'un seul élément dans la liste
        supDebut(l);
        return;
    }
    Liste k = *l;
    while (k->next->next != NULL) { // On avance jusqu'à l'avant-dernier élément
        k = k->next;
    }
    printf("Suppression du dernier élément de la liste\n");
    free(k->next);
    k->next = NULL;
}

//inserer dans une liste triee
void inserTrier(Liste * l,int x)
{
if(*l == NULL || (*l)->val>x)
 ajouterDebut(l,x);
 else 
 inserTrier(&(*l)->next, x);

}
// Afficher la liste à l'envers
void affichenv(Liste l) { 
    if (l != NULL) {
        affichenv(l->next);
        printf("%d ", l->val);
    }
}



int main()
{
    Liste l = NULL; // Initialisation de la liste à NULL
    ajouterFin(&l, 2);
    ajouterDebut(&l, 1);
    ajouterFin(&l, 4);
    ajouterDebut(&l, 7);
    affiche(l);
    ajouterK(&l , 0 , 0);
    affiche(l);
    ajouterK(&l , 5 , 3);
    affiche(l);
    printf("affichage de la liste a l'envers : ");
    affichenv(l);
    printf("\n");
    printf("supprimer debut \n");
    supDebut(&l);
    affiche(l);
    printf("supprimer fin \n");
    supFin(&l);
    affiche(l);
    /*autre liste  triee*/
     Liste l2 = NULL; // Initialisation de la liste à NULL
    inserTrier(&l2,5);
    inserTrier(&l2,3);
    inserTrier(&l2,4);
    affiche(l2);
    return 0;
}

