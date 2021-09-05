#include <bits/stdc++.h>
#define MEM 1111
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
ll dp[MEM][MEM];
string c,d;
main()
{
    sanic;
    cin >> c >> d;
    for(int i=0; i<c.size(); i++){
        for(int j=0; j<d.size(); j++){
            if(c[i]==d[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout << dp[c.size()][d.size()];
}
