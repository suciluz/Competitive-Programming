#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
struct v{ll x, y, z;
    friend bool operator==(const v &a, const v &b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
    friend bool operator<(const v &a, const v &b){ return a.x < b.x || (a.x == b.x && (a.y < b.y || (a.y == b.y && a.z < b.z))); }
};
set<v> st;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll x,y,z,n; cin>>x>>y>>z>>n;
    for(int i=0; i<n; i++) {
        ll a,b,c; cin>>a>>b>>c;
        ll va = x-a, vb = y-b, vc = z-c;
        ll g = abs(__gcd(va, __gcd(vb,vc)));
        va /= g; vb /= g; vc/=g;
        st.insert({va,vb,vc});
    }
    cout<<st.size()<<fin;
}


