#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define MEM 111111
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
const ll MOD = 1e9+7;
const ll INF = 2e9+7;
ll mul(ll a, ll b){
    return ((a*b)%MOD+MOD)%MOD;
}
ll add(ll a, ll b){
    return ((a+b)%MOD+MOD)%MOD;
}
bool cp(pi a, pi b){
    return a.x*b.y<b.x*a.y;
}
ll t,n,m;
ll a[MEM], b[MEM], c[MEM];
ll f(ll x){
    for(int i=1; i<=m; i++)
        c[i] = 1;
    ll p=0, o=x-m, q=0;
    for(int i=x; i>0; i--){
        //cout << a[i] << ' ' << b[a[i]] << ' ' << c[a[i]] << '\n';
        if(!a[i]) q--;
        else if(b[a[i]]-(o+min(q,0LL))<=0 && c[a[i]]){
            p++;
            c[a[i]] = 0;
            o -= b[a[i]];
            o += min(q,0LL);
            q += b[a[i]];
        }
    }
    //cout <<x <<' ' << p << '\n';
    if(p==m) return 1;
    else return 0;
}
signed main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];
    ll l=0, r=n;
    while(l<=r){
        ll mid=(l+r)>>1;
        ll pos=f(mid);
        //cout <<mid << ' ' << pos << '\n';
        if(!pos) l = mid+1;
        else r = mid-1;
    }
    cout << (l>n ? -1:l);
}
