#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

int main()
{   
    fast_io;
    ll n, x;
    cin >> n >> x;
    v<ll> h(n), s(n);
    f(h, n);
    f(s, n);

    vector<ll> dp(x + 1, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], s[i] + dp[j - h[i]]);
        }
    }

    cout << dp[x] << "\n";
}
