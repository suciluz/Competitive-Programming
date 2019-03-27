#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[1001][1001];
int s1[1001], s2[1001];
int n,m;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0, tmp; i<n; i++) {
        cin>>tmp; s1[i] = tmp;
    }
    for(int i=0, tmp; i<m; i++) {
        cin>>tmp; s2[i] = tmp;
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            if(i==0 || j==0) d[i][j] = 0;
            else if (s1[i-1] == s2[j-1]) d[i][j] = d[i-1][j-1] +1;
            else d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    cout<<d[n][m]<<fin;
}
