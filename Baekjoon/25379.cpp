#include <bits/stdc++.h>
#define ll long long
#define MEM 1000005
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
ll n,k,p,ans1,ans2;
ll a[MEM], b[MEM], c[MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        a[i] %= 2;
    }
    if(a[0]) b[0]++;
    else c[0]++;
    for(int i=1; i<n; i++){
        b[i] = b[i-1] + a[i];
        c[i] = c[i-1] + 1-a[i];
    }
    for(int i=1; i<n; i++){
        if(a[i]) ans1 += c[i];
        else ans2 += b[i]; 
    }
    cout << min(ans1, ans2);
}
