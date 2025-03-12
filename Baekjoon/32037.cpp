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
ll t,n,k,o=1;
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        string s;
        cin >> n >> s;
        ll o0 = 0, o1 = 0;
        if(s[0]=='0') o0++;
        else o1++;
        for(int i=1; i<n; i++){
            if(s[i-1]=='0' && s[i]=='1') o1++;
            else if(s[i-1]=='1' && s[i]=='0') o0++;
        }
        if(s[0]=='0' && o0==1){
            if(!o1) cout << 0;
            else{
                for(int i=0; i<n; i++){
                    if(s[i]=='0') continue;
                    cout << 1;
                }
            }
            cout << '\n';
            continue;
        }
        if(s[0]=='1' && !o0){
            for(int i=0; i<n-1; i++) cout<<1;
            cout<<0<<'\n';
            continue;
        }
        o0 = 0, o1 = 0;
        ll u=0,l=INF,y=0;
        if(s[0]=='0') o0++;
        else o1++, y++;
        for(int i=1; i<n; i++){
            if(s[i-1]=='0' && s[i]=='1') o1++;
            else if(s[i-1]=='1' && s[i]=='0') o0++;
            if(o1==1 && s[i]=='0') u++, l = min((ll)i, l);
            if(o1==1 && s[i]=='1') y++;
        }
        //
        u = min(u,y);
        //cout << l << ' ' << u << '\n';
        for(int i=0; i<n; i++){
            if(i<l) {
                if(s[i]=='1') cout << s[i];
                continue;
            }
            if(s[i]==s[i-u]) cout << 0;
            else cout << 1;
        }
        cout<< '\n';
    }
}
