#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 51;
int adj[maxn][maxn]; string s;
int dis[maxn]; bool vis[maxn];
int fbfs (int src) {
    memset(dis,0,sizeof(dis)); memset(vis,0,sizeof(vis));
    queue <int> q; q.push(src); vis[src]=1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i=1; i<=50; i++) {
            if(adj[u][i] && !vis[i]) {vis[i] = 1; dis[i] = dis[u]+1; q.push(i);}
        }
    }
    int cnt=0;
    for(int i=1; i<=50; i++) {
        if(vis[i] && dis[i]==2) cnt++;
    }
    return cnt;
}
int sbfs (int src, int des) {
    memset(dis,0,sizeof(dis)); memset(vis,0,sizeof(vis));
    queue <int> q; q.push(src); vis[src]=1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u==des) break;
        for(int i=1; i<=50; i++) {
            if(adj[u][i] && !vis[i]) {vis[i] = 1; dis[i] = dis[u]+1; q.push(i);}
        }
    }
    if(vis[des]) return dis[des];
    else return -1;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    adj[2][6] = adj[6][2] = 1; adj[1][6] = adj[6][1] = 1; adj[7][6] = adj[6][7] = 1;
    adj[3][6] = adj[6][3] = 1; adj[4][6] = adj[6][4] = 1; adj[5][6] = adj[6][5] = 1;
    adj[3][4] = adj[4][3] = 1; adj[4][5] = adj[5][4] = 1; adj[3][5] = adj[5][3] = 1;
    adj[3][15] = adj[15][3] = 1; adj[13][15] = adj[15][13] = 1; adj[12][13] = adj[13][12] = 1;
    adj[13][14] = adj[14][13] = 1; adj[7][8] = adj[8][7] = 1; adj[8][9] = adj[9][8] = 1;
    adj[9][10] = adj[10][9] = 1; adj[12][9] = adj[9][12] = 1; adj[11][12] = adj[12][11] = 1;
    adj[10][11] = adj[11][10] = 1; adj[16][18] = adj[18][16] = 1; adj[16][17] = adj[17][16] = 1; adj[17][18] = adj[18][17] = 1;
    while(1) {
        cin>>s;
        if(s=="q") break;
        else if(s=="i") {
            int u,v; cin>>u>>v;
            adj[u][v] = adj[v][u] = 1;
        }
        else if(s=="d") {
            int u,v; cin>>u>>v;
            adj[u][v] = adj[v][u] = 0;
        }
        else if(s=="n") {
            int x; cin>>x; int cnt= 0;
            for(int i=1; i<=50; i++) {
                if(adj[x][i]) cnt++;
            }
            cout<<cnt<<fin;
        }
        else if(s=="f") {
            int x; cin>>x;
            cout<<fbfs(x)<<fin;
        }
        else if("s") {
            int x,y; cin>>x>>y; int ans = sbfs(x,y);
            if(ans==-1) cout<<"Not connected"<<fin;
            else cout<<ans<<fin;
        }
    }
}
