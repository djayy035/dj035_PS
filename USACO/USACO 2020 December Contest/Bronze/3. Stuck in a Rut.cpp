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
char d[MEM];
ll wx[MEM],wy[MEM];
ll dp[MEM];
main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> d[i] >> wx[i] >> wy[i];
        dp[i] = INF;
    }
    vector<ll> ds;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ds.push_back(abs(wx[j]-wx[i]));
            ds.push_back(abs(wy[j]-wy[i]));
        }
    }
    sort(ds.begin(), ds.end());
    for(ll l : ds){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(wx[i]<wx[j] && wy[i]>wy[j] && (d[i]=='E' && d[j]=='N')){
                    if(wx[i]+l==wx[j] && wy[j]+min(dp[j],l)>wy[i])
                        dp[i] = min(dp[i],l);
                    else if(wy[j]+l==wy[i] && wx[i]+min(dp[i],l)>wx[j])
                        dp[j] = min(dp[j],l);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dp[i]==INF) cout << "Infinity";
        else cout << dp[i];
        cout << '\n';
    }
}
