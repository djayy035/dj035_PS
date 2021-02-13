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
vector<pi> ans;
vector<ll> a[28],b[28],aa,bb;
main(){
    //sanic; cin.tie(0);
    cin >> n;
    cin >> s >> t;
    for(int i=0; i<n; i++){
        if(s[i]=='?')
            a[26].push_back(i);
        else
            a[s[i]-'a'].push_back(i);
    }
    for(int i=0; i<n; i++){
        if(t[i]=='?')
            b[26].push_back(i);
        else
            b[t[i]-'a'].push_back(i);
    }
    for(int i=0; i<26; i++){
        ll ct=min(a[i].size(), b[i].size());
        for(int j=0; j<ct; j++)
            ans.push_back({a[i][j], b[i][j]});
        for(int j=ct; j<a[i].size(); j++)
            aa.push_back(a[i][j]);
        for(int j=ct; j<b[i].size(); j++)
            bb.push_back(b[i][j]);
    }
    ll ct=min(aa.size(), b[26].size());
    for(int j=0; j<ct; j++)
        ans.push_back({aa[j], b[26][j]});
    ll cf=min(bb.size(), a[26].size());
    for(int j=0; j<cf; j++)
        ans.push_back({a[26][j], bb[j]});
    ct = b[26].size()-ct;
    cf = a[26].size()-cf;
	ll h=min(ct,cf);
	for(int j=a[26].size()-1; j>=0 && h>0; j--, h--)
        ans.push_back({a[26][j], b[26][j]});
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans[i].x+1 << ' ' << ans[i].y+1 << '\n';
}
