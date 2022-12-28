#include<stdio.h>
#include<stdlib.h>
void main()
{
printf("enter table size: \n");
int n ;
scanf("%d", &n); 
int *t; 
t= (int*)malloc(n*sizeof(int)); 
for(int i=0 ; i<n ; i++)
{
printf("t[%d]=",i);
scanf("%d",t+i);
}
int *p,i;
int *posmin;
posmin=t;
for(p=t ; p<t+n ; p++)
{i=p-t;
printf("t[%d]=%d \t ",i,*p);
if (*p < *posmin)
{posmin=p;
}

}
printf("\n min= %d" , *posmin);



}

