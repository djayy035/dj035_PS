#include <bits/stdc++.h>
#define MEM 200005
#define sanic ios_base::sync_with_stdio(0)
#define MOD 1000000
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll t,n,m,k;
ll a[MEM];
main(){
    sanic; cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n%2){
            for(int i=n-1; i>0; i--){
                for(int j=0; j<i; j++){
                    if(j<n/2) cout << 1 << ' ';
                    else cout << -1 << ' ';
                }
            }
        }
        else {
            for(int i=n-1; i>0; i--){
                for(int j=1; j<=i; j++){
                    if(j>n/2) cout << 1 << ' ';
                    else if(j==n/2) cout << 0 << ' ';
                    else cout << -1 << ' ';
                }
            }
        }
        cout << '\n';
    }
}
