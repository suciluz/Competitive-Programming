#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int in[2*910];
int n,cnt=0;
string name[2*910];
vector<int> adj[2*910];
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0; i<n; i++) {
        string a,b;
        cin>>a>>b;
        if(!mp.count(a)) {mp[a]=cnt; name[cnt++]=a;}
        if(!mp.count(b)) {mp[b]=cnt; name[cnt++]=b;}
        adj[mp[b]].pb(mp[a]); in[mp[a]]++;
    }
    while(1) {
        int id=-1;
        for(int i=0; i<cnt; i++) {
            if(in[i]==0){in[i]--; id=i; break;}
        }
        if(id==-1)break;
        cout<<name[id]<<'\n';
        for(int v: adj[id])in[v]--;
    }
}

//map, topo sort
