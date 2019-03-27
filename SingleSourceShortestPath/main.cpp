#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 1001
typedef pair<int,int> pi;
int n,m, dis[maxn]; vector<pi> adj[maxn];
void dijkstras (int src) {
    memset(dis,0x3f3f3f3f,sizeof(dis)); dis[src] = 0;
    priority_queue<pi> pq;
    pq.push({0,src});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(auto &x: adj[u]) {
            if(dis[u]+x.second<dis[x.first]) {
                dis[x.first] = dis[u]+x.second;
                pq.push({-dis[x.first],x.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1,u,v,w; i<=m; i++) {
        cin>>u>>v>>w;
        adj[u].pb({v,w}); adj[v].pb({u,w});
    }
    dijkstras(1);
    for(int i=1; i<=n; i++) {
        if(dis[i]!=0x3f3f3f3f) cout<<dis[i]<<end;
        else cout<<-1<<end;
    }
}

