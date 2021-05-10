#include <bits/stdc++.h>
#define MEM 100005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e9+7;
ll t,n,m,ans[MEM];
ll u[MEM], d[MEM], v[MEM];
main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        ll p,q;
        cin >> p >> q;
        u[p]++;
        d[q]++;
    }
    for(int i=1; i<=n; i++){
        ll c=i+u[i]-d[i];
        if(v[c]){
            cout << -1;
            return 0;
        }
        ans[i] = c;
        v[c] = 1;
    }
    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';

}
