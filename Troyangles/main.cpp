#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int n, cnt = 0;
int g[2002][2002], d[2002][2002];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char tmp; cin>>tmp;
            if(tmp=='.') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }
    for(int i=n; i>=0; i--) {
        for(int j=0; j<=n; j++) {
            if(g[i][j] &&i&&j) {
                d[i][j] = min(d[i+1][j-1],min(d[i+1][j],d[i+1][j+1])) + 1; cnt+=d[i][j];
            }
        }
    }
    cout<<cnt<<fin;
}

