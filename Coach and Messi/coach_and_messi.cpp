#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x);
#ifndef ONLINE_JUDGE
    #define getcx getchar
#endif
using namespace std;
#define ull unsigned long long int
#define lli long long int
#define li long int
#define ii int
lli mod = 1000000007;
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

inline void write (lli n)
{
    lli N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

int A[100010];
int B[100010];

inline lli powmod(lli N, lli K, lli mod	)
{
    if(K==0) return 1;
    if(K==1) return N%mod;
    if(K%2 ==0)
    {
        lli temp = powmod(N,K/2,mod);
        return (temp*temp)%mod;
    }
    else
    {
        lli temp = powmod(N,K/2,mod);
        temp = (temp*temp)%mod;
        return (temp*N)%mod;
    }
}

int main()
{
    int T,i;
    string s1,s2;
    
	T = inp();
    
	while(T--)
    {
        lli M = 1000000007;
		lli N = 1000000006;
		lli X,Y;

		cin>>s1>>s2;

        for ( i=0;i<s1.length();i++ )
            A[i] = s1[i] - 48 ;

		for ( i=0;i<s2.length();i++ )
            B[i] = s2[i] - 48 ;
        
        X = A[0] % M;
        for ( i=1;i<s1.length();i++ )
            X = (10*X + A[i])% M; 

		Y = B[0] % N;
        for ( i=1;i<s2.length();i++ )
            Y = (10*Y + B[i])% N;
      
        write(powmod(X,Y,mod));
		printf("\n");
    }
   return 0;
}