#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 1001;
struct E{int v; double w, dw;
    friend bool operator<(const E &x, const E &y) {return x.w>y.w;}
};
vector<E> adj[maxn];
int n,m, nv[maxn]; double dis[maxn],ddis[maxn];
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1,u,v,d; i<=m; i++) { double s;
        cin>>u>>v>>d>>s;
        double w = d/s*60.0, dw = d/(s*0.75)*60.0;
        adj[u].pb({v,w,dw}); adj[v].pb({u,w,dw});
    }
    for(int i=0; i<=n; i++) dis[i] = (double) INT_MAX;
    priority_queue <E> pq; pq.push({1,0,0}); dis[1] = 0;
    while(!pq.empty()) {
        int cur = pq.top().v; double curw = pq.top().w; pq.pop();
        if(curw>dis[cur]) continue;
        for(auto &x : adj[cur]) {
            if(dis[cur]+x.w<dis[x.v]) {
                dis[x.v] = dis[cur]+x.w; nv[x.v] = nv[cur] + 1; ddis[x.v] = ddis[cur] + x.dw;
                pq.push({x.v,dis[x.v],ddis[x.v]});
            }
        }
    }
    cout<<nv[n]<<fin;
    cout<<round(ddis[n] - dis[n])<<fin;
}
