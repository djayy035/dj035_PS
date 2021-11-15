#include <bits/stdc++.h>
#define MEM 500005
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
ll dp[2][MEM];
int main()
{
    sanic; cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        ll q;
        cin >> q;
        ll c=i%2;
        for(int j=0; j<=500000; j++){
            if(dp[c][j]==-1) continue;
            ll l=j+q, r=abs(j-q);
            dp[c^1][j] = max(dp[c][j], dp[c^1][j]);
            if(l<=500000) dp[c^1][l] = max(dp[c^1][l], dp[c][j]+q);
            if(r<=500000) dp[c^1][r] = max(dp[c^1][r], dp[c][j]+(j<q ? r:0));
        }
    }
    cout << (dp[n%2][0]>0 ? dp[n%2][0] : -1);
}
