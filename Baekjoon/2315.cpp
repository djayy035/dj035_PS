#include <bits/stdc++.h>
#define MEM 1005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll t,n,m;
ll dp[MEM][MEM][2], p[MEM];
pi a[MEM];
ll DP(ll l, ll r, ll k){
    if(l==1 && r==n) return 0;
    ll &ret = dp[l][r][k];
    if(ret!=-1) return ret;
    ret = INF;
    ll w=p[n]-(p[r]-p[l-1]), cur=(k ? a[r].x : a[l].x);
    if(l>1) ret = min(ret, DP(l-1, r, 0)+(cur-a[l-1].x)*w);
    if(r<n) ret = min(ret, DP(l, r+1, 1)+(a[r+1].x-cur)*w);
    return ret;
}
int main()
{
    sanic; cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].y;
        p[i] = p[i-1]+a[i].y;
    }
    cout << DP(m,m,0);
}
