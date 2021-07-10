#include <bits/stdc++.h>
#define MEM 200005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 2e18+9;
const ll MOD = 1e9+7;
ll t,n,m,k;
ll a[MEM];
int main(){
    sanic;
    cin >> n;
    ll ans=1LL;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a,a+n);
    for(ll i=0LL; i<n; i++){
        ans *= (a[i]-i)*1LL;
        ans += MOD;
        ans %= MOD;
        //cout << ans << '\n';
    }
    cout << (ans+MOD)%MOD;
}
