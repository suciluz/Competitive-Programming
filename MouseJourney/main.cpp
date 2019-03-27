#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int g[26][26], d[26][26];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int r,c,k; cin>>r>>c>>k;
    for(int i=0,x,y; i<k; i++) {
        cin>>x>>y; g[x][y] = 1;
    }
    d[1][1] = 1;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(!g[i][j]) { d[i][j] = max(d[i][j], d[i-1][j] + d[i][j-1]); }
            //cout<<d[i][j]<<" ";
        }
        //cout<<fin;
    }
    cout<<d[r][c]<<fin;
}
