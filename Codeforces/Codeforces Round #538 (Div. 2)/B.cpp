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
ll t,n,m,k;
pi a[MEM];
int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> a[i].x;
        a[i].y = i;
    }
    sort(a,a+n);
    ll ans=0;
    priority_queue<ll> pq;
    for(int i=n-1; i>n-1-m*k; i--){
        ans += a[i].x;
        pq.push(-a[i].y);
    }
    cout << ans << '\n';
    ll p=1;
    while(!pq.empty()){
        if(!(p%m) && p!=m*k)
            cout << -pq.top()+1 << ' ';
        p++;
        pq.pop();
    }
}
