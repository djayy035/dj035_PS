#include <bits/stdc++.h>
#define MEM 500005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e9;
const ll MOD = 1e9+7;
ll t,n,m;
ll a[MEM];
int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n<m) swap(n,m);
        if(n-m==0){
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }
        cout << n-m <<  ' ' << min(m, min(m%(n-m), n-m-(m%(n-m)))) << '\n';
    }
}
