#include <bits/stdc++.h>
#define MEM 102
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz size()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e18;
const ll MOD = 20070713;
ll t,n,m,k;
vector<pair<pi, ll>> g[MEM];
ll dp[MEM][MEM*100];
ll DP(ll cur, ll tm){
    ll &ret = dp[cur][tm];
    if(ret!=-1) return ret;
    if(cur==n) return ret=0;
    ret = INF;
    for(int i=0; i<g[cur].sz; i++){
        ll nt=g[cur][i].y;
        if(tm-g[cur][i].x.y>=0) ret = min(ret, DP(nt, tm-g[cur][i].x.y)+g[cur][i].x.x);
    }
    return ret;
}
signed main(){
    sanic; cin.tie(0);
    cin >> n;
    cin >> m >> k;
    cin >> t;
    for(int i=0; i<t; i++){
        ll q1,q2,q3,q4;
        cin >> q1 >> q2 >> q3 >> q4;
        g[q1].pb({{q4, q3}, q2});
        g[q2].pb({{q4, q3}, q1});
    }
    memset(dp, -1, sizeof(dp));
    ll ans=DP(1, m);
    if(ans<=k)cout << ans;
    else cout << -1;
}

