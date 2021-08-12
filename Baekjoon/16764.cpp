#include <bits/stdc++.h>
#define sanic ios_base::sync_with_stdio(0);
#define MEM 500005
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll MOD = 1e9+7;
const ll INF = 1e13;
ll n,m,ans;
ll a[5];
map<vector<ll>, ll> mp;
int main() {
	cin >> n;
	for(int j=0; j<n; j++) {
		for(int i=0; i<5; i++) 
            cin >> a[i];
		sort(a,a+5);
		for(int b=1; b<(1<<5); b++) {
			vector<ll> v;
			for(int i=0; i<5; i++)
				if(b&(1<<i)) v.push_back(a[i]);
			ans += (v.size()%2? 1:-1)*mp[v];
			mp[v]++;
		}
	}
	cout << n*(n-1)/2-ans << '\n';
}
