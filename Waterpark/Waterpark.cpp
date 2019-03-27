#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
const int maxn = 10000;
vector<int> adj[maxn]; bool vis[maxn]; int n;
int d[maxn];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int x,y; cin>>n;
    do {
        cin>>x>>y; adj[y].push_back(x);
    } while(x!=0 && y!=0); d[n] = 1;
    for(int i=n; i>1; i--) {
        for(int x: adj[i]) {
            d[x] += d[i];
        }
    }
    for(int i=0; i<=n; i++) cout<<d[i]<<" ";
    cout<<d[1]<<fin;
}

