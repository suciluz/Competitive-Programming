#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 1501;
int n,m,k,dis[maxn],dis2[maxn];
vector<int> adj[maxn]; bool vis[maxn];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0,u,v; i<m; i++) {
        cin>>u>>v; adj[u].pb(v); adj[v].pb(u);
    }
    queue <int> q; q.push(1); vis[1]=1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int x: adj[u]) {
            if(!vis[x]) {vis[x] = 1; dis[x] = dis[u] + 1; q.push(1); }
        }
    }
    memset(vis,0,sizeof(vis));
    q.push(n); vis[n]=1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int x: adj[u]) {
            if(!vis[x]) {vis[x] = 1; dis2[x] = dis2[u] + 1; q.push(1); }
        }
    }
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            int tmp1 = abs(dis[i]-dis[j]);
            if(abs(dis[i]-dis[j]) <= k) cnt++;
        }
        cout<<cnt<<fin;
    }
}

