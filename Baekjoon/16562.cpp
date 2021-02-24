#include <bits/stdc++.h>
#define MEM 10006
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1234567891
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll t,n,k;
ll par[MEM],c[MEM],dp[MEM];
ll f(ll x) {
    if(x==par[x])return x;
    return par[x] = f(par[x]);
}
void uni(int x, int y){
    x = f(x);
    y = f(y);
    par[y] = x;
}
main()
{
    sanic; cin.tie(0);
    cin >> n >> k >> t;
    for(int i=1; i<=n; i++)
        cin >> c[i];
    for(int i=1; i<=n; i++)
        par[i] = i;
    for(int i=0; i<k; i++){
        ll x,y;
        cin >> x >> y;
        if(x>y) swap(x,y);
        uni(x,y);
    }
    for(int i=1; i<=n; i++){
        ll o=f(i);
        if(!dp[o]) dp[o] = INF;
        dp[o] = min(dp[o], c[i]);
    }
    ll ans=accumulate(dp+1,dp+n+1,0LL);
    if(ans>t) cout << "Oh no";
    else cout << ans;
}
