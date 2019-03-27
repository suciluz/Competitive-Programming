#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
typedef pair<ll,ll> pi;
vector<pi> v;
int n;
ll ans = 0;
long long gcd(long a, long b) {
    if(!a && !b) return 0;
    return b == 0 ? a : gcd(b, a % b);
}
ll permu (ll x) {
    return (x*(x-1))/2LL;
}

ll solve () {
    for(int i=0; i<n; i++) {
        map <pi, ll> mp;
        for(int j=i+1; j<n; j++) {
            ll dx = v[i].first - v[j].first, dy = v[i].second - v[j].second;
            if(gcd(dx,dy)) {
                pi tmp = {dx/gcd(dx,dy), dy/gcd(dx,dy)};
                mp[tmp]++; //avoid floating
            }
        }
        ans += permu(n-i-1);
        for(auto x : mp) ans -= permu(x.second);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) {
        int x,y; cin>>x>>y; v.push_back({x,y});
    }
    cout<<solve()<<fin;
}
