#include <bits/stdc++.h>
#define MEM 50005
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13;
const ll MOD = 1e9+7;
ll t,n,m,k,c,ans;
ll dp[505][MEM];
ll s[505][MEM];
int main(){
    sanic; cin.tie(0); cout.tie(0);
    cin >> t;
    dp[0][0] = 1;
    for(int i=1; i<=500; i++)
    	for(int j=0; j<=50000; j++){
    		if(j-i>=0) dp[i][j] += dp[i-1][j-i], dp[i][j] %= MOD;
    		dp[i][j] += dp[i-1][j];
    		dp[i][j] %= MOD;
    	}
    for(int i=0; i<=500; i++){
    	s[i][0] = dp[i][0];
    	for(int j=1; j<=50000; j++)
    		s[i][j] = (s[i][j-1]+dp[i][j])%MOD;
    }
    while(t--){
    	cin >> n >> m;
    	ans=0;
    	for(int i=1; i<=500; i++){
    		ll p=i*(i+1)/2;
    		ans = (ans+(n>=p-m ? (s[i][n]-(p-m>0 ? s[i][p-m-1]:0)+MOD)%MOD:0))%MOD;
    	}
    	cout << ans <<'\n';
    }
}
