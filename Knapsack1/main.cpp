#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
ll d[100001];
ll max(ll a, ll b) { return (a > b)? a : b; }
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int N,W; cin>>N>>W;
    for(int i=1,w,v; i<=N; i++) {
        cin>>w>>v;
        for(int j=W; j>=w; j--) {
            d[j] = max(d[j],d[j-w]+v);
        }
    }
    cout<<d[W]<<fin;
}
