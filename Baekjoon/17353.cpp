#include <bits/stdc++.h>
#define MEM 1000005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
struct Tr{
    ll v,l;
};
ll t,n,m,k;
ll a[MEM];
Tr tree[4*MEM];
ll init(ll nd, ll l, ll r){
    if(l==r && l>0) return tree[nd].v = a[l]-a[l-1];
    ll mid = (l+r)/2;
    return tree[nd].v = init(nd*2, l, mid)+init(nd*2+1, mid+1, r);
}
void propagate(ll nd, ll s, ll e){
    if(tree[nd].l){
        tree[nd].v += (e-s+1)*tree[nd].l;
        if(s!=e){
            tree[nd*2].l += tree[nd].l;
            tree[nd*2+1].l += tree[nd].l;
        }
        tree[nd].l = 0;
    }
}

void lazy(ll nd, ll val, ll l, ll r, ll s, ll e){
    propagate(nd,s,e);
    if(s>r || l>e) return;
    if(l<=s && e<=r) {
        tree[nd].l+=val;
        propagate(nd,s,e);
        return;
    }
    ll mid = (s+e)/2;
    lazy(nd*2, val, l, r, s, mid);
    lazy(nd*2+1, val, l, r, mid+1, e);
    tree[nd].v = tree[nd*2].v+tree[nd*2+1].v;
}

ll sumq(ll nd, ll l, ll r, ll s, ll e){
    propagate(nd,s,e);
    if(s>r || l>e) return 0;
    if(l<=s && e<=r) return tree[nd].v;
    ll mid = (s+e)/2;
    return sumq(nd*2, l, r, s, mid)+sumq(nd*2+1, l, r, mid+1, e);
}
int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    init(1,1,n);
    cin >> m;
    while(m--){
        ll q1,q2,q3;
        cin >> q1 >> q2;
        if(q1==1){
            cin >> q3;
            lazy(1, 1, q2, q3, 1, n);
            lazy(1, -q3+q2-1, q3+1, q3+1, 1, n);
        }
        else
            cout << sumq(1, 1, q2, 1, n) << '\n';
    }
}
