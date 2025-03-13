#include <bits/stdc++.h>
#define ll long long
#define MEM 400000
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
ll t,n,ans,m, tt;
ll a[MEM], b[MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m ;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    ans = INF;
    for(int i=0; i<n-1; i++){
        ll o=a[0]*(i+1)+a[i+1]*(n-i-1);
        ans = min(ans, (m+o-1)/o);
    }
    cout << ans;
}
