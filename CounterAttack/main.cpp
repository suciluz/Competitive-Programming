#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 5001;
typedef pair<int,int> pi; vector<pi> adj[maxn];
int n,m, dis[maxn],dis2[maxn];
void dijkstra (int src) {
    memset(dis,0x3f,sizeof(dis)); memset(dis2,0x3f,sizeof(dis2));
    priority_queue <pi> pq; pq.push({0,1}); dis[src]=0;
    while(!pq.empty()) {
        int u = pq.top().second, w = pq.top().first; pq.pop();
        for(auto &x: adj[u]) {
            if(-w+x.second < dis[x.first]) {
                dis2[x.first] = dis[x.first];
                dis[x.first] = -w + x.second;
                pq.push({-dis[x.first],x.first});
            }
            if(-w+x.second < dis2[x.first] && -w+x.second!=dis[x.first]) {
                dis2[x.first] = -w+x.second;
                pq.push({-dis2[x.first],x.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    scanf("%d %d",&n,&m);
    for(int i=1,u,v,w; i<=m; i++) {
        scanf("%d %d %d",&u,&v,&w); adj[u].pb({v,w}); adj[v].pb({u,w});
    }
    dijkstra(1);
    if(dis2[n]==0x3f3f3f3f) printf("%d\n",-1);
    else printf("%d\n",dis2[n]);
}
