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
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        ll s=accumulate(a,a+n,0LL);
        cout << (s%n)*(n-(s%n)) << '\n';
    }
}
