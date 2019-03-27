#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
const int maxn = 1000;
int n,m,dis[maxn][maxn],vis[maxn][maxn]; char adj[maxn][maxn],tmp;
struct coor{int x,y;};
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m; coor st; int ex,ey;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>tmp;
            if(tmp=='s') {st.x=i; st.y=j;}
            if(tmp=='e') {ex=i; ey=j;}
            adj[i][j]=tmp;
        }
    }
    int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    queue <coor> q;
    q.push(st);
    while(!q.empty()) {
        coor cur = q.front(); q.pop();
        int i = cur.x, j = cur.y; vis[i][j]=1; if(i==ex && j==ey) break;
        for(int x=0; x<4; x++) {
            int ni = i+d[x][0]; int nj = j+d[x][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && adj[ni][nj]!='X') {vis[ni][nj]=1; dis[ni][nj]=dis[i][j]+1; q.push(coor{ni,nj});}
        }
    }
    if(!vis[ex][ey]) cout<<-1<<end;
    else cout<<dis[ex][ey]-1<<end;
}
