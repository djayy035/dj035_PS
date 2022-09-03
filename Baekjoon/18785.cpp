#include <bits/stdc++.h>
#define MEM 2525
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz size()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e17;
const ll MOD = 20070713;
ll t,n,m;
ll a[MEM];
vector<ll> g[MEM];
ll sm0, sm1;
void dfs(ll cur, ll p, ll cl){
    if(cl) sm1+=a[cur], m++;
    else sm0+=a[cur];
    for(ll nt:g[cur]){
        if(nt==p) continue;
        dfs(nt, cur, cl^1);
    }
}
signed main(){
    sanic; cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<n; i++){
        ll q1,q2;
        cin >> q1 >> q2;
        g[q1].pb(q2);
        g[q2].pb(q1);
    }
    dfs(1, -1, 0);
    sm0 %= 12;
    sm1 %= 12;
    if(sm0==sm1) cout << n;
    else if((sm0-sm1+12)%12==1) cout << n-m;
    else if((sm0-sm1+12)%12==11) cout << m;
    else cout << 0;
}
