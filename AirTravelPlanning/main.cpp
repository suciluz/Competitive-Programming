#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
typedef pair<int,int> pi;
int main() {
    ios_base::sync_with_stdio(0);
    for(int t=0; t<5; t++) {
        unordered_map<string,int> mp; vector<pi> adj[21]; int dis[21];
        int n; cin>>n;
        for(int i=0,cnt=0,w; i<n; i++) {
            string tmp, tmp2; cin>>tmp>>tmp2>>w;
            if(!mp.count(tmp)) {mp[tmp] = ++cnt;}
            if(!mp.count(tmp2)) {mp[tmp2] = ++cnt;}
            adj[mp[tmp]].pb({mp[tmp2],w});
        }
        int st = mp["YYZ"];
        memset(dis,0x3f3f3f3f,sizeof(dis));
        priority_queue<pi> pq; dis[st] = 0; pq.push({0,st});
        while(!pq.empty()) {
            int u = pq.top().second; pq.pop();
            for(auto &x: adj[u]) {
                if(dis[u]+x.second<dis[x.first]) {
                    dis[x.first] = dis[u]+x.second;
                    pq.push({-dis[x.first],x.first});
                }
            }
        }
         cout<<dis[mp["SEA"]]<<end;
    }
}
