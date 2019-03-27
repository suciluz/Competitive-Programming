#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 2001
typedef pair<int,int> pi;
int n,m,b,q,dis[maxn];vector<pi> adj[maxn];
void dijkstras (int src) {
    memset(dis,0x3f3f3f3f,sizeof(dis)); dis[src]=0;
    priority_queue <pi> pq;
    pq.push({0,src});
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop(); vis[u]=0;
        for(auto &x: adj[u]) {
            if(dis[u]+x.second<dis[x.first]) {
                dis[x.first] = dis[u] + x.second;
                pq.push({-dis[x.first],x.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>b>>q;
    for(int i=1,u,v,w; i<=m; i++) {
        cin>>u>>v>>w;
        adj[u].pb({v,w}); adj[v].pb({u,w});
    }
    dijkstras(b);
    for(int i=1,t; i<=q; i++) {
        cin>>t;
        if(dis[t]!=0x3f3f3f3f) cout<<dis[t]<<end;
        else cout<<-1<<end;
    }
}
