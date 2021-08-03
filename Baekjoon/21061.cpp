#include <bits/stdc++.h>
#define MEM 1000220
#define sanic ios_base::sync_with_stdio(0)
using namespace std;
typedef long long ll;
const ll MOD = 1e9+9;
const ll INF = 1e9;
ll n,m;
string b;
ll a[MEM];
int main() {
    sanic; cin.tie(0);
    cin >> n;
    if(n%4==2 || n%4==3){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    ll d=n-1, c=n-1;
    m = -1;
    for(int i=0; i<n; i++)
        a[i] = -1;
    while(d){
        if(d==n/2) d--;
        a[c] = c+d*m;
        c += d*m;
        m *= -1;
        d--;
    }
    a[c] = n-1;
    for(int i=0; i<n; i++){
        if(a[i]==-1) cout << i << ' ';
        else cout << a[i] << ' ';
    }
}
