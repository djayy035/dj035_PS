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
ll n,m;
ll dp[MEM][MEM*111];
signed main() {
    sanic; 
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        ll w,v;
        cin >> w >> v;
        for(int j=1; j<=m; j++){
            if(w>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
        }
    }
    cout << dp[n][m];
}

