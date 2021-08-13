#include <bits/stdc++.h>
#define MEM 55
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}

ll t,n,m;
ll dp[MEM][MEM];
ll DP(ll a, ll b){
    if(b<0) return 0;
    if(a==n) return !b;
    ll& ret = dp[a][b];
    if(ret!=-1) return ret;
    return ret = DP(a+1, b+1) + DP(a+1, b-1);
}
void tr(ll a, ll b, ll k){
    if(a==n) return;
    if(DP(a+1, b+1)<=k){
        cout << ')';
        tr(a+1, b-1, k-DP(a+1, b+1));
    }
    else{
        cout << '(';
        tr(a+1, b+1, k);
    }
}
int main()
{
    sanic; cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    if(DP(0,0)<=m) cout << -1;
    else tr(0,0,m);
}

