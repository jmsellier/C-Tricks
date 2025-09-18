#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// naive approach
int naive(int x){
 if(x<0.) return(-1); // undefined
 else if(x==0) return(0); // x=0.
 else return(pow(2,ceil(log2(x)))); // x>0.
}

// alternative approach
unsigned alternative(unsigned x){
 x=x-1;
 x=x | (x>>1);
 x=x | (x>>2);
 x=x | (x>>4);
 x=x | (x>>8);
 x=x | (x>>16);

 return(x+1);
}

int main(void){
 int n;

 for(n=0;n<=32;n++){
  printf("%d # %d # %d\n",n,naive(n),alternative((unsigned)(n)));
 }

 return(0);
}
