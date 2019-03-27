#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 300001
int n,m, items[maxn], psum[maxn]; vector<int> adj[maxn]; queue<int> q; bool vis[maxn];
void bfs(int u) {
    q.push(u); vis[u]=1; psum[u]=items[u];
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int v: adj[cur]) {
            if(!vis[v]) {vis[v]=1; psum[v]=psum[cur]+items[v]; q.push(v);}
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int t; cin>>t;
        int k,temp; cin>>k;
        for(int j=0; j<k; j++) {
            cin>>temp;
            adj[t].pb(temp);
        }
    }
    for(int i=1; i<=n; i++) cin>>items[i];
    bfs(1);
    int ans = INT_MAX;
    for(int i=1; i<=n; i++) {
        if(adj[i].size()==0 && vis[i]) {

            ans = min(ans,psum[i]);
        }
    }
    cout<<ans<<end;
}


