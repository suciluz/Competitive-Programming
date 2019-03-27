#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int r,c; char adj[100][100]; int camera[100][100], dis[100][100]; bool vis[100][100];
struct coor {
    int x;
    int y;
};
void cam2(int i, int j); void cam (int sx,int sy); void bfs(int sx,int sy); bool conveyor(coor& u);

int main() {
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    char t;
    int sx=0, sy=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin>>t;
            if(t=='S') {sx=i; sy=j;}
            if(t=='C') camera[i][j]=2;
            if(t=='W') camera[i][j]=2;
            adj[i][j]=t;
        }
    }
    cam(sx,sy);
    if(camera[sx][sy]!=0) {
        for(int i = 0 ; i<r ; i++) {
            for(int j=0; j<c; j++) {
                if(adj[i][j]=='.') {
                    cout<<-1<<'\n';
                }
            }
        }
    }
    else  {
        bfs(sx,sy);
        for(int i = 0 ; i<r ; i++) {
            for(int j=0; j<c; j++) {
                if(adj[i][j]=='.') {
                    if(!vis[i][j]) cout<<-1<<'\n';
                    else cout<<dis[i][j]<<" "<<i<<" "<<j<<'\n';
                }
            }
        }
    }
}

void bfs(int sx,int sy) {
    queue <coor> q;
    q.push(coor{sx,sy});
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()) {
        int i=q.front().x, j=q.front().y; vis[i][j]=1;
        q.pop();
        for(int k=0; k<4; k++) {
            int ni = i+d[k][1], nj=j+d[k][0];
            coor u{ni,nj};

                if(adj[ni][nj]=='C' || adj[ni][nj]=='W' || camera[ni][nj]==2)continue;
                else {
                    if(!vis[u.x][u.y]&&adj[u.x][u.y]=='.'){
                        if(camera[u.x][u.y]==0){
                            q.push(u); vis[u.x][u.y]=1; dis[u.x][u.y]=dis[i][j]+1;
                        }
                    }
                    else if(!vis[u.x][u.y]&&conveyor(u)){
                            q.push(u); vis[u.x][u.y]=1; dis[u.x][u.y]=dis[i][j]+1;
                    }
                }

        }
    }
}

bool conveyor(coor &u) {
    coor v=u;
    while(1) {
        if(adj[v.x][v.y]=='U') v.x--;
        else if(adj[v.x][v.y]=='D')v.x++;
        else if(adj[v.x][v.y]=='L')v.y--;
        else if(adj[v.x][v.y]=='R')v.y++;
        if(adj[v.x][v.y]=='.'){
            if(vis[v.x][v.y] || camera[v.x][v.y]==2)return false;
            else {u=v;return true;}
        } else if(!vis[v.x][v.y]&& (adj[v.x][v.y]=='L'||adj[v.x][v.y]=='R'||adj[v.x][v.y]=='U'||adj[v.x][v.y]=='D')) {
            vis[v.x][v.y]=1;continue;
        } else return false;

    }
}
void cam2(int i, int j){
    for(int c=i+1;;c++){
        if(adj[c][j]=='W')break;
        else if(adj[c][j]=='.') camera[c][j]=2;
    }
    for(int c=i-1;;c--){
        if(adj[c][j]=='W')break;
        else if(adj[c][j]=='.') camera[c][j]=2;
    }
    for(int c=j+1;;c++){
        if(adj[i][c]=='W')break;
        else if(adj[i][c]=='.') camera[i][c]=2;
    }
    for(int c=j-1;;c--){
        if(adj[i][c]=='W')break;
        else if(adj[i][c]=='.') camera[i][c]=2;
    }
}

void cam (int sx,int sy) {
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(adj[i][j]=='C') cam2(i,j);
    for(int i=sx,j=sy+1;;j++){
        if(adj[i][j]=='C') {camera[sx][sy]=2;return;}
        else if(adj[i][j]=='W')break;
    }
    for(int i=sx,j=sy-1;;j--){
        if(adj[i][j]=='C') {camera[sx][sy]=2;return;}
        else if(adj[i][j]=='W')break;
    }
    for(int i=sx+1,j=sy;;i++){
        if(adj[i][j]=='C') {camera[sx][sy]=2;return;}
        else if(adj[i][j]=='W')break;
    }
    for(int i=sx-1,j=sy;;i--){
        if(adj[i][j]=='C') {camera[sx][sy]=2;return;}
        else if(adj[i][j]=='W')break;
    }
}
