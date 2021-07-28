#include <bits/stdc++.h>
#define MEM 63
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<double, double> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll pw(ll a, ll b){
    ll ret = 1LL;
    while(b>0){
        if(b%2) ret *= a;
        a *= a;
        b /= 2LL;
    }
    return ret;
}
ll limf(ll k){
    ll l=2, r=(1LL<<45);
    while(l<=r){
        ll mid = (l+r)/2LL;
        if(k*log(mid)+1e-9>log((1LL<<63)-1)) r = mid-1;
        else l = mid+1;
    }
    return r;
}
ll f(ll a, ll b, ll lim){
    ll l=0, r=lim;
    while(l<=r){
        ll mid = (l+r)/2LL;
        if(pw(mid, b)>=a) r = mid-1;
        else l = mid+1;
    }
    return l;
}
unordered_map<ll, ll> dp;
ll a[MEM];
ll DP(ll n){
    if(n==1) return 0;
    ll& ret = dp[n];
    if(ret) return ret;
    ret = n-1;
    for(ll i=61; i>=2; i--){
        ll r = f(n, i, a[i]);
        ll l = r-1;
        if(1<r) ret = min(ret, DP(r)+abs(n-pw(r,i))+1);
        if(1<l) ret = min(ret, DP(l)+abs(n-pw(l,i))+1);
    }
    return ret;
}
ll n,m,k,c,ans;
main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i=2; i<62; i++)
        a[i] = limf(i);
    cout << DP(n);
}

