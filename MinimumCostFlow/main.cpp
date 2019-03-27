#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
#define maxn 100001
struct E {int u, v, w, act,oe; } e[200001];
bool cmp(E x, E y) {
    if(x.w==y.w) return x.act<y.act;
    else return x.w < y.w;
}
int n,m,d,days=0,cnt=0,emax=0, p[maxn];

int Find (int d) {
    if(d!=p[d]) p[d] = Find(p[d]);
    return p[d];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>d;
    for(int i=1; i<=n; i++) p[i]=i;
    for(int i=1; i<=m; i++) {
        cin>>e[i].u>>e[i].v>>e[i].w;
        if(i<=n-1) e[i].act = 0;
        else e[i].act=1;
        e[i].oe=0;
    }
    sort(e,e+m+1,cmp);
    for(int i=1; i<=m; i++) {
        int u = e[i].u, v = e[i].v, actd = e[i].act;
        if(cnt==n-1)break;
        int fu = Find(u), fv=Find(v);
        if(fu!=fv) {p[fu] = fv; cnt++; emax=e[i].w; e[i].oe=1; if(actd) days++;}
    }
    for(int i=1; i<=n; i++) p[i]=i; cnt=0;
    for(int i=1; i<=m; i++) {
        int u = e[i].u, v = e[i].v, actd = e[i].act, wt = e[i].w, omst = e[i].oe;
        if(cnt==n-1)break;
        int fu = Find(u), fv=Find(v);
        if(fu!=fv) {
            if((omst==1 && wt==emax) || wt<emax) p[fu]=fv;
            else if(actd==0 && wt<=d) {days--; break;}
        }
    }
    cout<<days<<end;

}
