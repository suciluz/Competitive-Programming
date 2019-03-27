#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
struct E {int u,v,w;} e[100002];
bool cmp(E x, E y) {return x.w < y.w;}
int n, k,cnt=0,mst=0,cnt2=0, p[100002];

int Find(int d) {
    if(d!=p[d]) p[d] = Find(p[d]);
    return p[d];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0; i<n-1; i++) {
        cin>>e[i].w; e[i].u=i+1; e[i].v=i+2;
    }
    for(int i=0; i<=n; i++) p[i] = i%k; int sz = n-1;
    sort(e,e+sz,cmp);
    for(int i=0; i<n-1; i++) {
        int u = e[i].u, v = e[i].v;
        int fu = Find(u), fv = Find(v);
        if(fu!=fv) { p[fu] = fv; cnt++; mst+=e[i].w;}
        if(cnt==k-1) break;
    }
    cout<<mst<<end;
}

