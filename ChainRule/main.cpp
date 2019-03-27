#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
const int maxn = 300000;
typedef pair<int,int> pi;
int n,m, dis[maxn],rev[maxn]; vector<pi> adj[maxn];
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0, u, v, w; i<m; i++) {
        cin>>u>>v>>w;
        adj[u].pb({v,w}); adj[v].pb({u,w});
    }
    priority_queue<pi> pq;
    memset(dis,0x3f3f3f3f,sizeof(dis)); dis[0]=0;
    pq.push({0,0});
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for(auto &x: adj[u]) {
            if(dis[u]+x.second<dis[x.first]) {
                dis[x.first] = dis[u]+x.second;
                pq.push({-dis[x.first],x.first});
            }
        }
    }
    memset(rev,0x3f,sizeof(rev)); rev[n-1]=0;
    pq.push({0,n-1});
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for(auto &x: adj[u]) {
            if(rev[u]+x.second<rev[x.first]) {
                rev[x.first] = rev[u] + x.second;
                pq.push({-rev[x.first],x.first});
            }
        }
    }
    int ans = -1;
    for(int i=0; i<n; i++) ans = max(ans,dis[i]+rev[i]); cout<<ans<<end;
}

