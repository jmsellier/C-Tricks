#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sign(int n){
 int ret;

 if(n<0) ret=-1;
 else if(n==0) ret=0;
 else ret=1;

 return(ret);
}

int main(void)
{
 int m,n;

 for(n=-10;n<10;n++){
  printf("n = %d -- ",n);

  // standard approach
  m=sign(n);
  printf("%d ",m);

  // alternative #1
  m=(-(n>>31)|((-n)>>31));
  printf("%d ",-m);

  // alternative #2
  m=(n>0)-(n<0);
  printf("%d ",m);

  // alternative #3
  m=(n>=0)-(n<=0);
  printf("%d ",m);

  printf("\n");
 }

 return(0);
}
