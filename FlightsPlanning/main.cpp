#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
const int maxn = 20001;
typedef pair<ll,ll> pi;
int n,m,k,q,cnt=0; ll dis[maxn],ans=0; vector<pi> adj[maxn]; bool hub[maxn],pos[maxn];
void dijkstras (int src) {
    memset(dis,0x3f3f3f3f3f3f3f3f,sizeof(dis)); dis[src] = 0;
    priority_queue<pi> pq;
    pq.push({0,src});
    while(!pq.empty()) {
        int u = pq.top().second,w = pq.top().first;
        pq.pop();
        if(w>dis[u])continue;
        for(auto &x: adj[u]) {
            if(dis[u]+x.second<dis[x.first]) {
                dis[x.first] = dis[u]+x.second;
                pq.push({-dis[x.first],x.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k>>q;
    for(int i=1,u,v,w; i<=m; i++) {
        cin>>u>>v>>w;
        adj[u].pb({v,w});
    }
    for(int i=0,tmp; i<k; i++) {
        cin>>tmp;
        hub[tmp]=1;
    }
    for(int i=0; i<q; i++) {
        int st,en; cin>>st>>en; bool trig = 0;
        if(i==0) {
            dijkstras(st);
            for(int i=1; i<=n; i++) {
                if(dis[i]==0x3f3f3f3f3f3f3f3f) pos[i] = 1;
            }
        }
        else if(i!=0) {
            if(pos[st]==1 || pos[en]==1) {trig=1;}
            else dijkstras(st);
        }
        if(dis[en]!=0x3f3f3f3f3f3f3f3f && trig==0) {
            cnt++; ans+=dis[en];
        }
    }
    cout<<cnt<<fin;
    cout<<ans<<fin;
}
