#include <bits/stdc++.h>
#define MEM 1006
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll t,n,m,k,c,ans;
ll dp[MEM][11][11][11];
ll DP(ll a, ll b, ll c, ll d){
    if(a==n) return !b;
    ll& ret = dp[a][b][c][d];
    if(ret!=-1) return ret;
    ret = 0;
    if(d<10){
        for(int i=c; i<=9; i++){
            if(c+d==i) ret += DP(a+1, b, c+d, d);
            else ret += DP(a+1, b-1, i, 10);
            ret %= MOD;
        }
    }
    else{
        for(int i=c; i<=9; i++){
            ret += DP(a+1, b, i, i-c);
            ret %= MOD;
        }
    }
    return ret;
}
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(k>9){
        cout << 0;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=9; i++){
        ans += DP(1LL, k-1, i, 10);
        ans %= MOD;
    }
    cout << ans;
}
