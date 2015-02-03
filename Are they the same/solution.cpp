/* this solution will fetch you a score of 88.87 */
/* you have minimise the code length */
/* if anybody has a better solution, you can show us */

#include<bits/stdc++.h>
using namespace std;main(){char s[99],S[99];cin>>s>>S;sort(s,s+strlen(s));sort(S,S+strlen(S));if(!strcmp(s,S))cout<<"YES\n";else cout<<"NO\n";}