#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
const int maxn = 1e5+1;
struct E {int u,v,w,c; friend bool operator<(const E &x, const E &y) {return x.w<y.w;} };
vector <pair<int,int>> adj[maxn], adj2[maxn]; vector<E> edges, e;
int dis[maxn], dis2[maxn];
int N,M,A,B,Q;

void dijkstra (int src, int des, int trig) {
    if(trig) {
        memset(dis,0x3f,sizeof(dis)); dis[src] = 0;
        priority_queue <pair<int,int>> pq;
        pq.push({0,src});
        while(!pq.empty()) {
            int u = pq.top().second, w = pq.top().first;
            pq.pop();
            if(-w > dis[u]) continue;
            for(auto &v: adj[u]) {
                if(dis[u] + v.second < dis[v.first]) {
                    dis[v.first] = dis[u] + v.second;
                    pq.push({-dis[v.first], v.first});
                }
            }
        }
    }
    else {
        memset(dis2,0x3f,sizeof(dis2)); dis2[src] = 0;
        priority_queue <pair<int,int>> pq;
        pq.push({0,src});
        while(!pq.empty()) {
            int u = pq.top().second, w = pq.top().first;
            pq.pop();
            if(-w > dis2[u]) continue;
            for(auto &v: adj2[u]) {
                if(dis2[u] + v.second < dis2[v.first]) {
                    dis2[v.first] = dis2[u] + v.second;
                    pq.push({-dis2[v.first], v.first});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>N>>M>>A>>B;
    for(int i=0,u,v,w,c; i<M; i++) {
        cin>>u>>v>>w>>c;
        adj[u].push_back({v,w}); adj2[v].push_back({u,w});
        e.push_back({u,v,w,c});
    }
    dijkstra(A,B,1); dijkstra(B,A,0);
    for(int i=0; i<e.size(); i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w, c = e[i].c, d = dis[u] + dis2[v] + w;
        if(dis[u]!=0x3f3f3f3f && dis2[v]!=0x3f3f3f3f) edges.push_back({u,v,d,c});
    }
    sort(edges.begin(), edges.end());
    vector<int> cost(edges.size()); cost[0] = edges[0].c;
    for(int i=1; i<edges.size(); i++) cost[i] = cost[i-1]+edges[i].c;
    cin>>Q;
    for(int i=0; i<Q; i++) {
        int q; cin>>q;
        int lo = 0, hi = edges.size()-1, mid, ans=-1;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(edges[mid].w <= q) { lo = mid+1; ans = mid;}
            else hi = mid-1;
        }
        if(ans==-1) cout<<0<<fin;
        else cout<<cost[ans]<<fin;
        //cout<<ans<<" "<<lo<<fin;
    }
}


