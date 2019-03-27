#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 200001;
vector<int> adj[maxn];
int n, ans=0, dis[maxn]; bool vis[maxn];
unordered_set <int> st;
void dfs(int u) {
    vis[u] = 1; st.insert(u);
    for(int x: adj[u]) {
        if(vis[x]) {ans = max(ans,dis[u]-dis[x]+1); return; }
        else if(!vis[x]) {dis[x] = dis[u] + 1; dfs(x); }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=1,v; i<=n; i++) {
        cin>>v;
        adj[i].pb(v);
    }
    dfs(1);

    cout<<ans<<fin;
}
