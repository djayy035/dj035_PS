#include <bits/stdc++.h>
#define MEM 300005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e9+7;
ll t,n,m,ans=1;
ll a[MEM];
main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    ll cur=1;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=1; i<n; i++){
        if(a[i]>a[i-1] && !cur) ans++, cur ^= 1;
        else if(a[i]<a[i-1] && cur) ans++, cur ^= 1;
    }
    cout << (ll)ceil(log2(ans));
}
