#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

int main() {   
    fast_io;
    ll n,x;
    cin>>n>>x;
   v<ll>c(n);
   f(c,n);
   vector<ll>dp(x+1,LLONG_MAX);
   dp[0]=0;
   for(ll i=1;i<=x;i++)
   {
       for(ll j=0;j<n;j++)
       {
           if(i-c[j]>=0 &&dp[i-c[j]]!=LLONG_MAX)
           dp[i]=min(dp[i],1+dp[i-c[j]]);
       }
   }
   if(dp[x]!=LLONG_MAX)
   cout<<dp[x]<<endl;
   else
   cout<<-1<<endl;
    
}