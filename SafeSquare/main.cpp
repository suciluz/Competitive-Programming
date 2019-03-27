#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int r,c,c2, adj[100][100];
bool safe(int i, int j) {
    //cout<<12;
    int d[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    int snake=0,tot=0;
    for(int k=0; k<8; k++) {
        int ni=i+d[k][1], nj=j+d[k][0];
        if(ni>=0 && ni<r && nj>=0 && nj<c) {
            tot++; if(adj[ni][nj]==2) snake++;
        }
    }
    if(snake >= ceil(tot/2.0)) return false;
    else return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    memset(adj, 0, sizeof(adj));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            char in; cin>>in;
            if(in=='.') adj[i][j]=1;
            else adj[i][j]=2;
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++){
            //cout<<adj[i][j]<<" ";
            if(adj[i][j]==1) {
                if(safe(i,j)) c2++;
            }
        //cout<<" "<<'\n';
        }
    }
    cout<<c2<<'\n';
}
