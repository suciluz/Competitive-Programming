#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int N, p[200002]; string qry, x,y; bool portals[200002];

int Find (int d) {
    if(p[d]!=d) p[d]=Find(p[d]);
    return p[d];
}

int main()
{
    ios_base::sync_with_stdio(0);
    for(int t=0; t<5; t++) {
        unordered_map<string, int> mp; int cnt=0; cin>>N;
        for(int i=1; i<=2*N; i++) p[i]=i;
        for(int i=1; i<=N; i++) {
            cin>>qry>>x>>y;
            if(!mp.count(x)) mp[x]=++cnt; if(!mp.count(y)) mp[y]=++cnt;
            int fx = Find(mp[x]), fy = Find(mp[y]);
            if(qry=="p") {if(fx!=fy) {p[fx]=fy; portals[mp[x]]=1; portals[mp[y]]=1;}}
            else {
                if(fx==fy && portals[mp[x]]) cout<<"connected\n";
                else cout<<"not connected\n";
            }
        }
    }
}
