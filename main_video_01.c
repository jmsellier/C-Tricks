#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
 signed int n,m;

 for(n=0;n>-50;n--){
  // standard approach
  m=abs(n);
  printf("%d ",m);

  // alternative #1
  m=n>>31;
  m=(n^m)-m;
  printf("%d ",m);

  // alternative #2
  m=n>>31;
  m=(n+m)^m;
  printf("%d ",m);

  // alternative #3
  m=n>>31;
  m=n-((2*n)&m);
  printf("%d ",m);

  // alternative #4
  m=n>>31;
  m=((n>>30)|1)*n;
  printf("%d\n",m);
 }

}
