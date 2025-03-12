// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
#define MEM 60
#define x first
#define y second
#define sz size()
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<ll, ll> pi;
const ll INF = 4e18;
const ll MOD = 1e4;
ll gcd(ll a, ll b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
ll abs(ll a, ll b)
{
    return (a > b ? a - b : b - a);
}
ll add(ll a, ll b)
{
    return ((a + b) % MOD + MOD) % MOD;
}
ll sub(ll a, ll b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
ll mul(ll a, ll b)
{
    return ((a * b) % MOD + MOD) % MOD;
}
ll n,k,p,ans;
ll a[MEM][MEM]; // k = 0;
ll fl[MEM][MEM], py; // k = 1;
ll d[6][4] = {0,1,3,2, 1,2,0,3, 2,1,3,0, 1,0,2,3, 0,0,2,2, 1,1,3,3};
ll dx[4] = {-1,0,1,0};
ll dy[4] = {0,1,0,-1};
void f0(ll x, ll y, ll o){
    ll nx=d[a[x][y]][2*o+1];
    //cout << a[x][y] << ' ' << nx << ' ' << x << ' ' << y << ' ' << o << ' ' << x+dx[nx] << ' ' << y+dy[nx] << '\n';
    ans++;
    if(x==n && y==n) {
        if(nx!=1) p = 1;
        return;
    }
    if(x+dx[nx]<=0 || y+dy[nx]<=0 || x+dx[nx]>n || y+dy[nx]>n) {
        p = 1;
        return;
    } 
    if(nx==d[a[x+dx[nx]][y+dy[nx]]][0]) f0(x+dx[nx], y+dy[nx], 0);
    else if(nx==d[a[x+dx[nx]][y+dy[nx]]][2]) f0(x+dx[nx], y+dy[nx], 1);
    else{
        p = 1;
        return;
    }
}
void f1(ll x, ll y, ll o){
    ll nx=d[a[x][y]][2*o+1];
    //cout << a[x][y] << ' ' << nx << ' ' << x << ' ' << y << ' ' << o << ' ' << x+dx[nx] << ' ' << y+dy[nx] << '\n';
    py++;
    if(x==n && y==n) {
        if(nx!=1) p = 1;
        return;
    }
    if(x+dx[nx]<=0 || y+dy[nx]<=0 || x+dx[nx]>n || y+dy[nx]>n) {
        p = 1;
        return;
    } 
    if(nx==d[a[x+dx[nx]][y+dy[nx]]][0]) f1(x+dx[nx], y+dy[nx], 0);
    else if(nx==d[a[x+dx[nx]][y+dy[nx]]][2]) f1(x+dx[nx], y+dy[nx], 1);
    else{
        p = 1;
        return;
    }
}
main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> a[i][j];
    if(!k){
        if(a[1][1]!=1 && a[1][1]!=5) p=1;
        else f0(1,1,0);
        if(p) cout << -1;
        else cout << ans;
    }
    else{
        ans = INF;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                fl[i][j] = a[i][j];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int l=0; l<6; l++){
                    if(a[i][j]==l) continue;
                    a[i][j] = l;
                    if(a[1][1]!=1 && a[1][1]!=5) {
                        a[i][j] = fl[i][j];
                        continue;
                    }
                    p = 0;
                    py = 0;
                    f1(1,1,0);
                    if(!p)ans = min(ans, py);
                    a[i][j] = fl[i][j];
                }
            }
        }
        if(ans==INF) cout << -1;
        else cout << ans;
    }
}
