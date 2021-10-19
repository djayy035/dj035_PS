#include <bits/stdc++.h>
#define MEM 252525
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
ll par[MEM];
ll f(ll x) {
    if(x==par[x]) return x;
    return par[x] = f(par[x]);
}
void uni(ll x, ll y){
    x = f(x);
    y = f(y);
    par[y] = x;
}
ll t,n,m,ans;
vector<ll> g[MEM];
pi a[MEM];
signed main(){
    sanic;
    cin >> n;
    vector<pi> v;
    for(int i=0; i<n; i++){
        ll q1,q2;
        cin >> q1 >> q2;
        v.pb({q1,i+1});
        v.pb({q2,i+1});
        par[i+1] = i+1;
        ans += q1+q2;
        a[i+1] = {q1,q2};
    }
    sort(all(v));
    for(int i=1; i<v.size(); i++)
        if(v[i-1].x==v[i].x && f(v[i-1].y)!=f(v[i].y)) uni(v[i-1].y, v[i].y);
    for(int i=1; i<=n; i++)
        g[f(i)].pb(i);
    for(int i=1; i<=n; i++){
        vector<ll> c;
        if(!g[i].size()) continue;
        for(ll j:g[i]){
            c.pb(a[j].x);
            c.pb(a[j].y);
        }
        sort(all(c));
        c.erase(unique(all(c)), c.end());
        for(int j=0; j<g[i].size(); j++) ans -= c[j];
    }
    cout << ans;
}
