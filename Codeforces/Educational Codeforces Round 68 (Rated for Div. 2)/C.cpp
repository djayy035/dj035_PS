#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define MEM 55555
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz size()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll MOD = 1e9+7;
const ll INF = 2e18+7;
ll mul(ll a, ll b){
    return ((a*b)%MOD+MOD)%MOD;
}
ll add(ll a, ll b){
    return ((a+b)%MOD+MOD)%MOD;
}
bool cp(pi a, pi b){
    return a.x*b.y<b.x*a.y;
}
ll t,n,m;
ll a[27], b[27], c[27];
string s,p,ss;
signed main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s >> ss >> p;
        ll ans=1;
        for(int i=0; i<26; i++){
            a[i]=0;
            b[i]=0;
            c[i]=0;
        }
        for(int i=0; i<s.sz; i++)
            a[s[i]-'a']++;
        for(int i=0; i<ss.sz; i++)
            b[ss[i]-'a']++;
        for(int i=0; i<p.sz; i++)
            c[p[i]-'a']++;
        ll pp=INF;
        for(int i=0; i<26; i++)
            pp = min(pp, a[i]+c[i]-b[i]);
        //cout << pp << '\n';
        if(pp<0) ans = 0;
        ll j=0;
        for(int i=0; i<ss.sz; i++){
            if(j>=s.sz || s[j]!=ss[i]){
                if(c[ss[i]-'a']<=0) {
                    ans = 0;
                    break;
                }
                c[ss[i]-'a']--;
            }
            else j++;
        }
        if(j<s.sz) ans = 0;
        if(!ans)cout << "NO\n";
        else cout << "YES\n";
    }
}
