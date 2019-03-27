#include <bits/stdc++.h>
using namespace std;
const int MM=10002, INF=99999999;
typedef pair<int, int> pii;
int N, M, D, dis[MM]; vector<pii> adj[MM]; bool d[MM];
void prim(int st){
    priority_queue<pii> Q;
    memset(dis,0x3f,sizeof(dis));
    Q.push({0, 1}); dis[1] = 0;
    while(!Q.empty()){
        int w = Q.top().first, u = Q.top().second; Q.pop();
        if( w > dis[u]) continue;
        for(pii e: adj[u]){
            int v = e.first, dd = e.second;
            if(dis[v] > dd){
                dis[v] = dd;  Q.push({dis[v], v});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>N>>M>>D;
    for(int i=0, x, y, z; i<M; i++){
        cin>>x>>y>>z;
        adj[x].push_back({y, z}); adj[y].push_back({x, z});
    }
    for(int i=0, x; i<D; i++){
        cin>>x; d[x] = true;
    }
    prim(1);
    int ans = INF;
    for(int i=1; i<=N; i++)
        cout<<dis[i]<<" ";

}
