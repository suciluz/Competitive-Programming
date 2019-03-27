#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 10001
int n,m,a,b, dis[maxn], vis[maxn]; vector<int> adj[maxn];
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0,u,v; i<m; i++) {
        cin>>u>>v; adj[u].pb(v); adj[v].pb(u);
    }cin>>a>>b;
    queue <int> q;
    q.push(a); vis[a]=1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int x : adj[u]) {
            if(!vis[x]) {vis[x] = 1; dis[x] = dis[u]+1; q.push(x);}
        }
    }
    if(!vis[b]) cout<<0<<end;
    else cout<<1<<end;
}
