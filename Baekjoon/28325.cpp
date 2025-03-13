#include <bits/stdc++.h>
#define ll long long
#define MEM 2500005
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
ll t,n,k,o;
ll a[MEM];
ll dp[MEM][2][2];
ll DP(ll x, ll y, ll z){
    if(x==1){
        if(z==1) return 1;
        else return a[1];
    }
    ll &ret = dp[x][y][z];
    if(ret!=-1) return ret;
    if(x==2) {
        if(y==1 && z==1) return ret = -INF;
        else if(y==1) ret = max(ret, DP(1,z,z)+1);
        else ret = max(ret, DP(1,z,z)+a[x]);
    }
    else{
        if(y==1) ret = max(ret, DP(x-1, 0, z)+1);
        else ret = max(ret, max(DP(x-1, 0, z), DP(x-1, 1, z))+a[x]);
    }
    return ret;
}
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << max(DP(n,1,0), max(DP(n,0,1), DP(n,0,0)));
}
