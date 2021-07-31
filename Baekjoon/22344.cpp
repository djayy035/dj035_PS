#include <bits/stdc++.h>
#define MEM 100006
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll t,n,m,k;
vector<pi> g[MEM];
ll v[MEM], ans[MEM];
pi ff[MEM];
vector<ll> xx, vr, gr;
void dfs(ll a, ll b, ll c){
    if(v[a]){
        if(ff[a].x==b && ff[a].y==c) return;
        else if(ff[a].x==b && ff[a].y!=c) {
            cout << "No";
            exit(0);
        }
        else{
            xx.push_back(2*(c-ff[a].y)/(ff[a].x-b));
            return;
        }
    }
    else ff[a] = {b,c};
    gr.push_back(a);
    v[a] = 1;
    if(b>0) vr.push_back(-c);
    else vr.push_back(c);
    for(int i=0; i<g[a].size(); i++)
        dfs(g[a][i].x, -b, g[a][i].y-c);
    return;
}
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        ll q1,q2,q3;
        cin >> q1 >> q2 >> q3;
        g[q1].push_back({q2,q3});
        g[q2].push_back({q1,q3});
    }
    for(int i=1; i<=n; i++){
        if(v[i]) continue;
        xx.clear();
        vr.clear();
        gr.clear();
        dfs(i,1,0);
        sort(xx.begin(), xx.end());
        xx.erase(unique(xx.begin(), xx.end()), xx.end());
        if(xx.size()>1 || (xx.size()==1 && xx[0]%2)){
            cout << "No";
            exit(0);
        }
        sort(vr.begin(), vr.end());
        ll p=(xx.size() ? xx[0]/2 : vr[vr.size()/2]);
        for(int j=0; j<gr.size(); j++)
            ans[gr[j]] = ff[gr[j]].x*p+ff[gr[j]].y;
    }
    cout << "Yes\n";
    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';
}
