#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn=100001;
int n,m,k,a,b,ans=INT_MAX,dis[maxn],dis2[maxn]; vector<int> adj[maxn],shops; bool vis[maxn];
void bfs (int src, int des, int trig) {
    queue <int> q; q.push(src); vis[src] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int x: adj[u]) {
            if(trig==1) {if(!vis[x]) {vis[x] = 1; dis[x] = dis[u]+1; q.push(x);} }
            else {if(!vis[x]) {vis[x] = 1; dis2[x] = dis2[u]+1; q.push(x);}}
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k>>a>>b;
    for(int i=1,tmp; i<=k; i++) {cin>>tmp; shops.pb(tmp); }
    for(int i=1,u,v; i<=m; i++) {cin>>u>>v; adj[u].pb(v); adj[v].pb(u);}
    bfs(a,b,1); memset(vis,0,sizeof(vis)); bfs(b,a,2);
    for(int i=0; i<k; i++) ans = min(ans,dis[shops[i]]+dis2[shops[i]]);
    cout<<ans<<fin;
}


