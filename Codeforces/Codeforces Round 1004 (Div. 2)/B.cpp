#include <bits/stdc++.h>
#define ll long long
#define MEM 5025
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
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            a[m]++;
        }
        l = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!a[i])
                continue;
            if (a[i] < 2)
            {
                l = 0;
                break;
            }
            if (a[i] == n)
            {
                if (a[i] % 2)
                    l = 0;
                break;
            }
            a[i + 1] += a[i] - 2;
            a[i] = 2;
        }
        if (l)
            cout << "Yes";
        else
            cout << "No";
        cout << '\n';
    }
}
