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
    sanic; cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >>a[i];
        sort(a,a+n);
        ll ans=0;
        for(int i=0; i<n; i++)
            if(a[0]==a[i])
                ans++;
        cout << n-ans << '\n';
    }
}
