#include<stdio.h>
#include<stdlib.h>
void main()
{
int **mat,r,c,i,j; 
printf("enter matrix size R C ");
scanf("%d",&r);
scanf("%d",&c); 
mat=(int**)malloc(r*sizeof(int*)); 
for(i=0;i<r;i++)
  {mat[i]=(int*)malloc(c*sizeof(int));}
for(i=0;i<r;i++)
  {for(j=0;j<c;j++)
          {mat[i][j]=rand()%21;}
  }
  
for(i=0;i<r;i++)
  {printf("\n");
  for( j=0;j<c;j++)
  {
    printf("MAT[%d][%d]=%d \t ",i,j,mat[i][j]);}
   }

}
