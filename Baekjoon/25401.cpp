#include <bits/stdc++.h>
#define ll long long
#define MEM 700
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
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    ll ans = INF;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((a[j]-a[i])%(j-i)) continue;
            ll d = (a[j]-a[i])/(j-i), cnt=0;
            for(int k=j; k>=0; k--) b[k] = a[j]-(j-k)*d;
            for(int k=j; k<n; k++) b[k] = a[j]+(k-j)*d;
            for(int k=0; k<n; k++) if(a[k]!=b[k]) cnt++;
            ans = min(ans, cnt);
        }
    }
    cout << ans;
}
