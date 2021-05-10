#include <bits/stdc++.h>
#define MEM 300005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e9+7;
ll t,n,m,ans;
ll a[MEM];
main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    while(t--){
        ll q1,q2;
        cin >> q1 >> q2;
        if(m==1) {
            cout << abs(q1-q2) << '\n';
            continue;
        }
        ans = 0;
        while(q1!=q2){
            if(q1>q2){
                q1 = (q1+m-2)/m;
                ans++;
            }
            else{
                q2 = (q2+m-2)/m;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}

