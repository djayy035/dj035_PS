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
ll a[MEM];
vector<ll> ans;
main(){
    //sanic; cin.tie(0);
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    ll k=0;
    for(int i=0; i<min(s.size(), t.size()); i++){
        if(s[i]!=t[i]) break;
        k++;
    }
    cout << s.size()+t.size()-2*k;
}
