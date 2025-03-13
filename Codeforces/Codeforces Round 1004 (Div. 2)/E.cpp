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
ll a[MEM], l[MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll m=a[0], c=0;
        vector<ll> v;
        for(int i=0; i<=n; i++) l[i] = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(!a[i]){
                if(!c) v.pb(a[i]);
                c++;
                l[0] = 1;
                continue;
            } 
            a[i] = min(a[i], n+1);
            v.pb(a[i]);
            l[a[i]]++;
        }
        if(!c){
            cout << n << '\n';
            continue;
        }
        ll o=1, mx = 0;
        for(int i=0; i<=n; i++){
            if(!l[i]){
                mx = i;
                break;
            }
        }
        m = v[0];
        for(int i=0; i<v.sz; i++){
            m = min(v[i], m);
            l[v[i]]--;
            if(!l[v[i]]){
                if(mx>v[i]) mx = v[i];
            }
            if(m<mx) {
                o = 0;
                break;
            }
        }
        cout << n-c+o << '\n';
    }
}
