#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct E {int u, v, w;} e[100];
int n,m,p[100],mst=0,cnt=0;
bool cmp(E x, E y) {return x.w < y.w;}

int Find (int d) {
    if(d!=p[d]) p[d] = Find(p[d]);
    return p[d];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0; i<100; i++) p[i]=i;
    for(int i=1; i<=m; i++) {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e,e+m,cmp);
    for(int i=1; i<=m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w; cout<<w<<" ";
        if(cnt==n-1)break;
        int fu = Find(u), fv=Find(v);
        if(fu!=fv) {p[fu] = fv; cnt++; mst+=w;}
    }

    cout<<mst<<'\n';
}
//0 12 25 17 26 19
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
