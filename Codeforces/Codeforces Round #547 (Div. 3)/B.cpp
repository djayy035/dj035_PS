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
ll a[MEM],p[MEM];
string s;
main(){
    sanic; cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    ll ans=0,c=0;
    for(int i=0; i<2*n; i++){
        if(a[i%n]) c++;
        else{
            ans = max(ans,c);
            c=0;
        }
    }
    cout << ans;
}
