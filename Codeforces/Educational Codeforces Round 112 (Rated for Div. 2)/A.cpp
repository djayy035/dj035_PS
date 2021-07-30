#include <bits/stdc++.h>
#define MEM 1006
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll t,n,m,k,c,ans;
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cout << max(15LL, ((n+1)/2LL)*5LL) << '\n';
    }
}
