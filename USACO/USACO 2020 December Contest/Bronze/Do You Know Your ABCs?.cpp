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
    for(int i=0; i<7; i++)
        cin >> a[i];
    sort(a,a+7);
    cout << a[0] << ' ' << a[1] << ' ' << a[6]-a[1]-a[0];
}
