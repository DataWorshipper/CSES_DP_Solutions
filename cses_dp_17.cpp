#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];
vector<ll> sieve(ll sieve_size)
{
    vector<ll> s(sieve_size + 1, 1);
    s[0] = s[1] = 0;  
 
    for (ll i = 2; i * i <= sieve_size; i++)
    {
        if (s[i] == 1)
        {
            for (ll j = i * i; j <= sieve_size; j += i)  
            {
                s[j] = 0;
            }
        }
    }
    return s;
}
ll dp[19][2][10][2];




ll count(string s, int ind, int tight, int prev, int valid) {
    int sz = s.size();
    if (ind == sz) {
        return valid == 1 ? 1 : 0;
    }

    if (dp[ind][tight][prev][valid] != -1) {
        return dp[ind][tight][prev][valid];
    }

    int limit = tight ? (s[ind] - '0') : 9;
    ll ans = 0;

    for (int d = 0; d <= limit; d++) {
        int newTight = tight & (d == (s[ind] - '0'));
        if (valid == 0 && d == 0) {
            // still leading zero
            ans += count(s, ind + 1, newTight, prev, 0);
        } else if (valid == 0 && d > 0) {
            // first non-zero digit
            ans += count(s, ind + 1, newTight, d, 1);
        } else if (prev != d) {
            // adjacent digits must differ
            ans += count(s, ind + 1, newTight, d, 1);
        }
    }

    return dp[ind][tight][prev][valid] = ans;
}

int main()
{   
    fast_io;
ll a,b;
cin>>a>>b;
memset(dp, -1, sizeof(dp));
string s1=to_string(a-1);
string s2=to_string(b);
ll c1=count(s1,0,1,10,0);
memset(dp, -1, sizeof(dp));
ll c2=count(s2,0,1,0,0);
if(a==0)
cout<<(c2-c1+1)<<endl;
else
cout<<c2-c1<<endl;

}
