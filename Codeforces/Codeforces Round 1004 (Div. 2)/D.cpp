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
ll a[MEM], b[MEM];
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll mx=0, mn=INF;
        for(int i=1; i<=n; i++) b[i] = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i]<mn) mn = a[i], k = i+1;
            if(a[i]>mx) mx = a[i], l = i+1;
            b[a[i]]++;
        }
        if(mx-mn==n-1){
            cout << "? " << k << ' ' << l << endl;
            cin >> m;
            if(m>n-1) cout << "! B" << endl;
            else if(m<n-1) cout << "! A" << endl;
            else{
                cout << "? " << l << ' ' << k << endl;
                cin >> m;
                if(m==n-1) cout << "! B" << endl;
                else cout << "! A" << endl;
            }
        }
        else{
            for(int i=1; i<=n; i++){
                if(b[i]) continue;
                cout << "? " << i << ' ' << (i==1 ? 2:1) << endl;
                cin >> m;
                if(!m) cout << "! A" << endl;
                else cout << "! B" << endl;
                break;
            }
        }
    }
}
