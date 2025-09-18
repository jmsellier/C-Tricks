#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
 int m,n;

 int l=100;

 for(n=0;n<50;n++){
  printf("floor() ");

  // standard floor function
  m=floor(0.5*(l+n));
  printf("%d ",m);

  // alternative to floor
  m=(n&l)+((n^l)>>1);
  printf("%d ",m);

  printf(" - ceil() ");

  // standard ceil function
  m=ceil(0.5*(l+n));
  printf("%d ",m);

  // alternative to ceil
  m=(n|l)-((n^l)>>1);
  printf("%d ",m);

  printf("\n");
 }

 return(0);
}
