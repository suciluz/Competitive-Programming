#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
vector<int> adj[26]; int cnt=0;
struct e {int u,v;}; vector<e> edges; bool vis[26]; queue <int> q;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL); string s;
    cin>>s;
    while(s!="**"){
        int u = s.at(0)-65, v = s.at(1)-65;
        adj[u].pb(v); adj[v].pb(u); edges.pb({u,v});
        cin>>s;
    }
    for(int i=0; i<edges.size(); i++) {
        e E =  edges[i];
        int x = E.u, y = E.v;
        memset(vis,0,sizeof(vis));
        q.push(0); vis[0] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int k: adj[u]) {
                if(!vis[k] && !(u==x && k==y) && !(u==y && k==x)) {vis[k] = 1; q.push(k); }
            }
        } cout<<fin;
        if(!vis[1]) {
            cout<<(char)(x+65)<<(char)(y+65)<<fin; cnt++;
        }
    }
    cout<<"There are "<<cnt<<" disconnecting roads."<<fin;
}
