#include <bits/stdc++.h>
#define MEM 200005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll t,n,m,k;
ll a[MEM];
main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll ans=0;
        for(ll i=1; (i*i+1)/2<=n; i+=2){
            ll a=i, b=(i*i-1)/2, c=(i*i+1)/2;
            if(1<=a && a<=b && c<=n) ans++;
            //cout << a << ' ' << b << ' ' << c << '\n';
        }
        cout << ans << '\n';
    }
}
