#include <bits/stdc++.h>
#define MEM 5005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef int ll;
typedef pair<ll, ll> pi;
const ll INF = 1e9+9;
const ll MOD = 1e9+7;
ll t,n,m,k;
ll a[MEM], dp[MEM][MEM][2];
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j][0] = dp[i][j][1] = (i==j ? 0:INF);
    for(int r=0; r<n; r++)
        for(int l=r; l>=0; l--)
            for(int b=0; b<2; b++){
                ll cur = (b ? a[r] : a[l]);
                if(l) dp[l-1][r][0] = min(dp[l-1][r][0], dp[l][r][b]+(cur!=a[l-1]));
                if(r+1<n) dp[l][r+1][1] = min(dp[l][r+1][1], dp[l][r][b]+(cur!=a[r+1]));
            }

    cout << min(dp[0][n-1][0],dp[0][n-1][1]);
}
