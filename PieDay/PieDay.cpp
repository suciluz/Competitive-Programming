#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n, k, d[251][251];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k; memset(d,-1,sizeof(d));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j==1 || i==j) d[i][j]=1;
            else if (i<j) d[i][j] =0;
            else if(d[i][j]==-1) {
                d[i][j] = d[i-1][j-1] + d[i-j][j];
            }
        }
    }
    cout<<d[n][k]<<fin;
}

