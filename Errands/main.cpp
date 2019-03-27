#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 100001;
int n,m,q,c;
int dis[maxn]; bool vis[maxn];
vector<int> adj[maxn];
void bfs(int src) {
    queue <int> q; q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop(); vis[u] =1;
        for(int x: adj[u]) {
            if(!vis[x]) {vis[x] = 1; dis[x] = dis[u]+1; q.push(x);}
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>q>>c;
    for(int i=0,u,v; i<m; i++) {
        cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }
    bfs(c);
    for(int i=0,a,b; i<q; i++) {
        cin>>a>>b;
        if(!vis[a] || !vis[b]) cout<<"This is a scam!"<<fin;
        else cout<<dis[a]+dis[b]<<fin;
    }
}
