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
    cin >> n >> m;
    ll ans=1,p,o=0;
    if(m%n) ans=0;
    else p=m/n;
    while(!(p%2) || !(p%3)){
        if(!(p%2)) p /= 2;
        else if(!(p%3)) p /= 3;
        o++;
    }
    if(p>1) ans=0;
    if(ans) cout << o;
    else cout << -1;
}
