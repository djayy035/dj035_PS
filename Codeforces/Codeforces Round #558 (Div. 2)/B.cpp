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
ll n,m,k,t,ans;
ll a[MEM];
ll cnt[MEM];
int main(){
    sanic;
    cin >> n;
    for(int i=1; i<=n; i++){
        ll q;
        cin >> q;
        cnt[q]++;
        a[cnt[q]-1]--;
        a[cnt[q]]++;
        m=max(m,cnt[q]);
        ll b=0;
        if(a[1]==i) b=1;
        else if(a[i]==1) b=1;
        else if(a[1]==1 && a[m]*m==i-1) b=1;
        else if(a[m-1]*(m-1)==i-m && a[m]==1) b=1;
        if(b) ans = i;
    }
    cout <<ans;
}
