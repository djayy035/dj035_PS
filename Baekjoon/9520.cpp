#include <bits/stdc++.h>
#define MEM 1515
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
ll dp[MEM][MEM];
ll c[MEM][MEM];
ll DP(ll l, ll r){
    if(l==n || r==n) return 0;
    ll &ret = dp[l][r];
    if(ret!=-1) return ret;
    ret = 0;
    ll nx=max(l,r)+1;
    ret = min(DP(nx, r)+c[nx][l], DP(l, nx)+c[r][nx]);
    return ret;
}
signed main() {
    sanic;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> c[i][j];
    cout << DP(1, 2)+c[1][2];
}
