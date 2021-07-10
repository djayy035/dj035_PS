#include <bits/stdc++.h>
#define MEM 56
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 2e18+9;
const ll MOD = 1e9+7;
ll t,n,m,k;
ll a[MEM], dp[MEM];
int main(){
    sanic;
    cin >> n;
    for(int i=1; i<50; i++)
        dp[i] = 2LL*dp[i-1]+(1LL<<(i-1));
    n--;
    ll ans=0;
    for(int i=50; i>=0; i--)
        if(n>=(1LL<<i)){
            ans += dp[i]+(1LL<<i);
            n -= (1LL<<i);
        }
    cout << ans;
}
