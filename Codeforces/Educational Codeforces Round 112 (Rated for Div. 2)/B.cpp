#include <bits/stdc++.h>
#define MEM 1006
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef double ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll t,n,m;
ll a,b,c,d,k,l;
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    cout.precision(10);
    cout << fixed;
    while(t--){
        cin >> n >> m;
        cin >> a >> b >> c >> d;
        cin >> k >> l;
        ll ans=INF;
        if(k<=a || l<=b) ans=0;
        ll dx=abs(k-a), dy=abs(l-b);
        if(c+dx<=n) ans = min(dx,ans);
        if(d+dy<=m) ans = min(dy,ans);
        if(n-k>=c || l<=b) ans=0;
        dx=abs(n-k-c), dy=abs(l-b);
        if(a-dx>=0) ans = min(dx,ans);
        if(d+dy<=m) ans = min(dy,ans);
        if(n-k>=c || m-l>=d) ans=0;
        dx=abs(n-k-c), dy=abs(m-l-d);
        if(a-dx>=0) ans = min(dx,ans);
        if(b-dy>=0) ans = min(dy,ans);
        if(k<=a || m-l>=d) ans=0;
        dx=abs(k-a), dy=abs(m-l-d);
        if(c+dx<=n) ans = min(dx,ans);
        if(b-dy>=0) ans = min(dy,ans);
        cout.precision(10);
        cout << fixed;
        if(ans!=INF) cout << ans;
        else cout << -1;
        cout << '\n';
    }
}
