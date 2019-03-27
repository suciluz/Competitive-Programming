#include <bits/stdc++.h>
using namespace std;
const int M=100002;
int N, P, dis[M], L, rt, cnt; bool pho[M]; vector<int> g[M],g2[M];
void tree_pruning(int u, int par){
    if(par!=-1) dis[u]=dis[par]+1;
    if(dis[u] > L && pho[u]) { L=dis[u]; rt=u;}
    for(int v: g[u]){
        if(v==par) continue;
        tree_pruning(v, u);
        if(!g2[v].empty()||pho[v]) {g2[u].push_back(v); g2[v].push_back(u); cnt++;}
    }
}
void dfs(int u, int par){
    if(par!=-1) { dis[u]=dis[par]+1; L=max(L, dis[u]);}
    for(int v: g2[u]){
        if(v==par) continue;
        dfs(v, u);
    }
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &P);
    for(int i=0; i<P; i++){
        scanf("%d", &rt); pho[rt]=1;
    }
    for(int i=1, x, y; i<N; i++){
        scanf("%d %d", &x, &y);
        g[x].push_back(y); g[y].push_back(x);
    }
    tree_pruning(rt, -1);
    memset(dis, 0, sizeof(dis)); L=0;
    dfs(rt, -1);
    printf("%d\n", 2*cnt-L);
}
