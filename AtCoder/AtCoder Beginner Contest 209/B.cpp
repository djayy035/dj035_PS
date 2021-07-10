#include <bits/stdc++.h>
#define MEM 106
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 2e18+9;
const ll MOD = 1e9+7;
ll t,n,m,k;
ll a[MEM];
int main(){
    sanic;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i%2) a[i]--;
        m += a[i];
    }
    if(m>k) cout << "No";
    else cout << "Yes";
}
