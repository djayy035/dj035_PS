#include <bits/stdc++.h>
#define sanic ios_base::sync_with_stdio(0);
#define MEM 500005
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll MOD = 1e9+7;
const ll INF = 1e13;
ll n,m,p,ans,t;
ll a[MEM];
vector<ll> v[MEM];
ll turn(){
    ll b=0;
    for(int i=1; i<=n; i++){
        if(a[i]) continue;
        ll c=0;
        for(int j=0; j<v[i].size(); j++)
            c += (!a[v[i][j]]);
        if(c>1) {
            b = 1;
            a[i] ^= 1;
        }
    }
    for(int i=1; i<=n; i++){
        if(!a[i]) continue;
        ll c=0;
        for(int j=0; j<v[i].size(); j++)
            c += (a[v[i][j]]);
        if(c>1) {
            b = 1;
            a[i] ^= 1;
        }
    }
    return b;
}
int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> m;
        for(int j=0; j<m; j++){
            ll q;
            cin >> q;
            v[i].push_back(q);
        }
    }

    while(1){
        if(!turn()) break;
    }
    vector<ll> ans1,ans2;
    for(int i=1; i<=n; i++){
        if(a[i]) ans2.push_back(i);
        else ans1.push_back(i);
    }
    cout << ans1.size() << ' ';
    for(int i=0; i<ans1.size(); i++)
        cout << ans1[i] << ' ';
    cout << '\n';
    cout << ans2.size() << ' ';
    for(int i=0; i<ans2.size(); i++)
        cout << ans2[i] << ' ';
}
