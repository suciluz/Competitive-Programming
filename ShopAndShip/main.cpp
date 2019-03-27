#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 5001
typedef pair<int,int> pi;
int n,t,k,d,dis[maxn],price[maxn],ans=INT_MAX; vector<pi> adj[maxn];
void dijkstras (int src) {
    memset(dis,0x3f3f3f3f,sizeof(dis)); dis[src]=0;
    priority_queue <pi> pq;
    pq.push({0,src});
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for(auto &x: adj[u]) {
            if(dis[u]+x.second<dis[x.first]) {
                dis[x.first] = dis[u] + x.second;
                if(price[x.first]>=0) ans = min(dis[x.first]+price[x.first],ans);
                pq.push({-dis[x.first],x.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>t;
    for(int i=1,u,v,w; i<=t; i++) {cin>>u>>v>>w; adj[u].pb({v,w}); adj[v].pb({u,w}); } cin>>k; memset(price,-1,sizeof(price));
    for(int i=1,tmp; i<=k; i++) {cin>>tmp; cin>>price[tmp];} cin>>d; dijkstras(d);
    if(price[d]>=0 && price[d]<ans) cout<<price[d]<<end;
    else cout<<ans<<end;
}

