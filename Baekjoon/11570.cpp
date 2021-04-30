#include <bits/stdc++.h>
#define MEM 2005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll n, dp[MEM][MEM];
ll a[MEM];
ll ans=INF;
int main()
{
    //sanic; cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = INF;
    dp[1][0] = 0;
    dp[0][1] = 0;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++){
            if(i==j) continue;
            ll nx=max(i,j)+1;
            if(i==0 || j==0) a[0] = a[nx];
            dp[i][nx] = min(dp[i][nx], dp[i][j]+abs(a[nx]-a[j]));
            dp[nx][j] = min(dp[nx][j], dp[i][j]+abs(a[nx]-a[i]));
        }
    for(int i=0; i<=n; i++)
        ans = min({ans, dp[i][n], dp[n][i]});
    cout << ans;
}
