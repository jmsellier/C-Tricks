#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// naive implementation
int naive(int x){
 if(x<0.) return(-1); // undefined
 else if(x==0) return(0);
 else return(pow(2,floor(log2(x)))); // x>0.
}

// branch-free implementation
int branch_free(unsigned x){
 x=x | (x>>1);
 x=x | (x>>2);
 x=x | (x>>4);
 x=x | (x>>8);
 x=x | (x>>16);
 return(x-(x>>1));
}

// simple loops

int simple(unsigned x){
 unsigned y;

 y=0x80000000;
 while(y>x)
  y=y>>1;
 return(y);
}

int main(void){
 int n;

 for(n=0;n<=32;n++){
  printf("%d # %d # %d # %d\n",n,naive(n),branch_free((unsigned)(n)),simple((unsigned)(n)));
 }

 return(0);
}
