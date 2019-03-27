#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
typedef pair<int,int> pi;
int d[2][200001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n; vector<pi> v (n+1);
    for(int i=1; i<=n; i++) cin>>v[i].first>>v[i].second;
    memset(d,0x3f,sizeof(d));
    d[0][0] = d[1][0] = 0;
    for(int i=2; i<=n; i++) {
        d[0][i] = min (d[0][i], min(abs(v[i].first-v[i].second), abs(v[i-1].first-v[i].second)));
        d[1][i] = min (d[1][i], min(abs(v[i].first-v[i].second), abs(v[i-2].first-v[i].second)));
    }
    cout<<d[0][n]<<" "<<d[1][n];
}


