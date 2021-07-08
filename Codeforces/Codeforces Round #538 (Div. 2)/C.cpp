#include <bits/stdc++.h>
#define MEM 500005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 2e18+9;
const ll MOD = 1e9+7;
ll calc(ll n, ll m){
    ll ans=0;
    ll p=n;
    while(p>0){
        p /= m;
        ans += p;
    }
    return ans;
}
ll t,n,m,k;
pi a[MEM];
vector<pi> fc;
int main(){
    cin >> n >> m;
    k = m;
    ll o=0;
    for(ll i=2LL; i*i<=m; i++){
        ll ct=0;
        while(!(k%i)){
            k /= i;
            ct++;
        }
        if(ct) fc.push_back({i,ct});
    }
    if(k>1) fc.push_back({k,1});
    ll res=INF;
    for(int i=0; i<fc.size(); i++){
        //cout << fc[i].x << ' ' << fc[i].y << '\n';
        res = min(calc(n,fc[i].x)/fc[i].y, res);
    }
    cout << res;
}
