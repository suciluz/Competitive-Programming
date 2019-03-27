#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define maxn 200001
int n,r,s,e, dis[maxn], path[maxn]; bool vis[maxn]; vector<int> adj[maxn]; queue <int> q;
#define pb push_back

void bfs(int trig) {
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int v: adj[cur]) {
            if(trig==2) {
                if(!vis[v]) {path[v]=cur;vis[v]=1;q.push(v);}
            } else {
                if(!vis[v]) {dis[v]=dis[cur]+1;vis[v]=1;q.push(v);}
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); for(int i=0; i<maxn; i++) vis[i]=0; memset(dis,0,sizeof(dis));
    cin>>n>>r;
    for(int i=1, u,v; i<=n-1; i++) {
        cin>>u>>v; adj[u].pb(v); adj[v].pb(u);
    }
    for(int i=0, rab; i<r; i++) {cin>>rab; vis[rab]=1; q.push(rab); } cin>>s>>e; bfs(1);
    for(int i=0; i<maxn; i++) vis[i]=0; q.push(s); vis[s]=1; path[s]=-1; bfs(2);
    int ans = 100000000;
    for(int i=e; i!=-1; i=path[i]) ans=min(dis[i],ans);
    cout<<ans<<'\n';
}


