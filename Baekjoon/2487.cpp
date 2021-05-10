#include <bits/stdc++.h>
#define MEM 200005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e18+7;
ll t,n,m,ans;
ll a[MEM], p[MEM], r[MEM];
ll find(ll u){
    if(p[u]==u) return u;
    return p[u] = find(p[u]);
}
void merg(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a!=b) p[a] = b;
}
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}
main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        p[i] = i;
    for(int i=0; i<n; i++){
        cin >> a[i];
        merg(a[i],i+1);
    }

    for(int i=0; i<n; i++)
        r[find(a[i])]++;
    sort(r,r+n);
    ans = 1LL;
    ll g=0,h=0;
    for(int i=n-1; r[i]>1; i--)
        ans = lcm(ans, r[i]);
    cout << ans;
}
