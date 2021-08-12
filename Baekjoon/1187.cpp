#include <bits/stdc++.h>
#define MEM 4005
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
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll n,m,k;
ll a[MEM];
ll dnc(ll l, ll r){
    ll N=(r-l+2)/2;
    if(N<=1) return a[l];
    ll h[3] = {0,};
    for(int i=0; i<3; i++)
        h[i] = dnc(l+i*(N/2), l+i*(N/2)+N-2)/(N/2);
    if(h[0]%2==h[1]%2) return (h[0]+h[1])*(N/2);
    else if(h[0]%2==h[2]%2){
        for(int i=0; i<N/2; i++)
            swap(a[l+i+N/2], a[l+i+N]);
        return (h[0]+h[2])*(N/2);
    }
    else{
        for(int i=0; i<N/2; i++)
            swap(a[l+i], a[l+i+N]);
        return (h[2]+h[1])*(N/2);
    }
}
int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<2*n-1; i++)
        cin >> a[i];
    dnc(0,2*(n-1));
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
}
