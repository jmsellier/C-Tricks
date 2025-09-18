#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(int n,int m){
 int ret;

 if(n<m) ret=-1;
 else if(n>m) ret=1;
 else ret=0;

 return(ret);
}

int main(void)
{
 int n,ret;
 int m=-1;

 for(n=-10;n<10;n++){
  printf("%d %d --> ",n,m);

  // standard method
  ret=cmp(n,m);
  printf("%d ", ret);

  // alternative #1
  ret=(n>m)-(n<m);
  printf("%d ", ret);

  // alternative #2
  ret=(n>=m)-(n<=m);
  printf("%d ", ret);

  printf("\n");
 }

 return(0);
}
