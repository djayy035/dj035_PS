#include <bits/stdc++.h>
#define MEM 100005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 2e18+9;
const ll MOD = 1e9+7;
ll t,n,m,k;
ll a[MEM], c[MEM];
string s[MEM];
map<string, ll> p;
int main(){
    sanic;
    cin >> n;
    if(n<=5) cout << -1 << '\n';
    else{
        cout << "1 2\n1 3\n1 4\n";
        for(int i=5; i<=n; i++)
            cout << 2 << ' ' << i << '\n';
    }
    for(int i=1; i<n; i++)
        cout << 1 << ' ' << i+1 << '\n';
}
