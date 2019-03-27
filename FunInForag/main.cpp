#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 100010
typedef long long ll;
struct E {int des,w,lvl;
    friend bool operator<(const E &x, const E &y) {return x.w>y.w;}
};
int n, m,a,b; vector<E> adj[maxn];  bool vis[maxn];
ll dis[maxn],c;
void dijkstras (int src,int fin,int slvl) {
    memset(dis,0x3f3f3f3f,sizeof(dis)); dis[src] = 0;
    priority_queue<E> pq;
    pq.push({src,0,0});
    while(!pq.empty()) {
        int u = pq.top().des,cost = pq.top().w;
        //if(cost > dis[u]) continue;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto &x: adj[u]) {
            if(!vis[x.des]&&dis[u]+x.w<dis[x.des] && x.lvl<=slvl) {
                dis[x.des] = dis[u]+x.w;
                pq.push({x.des,dis[x.des],x.lvl});
            }
        }
        if(u==fin) break;
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=1,x,y,z; i<=m; i++) {
        scanf("%d %d %d",&x,&y,&z);
        E tmp = {y,z,i}; E tmp2 = {x,z,i};
        adj[x].pb(tmp); adj[y].pb(tmp2);
    } scanf("%d %d %lld",&a,&b,&c);
    dijkstras(a,b,m);
    if(a==b) printf("%d",0);
    if(dis[b]>=c) {printf("%d",-1);return 0; }
    int l=0, h=m, mid=0;
    while(l<h) {
        mid = l+(h-l)/2;
        dijkstras(a,b,mid);
        if(dis[b]<c) h=mid;
        else l=mid+1;
    }
    printf("%d",l);
}
