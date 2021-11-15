#include <bits/stdc++.h>
#define MEM 252525
#define sanic ios_base::sync_with_stdio(0)
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = 1e13+7;
const ll MOD = 1e9+7;
ll gcd(ll a, ll b){
    if(a%b) return gcd(b, a%b);
    return b;
}
ll n,a,b,c=INF;
vector<pi> v;
int main()
{
    sanic;
    cin >> n;
    if(n==1){
        cout << "4\n0 1\n1 2\n2 3";
        return 0;
    }
    for(int i=2; i<=500; i++)
        for(int j=1; j<=500; j++){
            if(i*j>n || i+j+n-i*j+2>500) continue;
            if(c>n-i*j || i+j+n-i*j+2>a+b+c+2) a=i,b=j,c=n-i*j;
        }
    //cout << a << ' ' << b << ' ' << c << '\n';
    cout << a+b+c+2 << '\n';
    for(int i=0; i<a; i++)
        cout << 0 << ' ' << i+1 << '\n';
    for(int i=1; i<=b; i++)
        cout << 1 << ' ' << a+i << '\n';
    cout << a+b << ' ' << a+b+1 << '\n';
    for(int i=0; i<c; i++)
        cout << a+b+1+i << ' ' << a+b+2+i << '\n';
}
