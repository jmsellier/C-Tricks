#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// population count for 64-bit integers
int pop_count_64(unsigned x){
 unsigned long long y;

 y=x*0x0002000400080010ULL;
 y=y&0x1111111111111111ULL;
 y=y*0x1111111111111111ULL;
 y=y >> 60;

 return(y);
}

// naive parity for 64-bit integers
int naive_parity(unsigned x){
 int num_one_bits;

 num_one_bits=pop_count_64(x);
 if((num_one_bits%2)==0) return(0);
 else return(1);
}

// efficient parity computation
int eff_parity(unsigned x){
 unsigned y;

 y=x^(x >> 1);
 y=y^(y >> 2);
 y=y^(y >> 4);
 y=y^(y >> 8);
 y=y^(y >> 16);

 if((y%2)==0) return(0);
 else  return(1);
}

int main(void){
 int n;

 for(n=0;n<=32;n++){
  printf("%d # %d # %d\n",n,naive_parity(n),eff_parity(n));
 }

 return(0);
}
