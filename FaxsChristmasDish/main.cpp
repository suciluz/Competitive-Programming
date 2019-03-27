#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 300001
int n,m,d,items[maxn]; vector<int> adj[maxn]; bool vis[maxn];
int dfs(int x) {
    int ans=0;
    if(adj[x].empty()) {ans = items[x];}
    else {
        for(int v: adj[x]) ans = max(ans,dfs(v));
        ans = min(ans,items[x]);
    } return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>d;
    for(int i=0; i<m; i++) {
        int t; cin>>t;
        int k,temp; cin>>k;
        for(int j=0; j<k; j++) {
            cin>>temp;
            adj[t].pb(temp);
        }
    }
    memset(items,0x3f3f3f3f,sizeof(items));
    for(int i=1; i<=d; i++) { int x; cin>>x; if(items[x]==0x3f3f3f3f) items[x]=i; }
    int ans = dfs(1);
    if(ans==0x3f3f3f3f) cout<<-1<<end;
    else cout<<ans<<end;
}
