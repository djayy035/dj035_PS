#include <bits/stdc++.h>
#define ll long long
#define MEM 100300
#define x first
#define y second
#define sz size()
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<ll, ll> pi;
const ll INF = 4e18;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
ll abs(ll a, ll b)
{
    return (a > b ? a - b : b - a);
}
ll add(ll a, ll b)
{
    return ((a + b) % MOD + MOD) % MOD;
}
ll sub(ll a, ll b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
ll mul(ll a, ll b)
{
    return ((a * b) % MOD + MOD) % MOD;
}
ll n,m,ans;
ll a[MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    ll mx=0, mn=INF, h=0, hh = 0,hhh = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i>0 && i<n-1) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        h += a[i];
        
    }
    hh = h - a[n-1];
    hhh = h - a[0];
    ans = h - a[0] - a[n-1] + mx;
    for(int i=1; i<n-1; i++){
        hhh -= a[i];
        ans = max(ans, h-a[0]-a[i]+hhh);
    }
    for(int i=n-2; i>0; i--){
        hh -= a[i];
        ans = max(ans, h-a[n-1]-a[i]+hh);
    }
    cout << ans;
}
