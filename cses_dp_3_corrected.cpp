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
   ll MOD=1e9+7;
   vector<ll>dp(x+1,0);
   dp[0]=1;
   for(ll j=1;j<=x;j++)
   {
  for(ll i=0;i<n;i++)
  {
      
      
          if(j-c[i]>=0)
          dp[j]+=(dp[j-c[i]])%MOD;
      }
  }
  cout<<dp[x]%MOD<<endl;
    
}