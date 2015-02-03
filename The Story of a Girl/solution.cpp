#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define getcx getchar_unlocked
#ifndef ONLINE_JUDGE
    #define getcx getchar
#endif
#define ull unsigned long long int
#define lli long long int
#define li long int
#define ii int
#define mod 1000000007
/* Created by : Rahul Johari
				Thapar University */
				
inline int inp()
{
   int n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   return n*sign;
}
inline long long in()
{
   long long n=0;
   long long ch=getcx();long long sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   return n*sign;
}
 
void multiply(lli F[2][2], lli M[2][2]);
 
void power(lli F[2][2], lli n);
 
lli fib(lli n)
{
  lli F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 
void power(lli F[2][2], lli n)
{
  if( n == 0 || n == 1)
      return;
  lli M[2][2] = {{1,1},{1,0}};
 
  power(F,n/2);
  multiply(F,F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(lli F[2][2], lli M[2][2])
{
  lli x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  lli y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  lli z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  lli w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
}
 
int main()
{
	lli t,n;
	t = in();
	while ( t-- )
	{
		n = in();
		printf("%lld\n", fib(n));
	}
	return 0;
}