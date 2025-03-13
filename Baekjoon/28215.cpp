#include <bits/stdc++.h>
#define ll long long
#define MEM 70
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
ll t,n,k,o,q,ans;
ll a[MEM], b[MEM];
ll c[MEM][MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i];
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            c[i][j] = c[j][i] = abs(a[i]-a[j])+abs(b[i]-b[j]);
    ans = INF;
    if(k==1){
        for(int i=1; i<=n; i++){
            o = 0;
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                o = max(o, c[i][j]);
            }
            ans = min(o, ans);
        }
    }
    else if(k==2){
        for(int i=1; i<=n; i++){
            for(int l=i+1; l<=n; l++){
                o = 0;
                for(int j=1; j<=n; j++){
                    if(i==j || i==l) continue;
                    o = max(o, min(c[i][j], c[j][l]));
                }
                ans = min(o, ans);
            }
        }
    }
    else{
        for(int i=1; i<=n; i++){
            for(int l=i+1; l<=n; l++){
                for(int u=l+1; u<=n; u++){
                    o = 0;
                    for(int j=1; j<=n; j++){
                        if(i==j || i==l || i==u) continue;
                        o = max(o, min(c[i][j], min(c[j][l], c[j][u])));
                    }
                    ans = min(o, ans);
                }
            }
        }
    }
    cout << ans;
}
