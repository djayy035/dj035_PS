#include <bits/stdc++.h>
#define ll long long
#define MEM 500025
#define x first
#define y second
#define sz size()
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<ll, ll> pi;
const ll INF = 4e18;
const ll MOD = 1e4;
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
ll chk(ll n)
{
    ll o = n, p = 7;
    while (o > 0)
    {
        if (o % 10 <= 7)
            p = min(p, (7LL - o % 10));
        o /= 10;
    }
    return p;
}
ll t, n, m, k, l;
string s;
ll a[MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll ans = 7;
        for (ll i = 0; i < 7; i++)
        {
            if (chk(n) <= i)
                ans = min(ans, i);
            n--;
        }
        cout << ans << '\n';
    }
}
