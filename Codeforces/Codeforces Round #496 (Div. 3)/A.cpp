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
ll n,m,k;
string s,t;
ll a[MEM];
vector<ll> ans;
main(){
    //sanic; cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    ll k=1;
    for(int i=0; i<n; i++){
        //cout << k << ' ' << a[i] << '\n';
        if(a[i]!=k){
            ans.push_back(k-1);
            k=1;
        }
        k++;
    }
    ans.push_back(k-1);
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';
}
