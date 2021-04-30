#include <bits/stdc++.h>
#define MEM 1008
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e9+7;
vector<pi> v;
ll n,m,k,sum,ans;
ll dp[MEM][MEM];
pi a[MEM];
ll t[MEM];
ll dist(pi c, pi d){
    return abs(c.x-d.x)+abs(c.y-d.y);
}
ll DP(ll l, ll r){
    if(l==m || r==m) return 0;
    ll& ret = dp[l][r];
    if(ret!=-1) return ret;
    ll nxt = max(l,r)+1;
    if(!l) ret = DP(nxt,r)+dist({1,1},a[nxt]);
    else ret = DP(nxt,r)+dist(a[l],a[nxt]);
    if(!r) ret = min(DP(l,nxt)+dist({n,n},a[nxt]), ret);
    else ret = min(DP(l,nxt)+dist(a[r],a[nxt]), ret);
    return ret;
}
void trace(ll l, ll r){
    if(l==m || r==m) return;
    ll nxt = max(l,r)+1;
    ll s,e;
    if(!l) s = DP(nxt,r)+dist({1,1},a[nxt]);
    else s = DP(nxt,r)+dist(a[l],a[nxt]);
    if(!r) e = DP(l,nxt)+dist({n,n},a[nxt]);
    else e = DP(l,nxt)+dist(a[r],a[nxt]);
    if(s>e){
        t[nxt] = 2;
        trace(l, nxt);
    }
    else{
        t[nxt] = 1;
        trace(nxt, r);
    }
}
main(){
    sanic;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    cin >> m;
    for(int i=1; i<=m; i++)
        cin >> a[i].x >> a[i].y;
    cout << DP(0,0) << '\n';
    trace(0,0);
    for(int i=1; i<=m; i++)
        cout << t[i] << '\n';
}

