#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    int x,y,z; cin>>x>>y>>z; d[x]=1; d[y]=1; d[z]=1;
    for(int i=0; i<=n; i++) {
        if(i+x<=n && d[i]!=0) d[i+x]=max(d[i]+1,d[i+x]);
        if(i+y<=n && d[i]!=0) d[i+y]=max(d[i]+1,d[i+y]);
        if(i+z<=n && d[i]!=0) d[i+z]=max(d[i]+1,d[i+z]);
    }
    cout<<d[n]<<fin;
}
