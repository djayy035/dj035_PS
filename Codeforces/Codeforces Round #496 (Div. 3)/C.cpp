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
ll n,m,k;
string s,t;
ll a[MEM];
ll ans;
main(){
    //sanic; cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    ll k=a[n];
    for(int i=1; i<=n; i++){
        ll b=0;
        for(ll j=1; j<=k*2; j*=2){
            if(j<a[i]) continue;
            if(a[i]==j-a[i] && (a[i-1]!=a[i] && a[i+1]!=a[i])) continue;
            if(binary_search(a+1,a+n+1,j-a[i])) b=1;
        }
        if(!b) ans++;
    }
    cout << ans;
}
