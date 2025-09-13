#include <bits/stdc++.h>
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll MEM = 3010;
const ll MOD = 1000000007;
const ll INF = 9e17;
ll gcd(ll a, ll b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
pi a[MEM];
ll u[MEM][MEM], d[MEM][MEM];
ll t, n, m, k;
int main()
{
    sanic;
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);
    ll ans = 1 + n;
    for (int i = 1; i <= n; i++)
    {
        ll yy = a[i].y;
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = d[i][j - 1];
            u[i][j] = u[i][j - 1];
            if (i == j)
                continue;
            if (yy > a[j].y)
                d[i][j]++;
            else
                u[i][j]++;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i].y < a[j].y)
                ans += (d[i][j] - d[i][i - 1] + 1) * (u[j][j] - u[j][i - 1] + 1);
            else
                ans += (u[i][j] - u[i][i - 1] + 1) * (d[j][j] - d[j][i - 1] + 1);
        }
    cout << ans;
}
