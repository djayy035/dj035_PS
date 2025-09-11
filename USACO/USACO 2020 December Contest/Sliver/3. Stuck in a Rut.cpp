#include <bits/stdc++.h>
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll MEM = 1010;
const ll MOD = 1000000007;
const ll INF = 9e17;
ll gcd(ll a, ll b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
ll a[MEM], b[MEM], p[MEM], chk[MEM], ans[MEM], pr[MEM];
vector<ll> g[MEM];
ll t, n, m, k;
ll dfs(ll c, ll pp)
{
    ans[c] = 0;
    for (ll nt : g[c])
    {
        if (nt == pp)
            continue;
        ans[c] += dfs(nt, c) + 1;
    }
    return ans[c];
}
int main()
{
    sanic;
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<pair<pi, ll>> nn, ee;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c >> a[i] >> b[i];
        if (c == 'N')
        {
            p[i] = 1;
            nn.push_back({{a[i], b[i]}, i});
        }
        else
        {
            p[i] = 2;
            ee.push_back({{b[i], a[i]}, i});
        }
        pr[i] = -1;
    }
    sort(all(nn));
    sort(all(ee));
    for (int i = 0; i < nn.size(); i++)
    {
        for (int j = 0; j < ee.size(); j++)
        {
            pi nj = nn[i].x, ej = {ee[j].x.y, ee[j].x.x};
            ll xs = nj.x - ej.x, ys = ej.y - nj.y, nnu = nn[i].y, enu = ee[j].y;
            if (chk[enu])
                continue;
            if (xs < 0 || ys < 0)
                continue;
            if (xs == ys)
                continue;
            else if (xs > ys)
            {
                pr[enu] = nnu;
                g[nnu].push_back(enu);
                g[enu].push_back(nnu);
                chk[enu] = 1;
            }
            else
            {
                pr[nnu] = enu;
                g[nnu].push_back(enu);
                g[enu].push_back(nnu);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (pr[i] != -1)
            continue;
        dfs(i, -1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
