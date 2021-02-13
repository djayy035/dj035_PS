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
ll a[MEM],p[MEM],c[MEM],ans[MEM];
string s;
main(){
    //sanic; cin.tie(0);
    cin >> n;
    for(int i=1; i<n; i++)
        cin >> a[i];
    for(int i=1; i<n; i++)
        p[i] += p[i-1]+a[i];
    ll k=INF;

    for(int i=0; i<n; i++){
        //cout << p[i] << ' ';
        if(p[i]<k){
            k = p[i];
            t=i;
        }
    }
    //cout << t << ' ';
    ans[t] = 1;
    for(int i=t-1; i>=0; i--)
        ans[i] = ans[i+1]-a[i+1];
    for(int i=t+1; i<n; i++)
        ans[i] = a[i]+ans[i-1];
    for(int i=0; i<n; i++){
        if(ans[i]>200000) {
            cout << -1;
            return 0;
        }
        if(c[ans[i]] || ans[i]>n) {
            cout << -1;
            return 0;
        }
        c[ans[i]] = 1;
    }
    for(int i=0; i<n; i++)
        cout << ans[i] << ' ';
}
