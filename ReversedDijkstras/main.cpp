#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 19;
vector<int> adj[maxn]; int dis[maxn]; bool vis[maxn];
int n,m,a,b,V;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>a>>b>>V;
    for(int i=0,u,v; i<m; i++) {
        cin>>u>>v; adj[u].pb(v); adj[v].pb(u);
    }

}

