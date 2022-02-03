#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define MEM 55555
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
const ll INF = 2e18+7;
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
ll cx[MEM],cy[MEM];
string mp[MEM];
signed main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> mp[i];
        ll o1=INF,o2=INF, q1=0, q2=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                cx[i] = 0;
                cy[j] = 0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                cx[i] += (mp[i][j]=='.');
                cy[j] += (mp[i][j]=='.');
            }
        }
        ll ans=INF;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                ans = min(ans, cx[i]+cy[j]-(mp[i][j]=='.'));
        }
        cout << ans << '\n';
    }
}
