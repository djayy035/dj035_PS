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
ll a[MEM];
signed main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; ; i++){
        if((n*i)%10==0 || (n*i)%10==m){
            cout << i << '\n';
                break;
        }
    }
}
