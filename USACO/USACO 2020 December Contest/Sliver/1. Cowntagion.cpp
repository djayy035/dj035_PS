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
ll d[MEM],ans;
main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        ll q1,q2;
        cin >> q1 >> q2;
        d[q1]++,d[q2]++;
    }
    ans = n-1;
    for(int i=1; i<=n; i++)
        if(d[i]>1 || i<2)
            ans += ceil(log2(d[i]+1+(i<2?0:-1)));
    cout << ans;
}
