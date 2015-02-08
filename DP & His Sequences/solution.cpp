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

#define inf 2000000000

int n;
int low_limit = -inf;
int up_limit = inf;
    
int main()
{
    int m,i,x=0,ans;
	//freopen("mea10b.in","r",stdin);
	//freopen("out10b.txt","w",stdout);
    n = inp();
    
    for ( i=0;i<n;i++ ) 
	{
		m = inp();
        if ( i%2==0 ) 	// new upper limit
		{ 
            x += m;
            if ( up_limit > x )
                up_limit = x;
			
            x += m;
        } 
		else 			// new lower limit
		{ 
            x -= m;
            if ( low_limit < x )
                low_limit = x;
			
            x -= m;
        }
    }
    
    ans = up_limit - low_limit + 1;
    if ( ans>0 )
		write(ans);
	else
		printf("no solution\n");

    return 0;
}