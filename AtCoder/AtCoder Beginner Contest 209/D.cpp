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
vector<ll> g[MEM];
ll d[MEM], v[MEM];
void dfs(ll a){
    v[a] = 1;
    for(int i=0; i<g[a].size(); i++){
        ll nx=g[a][i];
        if(!v[nx]){
            d[nx] = d[a]+1;
            dfs(nx);
        }
    }
}
int main(){
    sanic;
    cin >> n >> m;
    for(int i=0; i<n-1; i++){
        ll q1, q2;
        cin >> q1 >> q2;
        g[q1].push_back(q2);
        g[q2].push_back(q1);
    }
    dfs(1);
    while(m--){
        ll q1, q2;
        cin >> q1 >> q2;
        if((d[q1]+d[q2])%2) cout << "Road";
        else cout << "Town";
        cout << '\n';
    }
}
