#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int m,n,dis[200001],p[200001],cnt=0;
typedef pair<int,int> pi;
vector<pi> adj[200001];
struct E {int u, v, w;} e[200001];
bool cmp(E x, E y) {return x.w > y.w;}

int Find (int d) {
    if(d!=p[d]) p[d] = Find(p[d]);
    return p[d];
}

void dfs(int cur, int pre){
    for (pi i : adj [cur]){
        if (i.first != pre){
            dis[i.first] = min(dis[cur], i.second);
            dfs(i.first, cur);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m; for(int i=0; i<=n; i++) p[i]=i;
    for(int i=0; i<m; i++) {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e,e+m,cmp);
    for(int i=0; i<m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(cnt==n-1)break;
        int fu = Find(u), fv=Find(v);
        if(fu!=fv) {p[fu] = fv; cnt++; adj[u].pb({v,w}); adj[v].pb({u,w});}
    }
    dis[1]=INT_MAX;
    dfs(1,-1); dis[1]=0;
    for(int i=1; i<=n; i++) cout<<dis[i]<<end;
}
