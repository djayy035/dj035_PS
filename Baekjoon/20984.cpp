#include <bits/stdc++.h>
#define MEM 200005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e18+7;
ll t,n,m,ans;
ll a[MEM], ldp[MEM], rdp[MEM];
main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=1; i<n; i++)
        ldp[i] = ldp[i-1]+max(0LL, a[i-1]-a[i]+1);
    for(int i=n-2; i>=0; i--)
        rdp[i] = rdp[i+1]+max(0LL, a[i+1]-a[i]+1);
    ll ans = INF;
    for(int i=0; i<n; i++)
        ans = min(ans, max(ldp[i],rdp[i]));
    cout << ans;
}
