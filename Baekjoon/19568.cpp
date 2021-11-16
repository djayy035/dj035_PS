#include <bits/stdc++.h>
#define MEM 2000005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll t,n,m,k;
ll ans;
signed a[MEM];
string s;
signed main()
{
    sanic; cin.tie(0); cout.tie(0);
    for(int i=0; i<30; i++){
        for(int j=0; j<30; j++){
            if(i==15 && j<15) cout << 1;
            else if(i==15 && j>15) cout << 15;
            else if(j==15 && i<15) cout << 225;
            else if(j==15 && i>15) cout << 3375;
            else cout << 0;
            cout << ' ';
        }
        cout << '\n';
    }
}
