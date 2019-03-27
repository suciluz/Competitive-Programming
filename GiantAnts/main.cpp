#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int n,m,w, dis[101], dis2[101], path[101]; vector<int> adj[101]; bool ants[101],vis[101]; queue<int> q;

void bfsAnt () {
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int v: adj[cur]) {
            if(!vis[v]) {vis[v]=1; dis[v]=dis[cur]+4;q.push(v);}
        }
    }
}
void bfs() {
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int v: adj[cur]) {
            if(!vis[v] && !ants[v] && dis2[cur]<dis[v]) {vis[v]=1; dis2[v]=dis2[cur]+1; q.push(v);  }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int x,y;cin>>x>>y;
        adj[x].pb(y); adj[y].pb(x);
    } cin>>w;
    for(int i=0; i<w; i++) {int t;cin>>t;ants[t]=1; vis[t]=1; q.push(t);} bfsAnt();
    memset(vis,0,sizeof(vis));
    q.push(1); bfs();
    if(!vis[n]) cout<<"sacrifice bobhob314"<<end;
    else cout<<dis2[n]<<end;
}
