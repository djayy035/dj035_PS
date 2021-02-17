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
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    ll ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            ll s=0;
            for(int k=j; k<=i; k++)
                s += a[k];
            ll p=0;
            for(int k=j; k<=i; k++)
                if(a[k]*(i-j+1)==s) p=1;
            ans += p;
        }
    }
    cout << ans;
}
