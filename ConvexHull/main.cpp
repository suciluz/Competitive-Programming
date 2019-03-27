#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 2001
struct E{int v,w,h;
    friend bool operator<(const E &x, const E &y) {return x.w>y.w;}
};
int k,n,m,a,b,ans,dis[maxn][201]; vector<E> adj[maxn];
void dijkstras (int src,int fin) {
    memset(dis,0x3f3f3f3f,sizeof(dis)); dis[src][0]=0;
    priority_queue <E> pq;
    pq.push({a,0,0});
    while(!pq.empty()) {
        int u = pq.top().v, w = pq.top().w, h = pq.top().h; pq.pop(); if(u==fin)break;
        for(auto &x: adj[u]) {
            if(dis[u][h]+x.w<dis[x.v][x.h+h] && x.h+h<k) {
                dis[x.v][x.h+h] = dis[u][h]+x.w;
                pq.push({x.v,dis[x.v][x.h+h],x.h+h});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>k>>n>>m;
    for(int i=1,u,v,w,h; i<=m; i++) {
        cin>>u>>v>>w>>h;
        adj[u].pb({v,w,h}); adj[v].pb({u,w,h});
    } cin>>a>>b; dijkstras(a,b); ans = *min_element(dis[b],dis[b]+201);
    if(ans==0x3f3f3f3f) cout<<-1<<end;
    else cout<<ans<<end;
}

