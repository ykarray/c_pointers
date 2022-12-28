#include <stdio.h>
#include <stdlib.h>
void main() {
    // Write C code here
     int *p1 , *p2 ,  temp , somme ; 
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    printf("Enter the value of p1  ");
    scanf("%d", p1);
    printf("Enter the value of p2  ");
    scanf("%d", p2);
    printf("Before Swapping %d , %d ",*p1,*p2);
    temp = *p1 ;
    *p1=*p2;
    *p2=temp;
    printf("After Swapping %d , %d ",*p1,*p2);
}
