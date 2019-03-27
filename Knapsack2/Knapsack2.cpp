#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
int mxV = 100000;
ll dp[101][100001], ans =0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int N,W; cin>>N>>W;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] =0;
    for(int i=1, w,v; i<=N; i++) {
        cin>>w>>v; dp[i][0] = 0;
        for(int j=0; j<=mxV; j++) {
            dp[i][j] = dp[i-1][j];
            if(j>=v) dp[i][j] = min(dp[i][j], dp[i-1][j-v]+w);
        }
    }
    for(int i=1; i<=mxV; i++)
        if(dp[N][i]<=W) ans = max(ans,i);
    cout<<ans<<fin;
}

void dfs (int u) {
    vis[u] = 1;
    for(int v: adj[u]) {
        if(!vis[v]) {
            dis[v] = dis[u]+1; vis[v] = 1; dfs(v);
        }
    }
}
