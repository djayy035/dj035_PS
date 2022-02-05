#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define MEM 444444
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
ll t,n,m,k,l;
ll a[MEM], b[MEM], c[MEM];
signed main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ll sm=(a[i]*a[i]+a[i])/2;
        b[i] = a[i];
        a[n+i] = a[i];
        c[i] = sm;
        b[i] += b[i-1];
        c[i] += c[i-1];
    }
    for(int i=n+1; i<=2*n; i++){
        ll sm=(a[i]*a[i]+a[i])/2;
        b[i] = a[i];
        c[i] = sm;
        b[i] += b[i-1];
        c[i] += c[i-1];
    }
    n *= 2;
    ll ans=0;
    for(int i=1; i<=n; i++){
        if(b[i]<m) continue;
        ll p=upper_bound(b,b+n+1,b[i]-m)-b;
        ll o=c[i]-c[p-1];
        ll ch=b[i]-b[p-1]-m;
        o -= (ch*ch+ch)/2;
        ans = max(ans, o);
    }
    cout << ans;
}
