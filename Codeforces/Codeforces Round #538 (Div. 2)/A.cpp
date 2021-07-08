#include <bits/stdc++.h>
#define MEM 500005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e9;
const ll MOD = 1e9+7;
ll t,n,m;
ll a,b,c,k;
int main(){
    cin >> n >> m >> k;
    cin >> a >> b >> c;
    ll ans=1;
    if(a<n) ans=0;
    else a -= n;
    if(a+b<m) ans=0;
    else if(a+b-m+c<k) ans=0;
    if(ans) cout << "YES";
    else cout << "NO";
}
