#include <bits/stdc++.h>
#define MEM 100005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 2e18+9;
const ll MOD = 1e9+7;
ll t,n,m,k;
ll a[MEM], c[MEM];
string s[MEM];
map<string, ll> p;
int main(){
    sanic;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> s[i];
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<m; i++){
        ll o;
        cin >> o;
        c[i] = INF;
        vector<ll> h;
        for(int j=0; j<o; j++){
            ll q;
            cin >> q;
            h.push_back(q);
            c[i] = min(c[i], a[q-1]);
        }
        for(int j=0; j<h.size(); j++)
            p[s[h[j]-1]] = c[i];
    }
    ll ans=0;
    for(int i=0; i<k; i++){
        string q;
        cin >> q;
        ans += p[q];
    }
    cout << ans;
}
