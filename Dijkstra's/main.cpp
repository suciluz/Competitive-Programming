#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int N,M;
const int MM=100;vector<pair<int,int>> adj[MM];
int dijkstras(int src, int fin, int V)
{
    vector<bool> vis(V+1);
    vector<int> dist(V+1, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>> buf;
    buf.push({0, src});
    while (!buf.empty())
    {
        int u = buf.top().second;
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (dist[u] + x.second < dist[x.first])
            {
                dist[x.first] = dist[u] + x.second;
                if (x.first == fin) return dist[x.first];
                if (!vis[x.first])
                    vis[x.first] = true, buf.push({-dist[x.first], x.first});
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N,&M);
    for(int i=1, u,v,w; i<=M; i++) {
        scanf("%d %d %d", &u,&v,&w);
        adj[u].push_back({v,w}); adj[v].push_back({u,w});
    }
    printf("%d ",dijkstras(1,5,5));
    //for(int i=1; i<=N; i++) printf("%d ", dis[i]);
    return 0;
}
/*
6 9
1 2 34
1 3 46
1 6 19
2 5 12
3 4 17
3 6 25
4 5 38
4 6 25
5 6 26
*/
