#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[100001], h[100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>h[i];
    d[2] = abs(h[1]-h[2]);
    for(int i=3; i<=n; i++) {
        d[i] = min(d[i-1]+abs(h[i]-h[i-1]), d[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<d[n]<<fin;
}
