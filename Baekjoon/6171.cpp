#include <bits/stdc++.h>
#define sanic ios_base::sync_with_stdio(0);
#define MEM 500005
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const ll MOD = 1e9+7;
const ll INF = 1e13;
struct{
    int s=0, e=0, id[MEM];
    pi f[MEM];
    double cross(int a, int b) {
        return 1.0*(f[a].y-f[b].y)/(f[b].x-f[a].x);
    }
    void ins(pi v, int l){
        f[e] = v;
        id[e] = l;
        while(s+1<e && cross(e-2,e-1)>cross(e-1,e)){
            f[e-1] = f[e];
            id[e-1] = id[e];
            e--;
        }
        e++;
    }
    ll query(ll x){
        while(s+1<e && f[s+1].y-f[s].y<=x*(f[s].x-f[s+1].x))
            s++;
        return f[s].x*x+f[s].y;
    }
} CHT;
ll t,n,m;
vector<pi> ee,v;
int main() {
    sanic; cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        pi q;
        cin >> q.x >> q.y;
        ee.pb(q);
    }
    sort(all(ee));
    v.pb(ee[n-1]);
    for(int i=n-2; i>=0; i--){
        if(ee[i].y>v.back().y)
            v.pb(ee[i]);
    }
    reverse(all(v));
    ll ans=0;
    for(int i=0; i<v.size(); i++){
        CHT.ins({v[i].y,ans}, i);
        ans = CHT.query(v[i].x);
    }
    cout << ans;
    return 0;
}
