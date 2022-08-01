#include <bits/stdc++.h>
#define MEM 333333
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
const ll INF = 1e17;
const ll MOD = 20070713;
struct pp{
    ll a,b,c,d;
};
ll tr[MEM*4][2];
void upd(ll nd, ll p, ll v, ll l, ll r, ll id){
    if(p<l || r<p) return;
    if(l==r){
        tr[nd][id] = min(v, tr[nd][id]);
        return;
    }
    ll mid=l+r>>1;
    upd(nd<<1, p, v, l, mid, id);
    upd(nd<<1|1, p, v, mid+1, r, id);
    tr[nd][id] = min(tr[nd<<1][id], tr[nd<<1|1][id]);
}
ll query(ll nd, ll s, ll e, ll l, ll r, ll id){
    if(e<l || r<s) return INF;
    if(s<=l && r<=e) return tr[nd][id];
    ll mid=l+r>>1;
    return min(query(nd<<1, s, e, l, mid, id), query(nd<<1|1, s, e, mid+1, r, id));
}
ll t,n,m,k;
ll aa,bb,cc,dd,l,r;
pp a[MEM];
signed main(){
    sanic; cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<=m*12; i++)
        tr[i][0] = tr[i][1] = INF;
    vector<ll> v;
    aa = INF;
    for(int i=0; i<m; i++){
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
        aa = min(aa, a[i].a);
        bb = max(bb, a[i].b);
        v.pb(a[i].a);
        v.pb(a[i].b);
        v.pb(a[i].c);
    }
    if(aa>1 || bb<n){
        cout << -1;
        return 0;
    }
    sort(all(v));
    ll o=0;
    v.erase(unique(all(v)), v.end());
    for(int i=0; i<m; i++){
        a[i].a = lower_bound(all(v), a[i].a)-v.begin();
        a[i].b = lower_bound(all(v), a[i].b)-v.begin();
        a[i].c = lower_bound(all(v), a[i].c)-v.begin();
        //cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c <<'\n';
        o = max(o, a[i].b);
    }
    upd(1, 0, 0, 0, 3*m, 0);
    upd(1, o, 0, 0, 3*m, 1);
    ll ans=INF;
    for(int i=0; i<m; i++){
        aa=a[i].a, bb=a[i].b, cc=a[i].c, dd=a[i].d;
        l=query(1, aa, bb, 0, 3*m, 0), r=query(1, aa, bb, 0, 3*m, 1);
        ans = min(ans, l+r+dd);
        upd(1, cc, dd+l, 0, 3*m, 0);
        upd(1, cc, dd+r, 0, 3*m, 1);
    }
    cout << (ans>=INF ? -1:ans);
}

