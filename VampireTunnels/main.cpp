#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 1600;
struct E {int v,w,h;
    friend bool operator<(const E &x, const E &y) {return x.w>y.w;}
};
int s,n,e,dis[maxn][3601]; vector<E> adj[maxn];
void dijkstra () {
    memset(dis,0x3f,sizeof(dis)); dis[0][0] = 0;
    priority_queue <E> pq; pq.push({0,0,0});
    while(!pq.empty()) {
        int u = pq.top().v, w = pq.top().w, h = pq.top().h; pq.pop(); if(u==n-1)break;
        for(auto &x: adj[u]) {
            if(dis[u][h]+x.w<dis[x.v][x.h+h] && x.h+h<=s) {
                dis[x.v][x.h+h] = dis[u][h]+x.w;
                pq.push({x.v,dis[x.v][x.h+h],x.h+h});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>s>>n>>e;
    for(int i=0,u,v,w,t; i<e; i++) {
        cin>>u>>v>>w>>t;
        if(t) { adj[u].pb({v,w,w}); adj[v].pb({u,w,w}); }
        else { adj[u].pb({v,w,0}); adj[v].pb({u,w,0}); }
    }
    dijkstra();
    int ans = *min_element(dis[n-1],dis[n-1]+3601);
    if(ans==0x3f3f3f3f) cout<<-1<<fin;
    else cout<<ans<<fin;
}

