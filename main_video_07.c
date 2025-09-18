#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// divide-and-conquer approach
int divide_and_conquer(unsigned n){
 unsigned x;

 x=n;
 x=(x & 0x55555555) + ((x >> 1) & 0x55555555);
 x=(x & 0x33333333) + ((x >> 2) & 0x33333333);
 x=(x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
 x=(x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
 x=(x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);

 return(x);
}

// 2-bit field approach
int two_bit_field(unsigned n){
 unsigned x;

 x=n;
 x=x-((x >> 1) & 0x55555555);
 x=(x & 0x33333333) + ((x >> 2) & 0x33333333);
 x=(x+(x >> 4)) & 0x0F0F0F0F;
 x=x+(x >> 8);
 x=x+(x >> 16);

 return(x & 0x0000003F);
}

// 3-bit field approach
int three_bit_field(unsigned x){
 unsigned n;

 n=(x >> 1) & 033333333333;
 x=x-n;
 n=(n >> 1) & 033333333333;
 x=x-n;
 x=(x+(x >> 3)) & 030707070707;
 
 return(x%63);
}

// for 64-bit integers
int pop_count_64(unsigned x){
 unsigned long long y;

 y=x*0x0002000400080010ULL;
 y=y&0x1111111111111111ULL;
 y=y*0x1111111111111111ULL;
 y=y >> 60;

 return(y);
}

int main(void)
{
 unsigned n;

 for(n=0;n<=32;n++){
  printf("%d # %d # %d # %d # %d\n",n,divide_and_conquer(n),two_bit_field(n),three_bit_field(n),pop_count_64(n));
 }

 return(0);
}
