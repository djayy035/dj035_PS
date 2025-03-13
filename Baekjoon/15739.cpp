#include <bits/stdc++.h>
#define ll long long
#define MEM 300
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
ll t,n,ans;
ll a[MEM*MEM], b[MEM], c[MEM][MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    ans = 1;
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c[i][j];
            a[c[i][j]]++;
        }
    }
    for(int i=1; i<=n*n; i++) if(a[i]!=1) ans = 0;
    for (int i=0; i<n; i++){
        ll o =0;
        for(int j=0; j<n; j++) o += c[i][j];
        if(o!=n*(n*n+1)/2) ans = 0;
    }
    for (int i=0; i<n; i++){
        ll o =0;
        for(int j=0; j<n; j++) o += c[j][i];
        if(o!=n*(n*n+1)/2) ans = 0;
    }
    ll o =0;
    for(int i=0; i<n; i++) o += c[i][i];
    if(o!=n*(n*n+1)/2) ans = 0;
    o = 0;
    for(int i=0; i<n; i++) o += c[i][n-1-i];
    if(o!=n*(n*n+1)/2) ans = 0;
    cout << (ans ? "TRUE":"FALSE");
}
