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
    ll n;
    cin>>n;
    vector<ll>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    v<ll>a;
    ll MOD=1e9+7;
    a.insert(a.begin(),{1,2,3,4,5,6});
    for(ll i=2;i<=n;i++)
    {
        for(ll c=0;c<a.size();c++)
        {
            if(i-a[c]>=0)
            dp[i]=(dp[i]+dp[i-a[c]])%MOD;
        }
        
    }
    cout<<dp[n]<<endl;
    
    
}