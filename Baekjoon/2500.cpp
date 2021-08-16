#include <bits/stdc++.h>
#define MEM 1005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
const ll MOD = 42043;
ll t,n,m,k;
vector<ll> mul(vector<ll> &a, vector<ll> &b){
    vector<ll> ret;
    for(int i=0; i<min((ll)a.size(), k+3); i++)
        for(int j=0; j<min((ll)b.size(), k+3); j++){
            while(ret.size()<=i+j) ret.pb(0);
            a[i] = (a[i]%MOD+MOD)%MOD;
            b[j] = (b[j]%MOD+MOD)%MOD;
            ret[i+j] = (ret[i+j]+((a[i]*b[j])%MOD+MOD)%MOD+MOD)%MOD;
        }
    return ret;
}
vector<ll> power(vector<ll> &x, ll y) {
    vector<ll> ret={1LL};
    while(y>0) {
        if(y%2) ret = mul(ret,x);
        x = mul(x,x);
        y /= 2;
    }
    return ret;
}

int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    vector<ll> a(k+2);
    for(int i=0; i<m; i++){
        ll q;
        cin >> q;
        if(q<=k) a[q]++;
    }
    vector<ll> ans = power(a, n);
    ll p=0;
    //for(int i=0; i<=k; i++)
        //cout << ans[i] << ' ';
    for(int i=0; i<=k; i++)
        p = ((p+ans[i])%MOD+MOD)%MOD;
    cout << p;
}
