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
ll t,n,ans;
ll a[MEM], b[MEM];
vector<ll> g[MEM];
priority_queue<pi> pq;
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=2; i<=n; i++){
        ll q;
        cin >> q;
        g[q].pb(i);
    }
    for(int i=1; i<=n; i++) cin >> a[i];
    pq.push({-a[1], 1});
    while(!pq.empty()){
        ll cx = pq.top().x, cy = pq.top().y;
        pq.pop();
        cout << -cx << '\n';
        for(ll o : g[cy]) pq.push({-a[o], o});
    }
}
