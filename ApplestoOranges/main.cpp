#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 500;
typedef pair<int,double> pi; vector<pi> adj[maxn];
int n,m, dis[maxn]; double stock[maxn];
unordered_map <string,int> mp;
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) {string tmp; cin>>tmp; mp[tmp]=i;}
    for(int i=0; i<m; i++) {
        string tmp, tmp2; double rate;
        cin>>tmp>>tmp2>>rate;
        adj[mp[tmp]].pb({mp[tmp2],rate});
    }
    int idx = mp["APPLES"];
    queue <pi> q; q.push({idx,1.0}); stock[idx]=1.0;
    while(!q.empty()) {
        int u = q.front().first; double amt = q.front().second; q.pop();
        if(u == idx && stock[idx] > 1.01) {cout<<"YA"<<fin; return 0;}
        for(auto x: adj[u]) {
            if(amt*x.second>stock[x.first]) {
                stock[x.first] = amt*x.second;
                q.push({x.first,amt*x.second});
            }
        }
    }
    cout<<"NAW"<<fin;
}


