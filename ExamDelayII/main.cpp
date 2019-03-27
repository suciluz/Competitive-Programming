#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
#define maxn 251
typedef pair<int,int> pi;
int n,m,mx=-1,dis[maxn],parent[maxn]; vector<pi> adj[maxn];
void dijkstras (int src) {
    memset(dis,0x3f3f3f3f,sizeof(dis)); dis[src] = 0;
    priority_queue<pi> pq;
    pq.push({0,src});
    while(!pq.empty()) {
        int u = pq.top().second,w = pq.top().first;
        pq.pop();
        if(w>dis[u]) continue;
        for(auto &x: adj[u]) {
            if(-w+x.second < dis[x.first]) {
                dis[x.first] = -w + x.second;
                parent[x.first] = u;
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
    for(int i=0; i<n; i++) cout<<parent[i]<<" ";
    /*
    for(int i=n; i!=-1; i=parent[i]) {
        int v = parent[i];
        for(auto &x: adj[i]) {
            if(x.first == v) {
                mx = max(mx,x.second);
            }
        }
    }*/
    cout<<dis[n]<<" "<<mx<<fin;
}

