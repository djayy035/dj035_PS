#include <bits/stdc++.h>
#define MEM 200005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll n,m,k;
string s,t;
ll a[MEM], cnt[3];
ll ans;
main(){
    //sanic; cin.tie(0);
    cin >> s;
    ll k=0;
    cnt[0] = 1;
    for(int i=0; i<s.size(); i++)
        a[i] = s[i]-'0';
    ll h=0;
    for(int i=0; i<s.size(); i++){
        h = (h+a[i])%3;
        if(cnt[h]) h = cnt[1] = cnt[2] = 0, ans++;
        else cnt[h] = 1;
    }
 
    cout << ans;
}
