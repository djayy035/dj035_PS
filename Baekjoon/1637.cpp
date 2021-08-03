#include <bits/stdc++.h>
#define MEM 50005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 3e9;
const ll MOD = 1234567891;
ll t,n,m,k,c,ans;
struct p{
    ll x,y,z;
};
p a[MEM];
ll in[MEM], v[MEM];
ll f(ll k){
    if(!k) return 0;
    ll ret=0;
    for(int i=0; i<n; i++){
        ll v=min(a[i].y, k)-a[i].x;
        ret += (v<0 ? 0LL: (v/a[i].z+1));
    }
    return ret;
}
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    ll l=0, r=INF;
    ll ans=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(f(mid)%2){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    if(ans==-1) cout << "NOTHING";
    else cout << ans << ' ' << f(ans)-f(ans-1);
}
