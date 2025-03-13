#include <bits/stdc++.h>
#define ll long long
#define MEM 300100
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
ll a[MEM], b[MEM];
ll c[MEM], ldp[MEM], rdp[MEM], dp[MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    c[0] = 1;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
        c[i] = add(c[a[i]],c[b[i]]);
    }
    ldp[0] = 1, rdp[0] = 1, dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = add(sub(add(mul(ldp[a[i]], c[b[i]]),mul(rdp[b[i]], c[a[i]])),1),add(dp[a[i]], dp[b[i]]));
        ldp[i] = add(ldp[a[i]], add(ldp[b[i]], sub(c[a[i]],1)));
        rdp[i] = add(rdp[a[i]], add(rdp[b[i]], sub(c[b[i]],1)));
        cout << dp[i] << '\n';
    }
}
