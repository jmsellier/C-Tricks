#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// unsigned division by 3
unsigned div3(unsigned n){
 unsigned n0,n1,w0,w1,w2,t,q;

 n0=n & 0xFFFF;
 n1=n >> 16;
 w0=n0*0xAAAB;
 t=n1*0xAAAB+(w0 >> 16);
 w1=t & 0xFFFF;
 w2=t >> 16;
 w1=n0*0xAAAA+w1;
 q=n1*0xAAAA+w2+(w1 >> 16);

 return(q >> 1);
}

// unsigned division by 5
unsigned div5(unsigned n){
 unsigned q,r;

 q=(n >> 3)+(n >> 4);
 q=q+(q >> 4);
 q=q+(q >> 8);
 q=q+(q >> 16);
 r=n-q*5;

 return(q+(13*r >> 6));
}

// unsigned division by 10
unsigned div10(unsigned n){
 unsigned q,r;

 q=(n >> 1)+(n >> 2);
 q=q+(q >> 4);
 q=q+(q >> 8);
 q=q+(q >> 16);
 q=q >> 3;
 r=n-q*10;

 return(q+((r+6) >> 4));
}

// unsigned division by 100
unsigned div100(unsigned n){
 unsigned q,r;

 q=(n >> 1)+(n >> 3)+(n >> 6)-(n >> 10)+
   (n >> 12)+(n >> 13)-(n >> 16);
 q=q+(q >> 20);
 q=q >> 6;
 r=n-q*100;

 return(q+((r+28) >> 7));
}

int main(void)
{
 unsigned n;

 // some examples below
 for(n=4;n<160;n+=40){
  printf("------------\n");
  printf("%d / 3 = %d # %d\n",n,n/3,div3(n));
  printf("%d / 5 = %d # %d\n",n,n/5,div5(n));
  printf("%d / 10 = %d # %d\n",n,n/10,div10(n));
  printf("%d / 100 = %d # %d\n",n,n/100,div100(n));
 }

 return(0);
}
