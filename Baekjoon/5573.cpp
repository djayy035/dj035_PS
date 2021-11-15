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
const ll INF = 1e13;
const ll MOD = 1000;
ll a[MEM][MEM], dp[MEM][MEM];
ll t,n,m,k;
int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];
    dp[0][0] = k-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j+1] += dp[i][j]/2+((dp[i][j]%2)&a[i][j]);
            dp[i+1][j] += dp[i][j]/2+((dp[i][j]%2)&!a[i][j]);
        }
    }
    ll x=0,y=0;
    while(x<n && y<m){
        if((dp[x][y]%2)^a[x][y]) y++;
        else x++;
    }
    cout << x+1 << ' ' << y+1 << '\n';
}
