#include <bits/stdc++.h>
#define MEM 200006
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll t,n,m;
ll a[MEM], b[MEM];
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            a[i] += a[i-1];
        }
        for(int i=1; i<=n; i++){
            cin >> b[i];
            b[i] += b[i-1];
        }
        ll ans=INF;
        for(int i=1; i<=n; i++)
            ans = min(ans, max(a[n]-a[i], b[i-1]));
        cout << ans << '\n';
    }
}
