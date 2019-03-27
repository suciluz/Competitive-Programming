#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
const int mod = 1000000007;
int a,b,c,d,e;
ll solve (ll n) {
    if(n==0) return e%mod;
    if(a==0&&c==0) return 0;
    ll ans = (a*solve((int)floor(n/b)) + c*solve((int)floor(n/d)))%mod;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>a>>b>>c>>d>>e>>n;
    cout<<solve(n%mod)%mod<<fin;
}
