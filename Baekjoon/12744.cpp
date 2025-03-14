#include <bits/stdc++.h>
#define ll long long
#define MEM 400000
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
ll n,m,ans;
ll chk[MEM][64];
queue<pair<pi, ll>> q;
main()
{
    // cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(0);
    cin >> n;
    ll st=0, st2=0;
    for(int i=0; i<n; i++){
        ll q;
        char q2;
        cin >> q >> q2;
        if(q2=='+') st |= 1<<(q-1);
        st2 *= 6;
        st2 += q-1;
    }
    q.push({{st2, st}, 0});
    chk[st2][st] = 1;
    while(q.sz){
        ll c = q.front().x.x,cc=q.front().x.y,h=q.front().y;
        q.pop();
        vector<ll> v;
        while(c>0) {
            v.pb(c%6);
            c /= 6;
        }
        if(v.sz<n) v.pb(0);
        ll o=1;
        for(int i=0; i<n; i++){
            if(v[i]+i!=n-1){
                o = 0;
                break;
            }
        }
        if(o && cc==(1<<n)-1){
            cout << h;
            return 0;
        }
        for(int i=0; i<n; i++){
            ll nc=0, ncc=cc;
            for(int j=i; j<n; j++) {
                nc *= 6;
                nc += v[j];
                ncc ^= (1<<v[j]);
            }
            for(int j=i-1; j>=0; j--) {
                nc *= 6;
                nc += v[j];
            }
            //cout << nc << ' ' << ncc << '\n';
            if(chk[nc][ncc]) continue;
            chk[nc][ncc] = 1;
            q.push({{nc, ncc}, h+1});
        }
    }
}
