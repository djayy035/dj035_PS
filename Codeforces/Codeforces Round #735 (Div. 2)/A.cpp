#include <bits/stdc++.h>
#define MEM 200006
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<double, double> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll t,n,m,k,c,ans;
ll a[MEM];
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll mx=0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(a[i]>mx)
                mx = a[i];
        }
        ans = 0;
        for(int i=2; i<=n; i++)
            ans = max(ans, a[i]*a[i-1]);
        cout << ans << '\n';
    }
}


