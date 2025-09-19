#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// efficient multiplication for unsigned words
void mult(unsigned short w[],unsigned short u[],
         unsigned short v[],int m, int n){
 unsigned int k,t,b;
 int i,j;

 for(i=0;i<m;i++) w[i]=0;

 for(j=0;j<n;j++){
  k=0;
  for(i=0;i<m;i++){
   t=u[i]*v[j]+w[i+j]+k;
   w[i+j]=t;
   k=t >> 16;
  }
  w[j+m]=k;
 }

 return;
}

int main(void)
{
 int i,j;
 int m=2;
 int n=2;
 unsigned short u[]={0,0}; // modified during the nested loop below
 unsigned short v[]={1,0}; // always 10
 unsigned short w[]={0,0,0}; // store the result of the multiplication

 for(i=0;i<2;i++){
  u[0]=i;
  for(j=0;j<10;j++){
   u[1]=j;
   mult(w,u,v,m,n);
   printf("%d%d * %d%d = %d # %d%d%d\n",u[0],u[1],v[0],v[1],(j+i*10)*10,w[0],w[1],w[2]);
  }
 }

 return(0);
}
