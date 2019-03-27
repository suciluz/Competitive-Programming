#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 400000;
typedef long long ll;
int n; ll dis[maxn]; bool vis[maxn];
vector<int> adj[maxn];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0,u,v; i<n-1; i++) {
        cin>>u>>v; adj[u].pb(v); adj[v].pb(u);
    }
    queue <int> q; q.push(1); ll endd = -1,child,maxd=-1,maxc;
    while(!q.empty()) {
        int u = q.front(); q.pop(); vis[u] =1;
        for(int x: adj[u]) {
            if(!vis[x]) {
                vis[x] = 1; dis[x] = dis[u] + 1; q.push(x);
                if(dis[x] >= endd) {
                    endd = dis[x]; child = x;
                }
            }
        }
    }
    memset(vis,0,sizeof(vis)); memset(dis,0,sizeof(dis));
    q.push(child);
    while(!q.empty()) {
        int u = q.front(); q.pop(); vis[u] = 1;
        for(int x: adj[u]) {
            if(!vis[x]) {
                vis[x] = 1; dis[x] = dis[u] + 1; q.push(x);
                if(dis[x] >= maxd) {
                    maxd = dis[x]; maxc = x;
                }
            }
        }
    }
    int cnt =0;
    for(int i=1; i<=n-1; i++) {
        if(dis[i]==maxd) cnt++;
    }
    cout<<maxd+1<<" "<<cnt<<fin;
}
