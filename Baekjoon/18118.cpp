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
ll dp[11][MEM];
signed main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
                dp[i][j] = -INF;
        dp[0][0] = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                for(int k=0; k<=10; k++){
                    if(k<10) dp[i+1][(10*j+k)%m] = max(10LL*dp[i][j]+k, dp[i+1][(10LL*j+k)%m]);
                    else dp[i+1][(100*j+11)%m] = max(100LL*dp[i][j]+11, dp[i+1][(100LL*j+11)%m]);
                }
            }
        
        cout << dp[n][0] << '\n';
    }
}
