#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 2000000;
int n,e,s,path[maxn],des; vector <int> adj[maxn]; bool vis[maxn], nchild[maxn];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>e>>s;
    for(int i=0,u,v; i<e; i++) {cin>>u>>v; nchild[v] = 1; adj[v].pb(u);}
    queue <int> q;
    q.push(s); path[s] = -1;
    while(!q.empty()) {
        int u = q.front(); q.pop(); vis[u] = 1;
        if(!nchild[u]) { des = u; break; }
        for(int x: adj[u]) {
            if(!vis[x]) {vis[x] = 1; path[x]=u; q.push(x); }
        }
    }
    cout<<des<<" ";
    for(int i=des; i!=-1; i=path[i]) {
        if(path[i]==s) break;
        cout<<path[i]<<" ";
    }
}
