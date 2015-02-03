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

const int ALPH_SIZE = 10;

struct Node
{
    int words;              
    int prefixes;           
    vector<Node*> links;    
    
    Node(){
        words = prefixes = 0;
        links.resize(ALPH_SIZE,NULL);
    }
};

class Trie
{
    public :
    
    Trie()
	{
        myRoot = new Node();
        myCount = 1;
    }
    int countPrefixes(const string& s) const;
    void insert(const string s);
    
    private :
    
    Node* myRoot;       
    int myCount;        
};

int Trie::countPrefixes(const string& s) const
{
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'0']==NULL) return 0;
        t = t->links[s[k]-'0'];
    }
    
    return t->prefixes;
}

void Trie::insert(const string s){
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
	    if(t->links[s[k]-'0']==NULL){
	        t->links[s[k]-'0'] = new Node();
	        ++myCount;
	    }
	    t = t->links[s[k]-'0'];
	    ++(t->prefixes);
    }
    
    ++(t->words);
}

int main()
{
	//your code goes here
    int T,N;
    char str[100010];
    string pin[100010];
    
    T = inp();
    
    while(T--)
	{
        N = inp();
        
        Trie* myTrie;
        myTrie = new Trie();
        
        bool flag = true;
        
        for(int i = 0;i<N;++i)
		{
            scanf("%s",str);
            pin[i] = string(str);
        }
        
        sort(pin,pin+N);
        
        for(int i=N-1;i>=0 && flag;--i)
		{
            myTrie->insert(pin[i]);
            if (myTrie->countPrefixes(pin[i])>1 ) 
				flag = false;
        }
        
        delete myTrie;
        
        if ( flag )
			printf("YES\n");
		else
			printf("NO\n");
    }
        
    return 0;   
}