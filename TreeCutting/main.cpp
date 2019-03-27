#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int r,c, grid[10][10],nt[10][10],th[10][10]; bool vis[10][10];
typedef pair<int,int> pi;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>r>>c; pi st,des; int mxh=-1;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            char tmp; cin>>tmp;
            if(tmp=='.') grid[i][j] = 0;
            else if(tmp=='X') {st.first = i; st.second = j;}
            else {grid[i][j] = tmp-48; mxh = max(mxh,grid[i][j]); }
        }
    }
    double edis = (double) INT_MAX;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            th[i][j]=INT_MAX;
            if(grid[i][j] == mxh) {
                double tmp = sqrt(pow(i-st.first,2)+pow(j-st.second,2));
                if(edis>tmp) {
                    edis = tmp;
                    des.first = i; des.second = j;
                }
            }
        }
    }
    priority_queue <pair<int,pi>> q;
    q.push({0,st}); th[st.first][st.second] = 0;
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()) {
        pi u = q.top().second; int w = -q.top().first; q.pop();
        int i = u.first, j = u.second; vis[i][j] = 1;
        for(int k=0; k<4; k++) {
            int ni = i+d[k][1], nj=j+d[k][0];
            if(ni>=0&&ni<r&&nj>=0&&nj<c) {
                if(w+grid[ni][nj] < th[ni][nj]) {
                    th[ni][nj] = w + grid[ni][nj]; nt[ni][nj] = nt[i][j]; if(grid[ni][nj]>0) nt[ni][nj]++;
                    q.push({-th[ni][nj],{ni,nj}});
                }
            }
        }
    }
    cout<<--nt[des.first][des.second]<<fin;
}


