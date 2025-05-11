#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

vector<long long >digit(ll n)
{
    vector<ll>d;
    while(n!=0)
    {
        d.pb(n%10);
        n/=10;
    }
    return d;
}
int main() {   
    fast_io;
    ll n;
    cin>>n;
    vector<ll>dp(n+1,0);
    for(ll i=1;i<=9;i++)
    {
        dp[i]=1;
    }
    for(ll i=10;i<=n;i++)
    {
        vector<ll>d=digit(i);
        ll minans=LLONG_MAX;
        for(ll j=0;j<d.size();j++)
        {   
            if(d[j]==0)
            continue;
            minans=min(minans,1+dp[i-d[j]]);
        }
        dp[i]=minans;
    }
    cout<<dp[n]<<endl;
   
    
}