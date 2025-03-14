#include <bits/stdc++.h>
#define ll long long
#define MEM 10004
#define x first
#define y second
#define sz size()
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<ll, ll> pi;
const ll INF = 4e18;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
ll abs(ll a, ll b)
{
    return (a > b ? a - b : b - a);
}
ll add(ll a, ll b)
{
    return ((a + b) % MOD + MOD) % MOD;
}
ll sub(ll a, ll b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
ll mul(ll a, ll b)
{
    return ((a * b) % MOD + MOD) % MOD;
}
ll n,m,ans;
ll a[MEM];
ll dp[MEM][511];
ll DP(ll x, ll y){
    if(x==n) {
        if(y>0) return -INF;
        return 0;
    }
    ll &ret = dp[x][y];
    if(ret!=-1) return ret;
    ret = -INF;
    if(y+1<=m) ret = max(ret, DP(x+1, y+1)+a[x]);
    if(y>0){
        if(x+y<=n) ret = max(ret, DP(x+y, 0));
    }
    else ret = max(ret, DP(x+1, 0));
    return ret;
}
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << DP(0, 0);
}
