#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
char g[20][20];
bool vis[20][20]; int dis[20][20];
typedef pair<int,int> pi;
int n,m,t,ans;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>t; pi st;
    queue <pi> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>g[i][j];
            if(g[i][j]=='G') st = {i,j};
            if(g[i][j]=='H') q.push({i,j});
        }
    }
   int moves[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    //q.push(st);
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second; q.pop();
        for(int k=0; k<4; k++) {
            int ni = i+moves[k][1], nj=j+moves[k][0];
            if(!vis[ni][nj]) {
                dis[ni][nj] = dis[i][j] + 1; vis[ni][nj] = 1; q.push({ni,nj});
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j] =='H' || g[i][j] =='G') {
                ans += dis[i][j];
            }
        }
    }
    cout<<ans<<fin;
}


