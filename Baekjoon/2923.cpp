#include <bits/stdc++.h>
#define sanic ios_base::sync_with_stdio(0);
#define MEM 500005
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll MOD = 1e9+7;
const ll INF = 1e13;
ll n,m,p,ans,t;
ll a[MEM], b[MEM], ima[MEM], imb[MEM];
int main() {
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        a[n]++;
        b[m]++;
        for(int i=1; i<=100; i++)
            ima[i] = a[i], imb[i] = b[i];
        ll pa=1, pb=100;
        ans = 0;
        while(pa<=100 && pb>0){
            while(!ima[pa] && pa<=100) pa++;
            while(!imb[pb] && pb>0) pb--;
            if(pa>=100 || pb<=0) break;
            ans = max(ans, pa+pb);
            if(ima[pa]>imb[pb]){
                ima[pa] -= imb[pb];
                imb[pb] = 0;
            }
            else{
                imb[pb] -= ima[pa];
                ima[pa] = 0;
            }
        }
        cout << ans << '\n';
    }
}
