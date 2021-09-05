#include <bits/stdc++.h>
#define MEM 111
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll t,n,m,k,ans;
ll dp[MEM];
signed main() {
    sanic;
    cin >> n;
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1]+dp[i-2];
    cout << dp[n];
}
