#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM=100;
int N, M,dis[MM]; vector<pi> adj[MM]; bool vis[MM];
void prim(int st) {
    memset(dis,0x3f, sizeof(dis) ); dis[st]=0;
    for(int i=1; i<=N; i++) {
        int Min = 1e9, id=-1;
        for(int j=1; j<=N; j++) {
            if(dis[j]<Min&&!vis[j]){
                Min=dis[j];id=j;
            }
        }
        vis[id]=1;
        for(pi e: adj[id])
            if(!vis[e.first] && dis[e.first]>e.second)   //just change this line and it will be dijstra
                dis[e.first] = e.second;
    }
}

int main() {
    scanf("%d %d", &N,&M);
    for(int i=1, u,v,w; i<=M; i++) {
        scanf("%d %d %d", &u,&v,&w);
        adj[u].push_back({v,w}); adj[v].push_back({u,w});
    }
    prim(1);
    for(int i=1; i<=N; i++) printf("%d ", dis[i]);
    return 0;
}

/*
Keep a dis,vis arrays
initialize dis array with infinity except start point
1. Select
2. update

1.1st round select A

6 9
1 2 34
1 3 46
1 6 19
2 5 12
3 4 17
3 6 25
4 5 38
4 6 25
5 6 26

animal farm
maximum strategic savings - disjoint set and MST
*/
