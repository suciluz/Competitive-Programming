#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef pair<int,int> pi;
typedef long long ll;
set<int> st;
bool np [301][301];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m; ll ans = 0; cin>>n>>m;
    vector<pi> fl(n+1);
    for(int i=1; i<=n; i++) {
        cin>>fl[i].first>>fl[i].second;
    }
    for(int i=0; i<m; i++) {
        int a,b; cin>>a>>b;
        np[a][b] = np[b][a] = 1;
    }
    for(int i=1; i<=n; i++) np[i][i] = 1;
    for(int i=1; i<=n; i++) {
        ans = max(ans, (ll)fl[i].second);
        for(int j=1; j<=n; j++) {
            if(np[i][j]) continue;
            ans = max(ans, (ll) fl[i].second * fl[j].first + fl[j].second);
            for(int k=1; k<=n; k++) {
                if(np[i][j] || np[j][k] || np[i][k]) continue;
                ll tmp2 = 0;
                ll tmp = tmp2*fl[i].first + fl[i].second;
                tmp = tmp*fl[j].first + fl[j].second;
                tmp = tmp*fl[k].first + fl[k].second;
                ans = max(ans, tmp);
            }
        }
    }
    cout<<ans<<fin;
}


