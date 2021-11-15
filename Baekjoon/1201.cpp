#include <bits/stdc++.h>
#define MEM 500005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13;
const ll MOD = 1000;
ll a[MEM];
ll t,n,m,k;
int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    if(n+1<m+k || n>m*k) {
        cout << -1;
        return 0;
    }
    for(int i=1; i<=n; i++)
        a[i] = i;
    ll s=1;
    for(int i=1; i<=m; i++){
        ll e=min(s+k, n-m+i+1);
        reverse(a+s,a+e);
        s = e;
    }
    for(int i=1; i<=n; i++)
        cout << a[i] << ' ';
}
