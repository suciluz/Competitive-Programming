#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n,m,ver,mst=0;
typedef pair<int,int> pi;
struct E {int u,v,w;}; vector<E> e;
bool cmp(E x, E y) {return x.w < y.w;}
map <pi,E> pen;
int p[101];

int Find (int d) {
    if(d!=p[d]) p[d] = Find(p[d]);
    return p[d];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>m; n=m;
    for(int i=1; i<=m; i++) {
        cin>>ver; int vs[ver];
        for(int j=0; j<ver; j++) cin>>vs[j];
        for(int j=0,tu,tv,tw; j<ver; j++) {
            cin>>tw;
            if(j==ver-1) { tu = min(vs[j],vs[0]); tv = max(vs[j],vs[0]); }
            else { tu = min(vs[j],vs[j+1]); tv = max(vs[j],vs[j+1]); }
            if(pen.find({tu,tv})==pen.end()) {pen[{tu,tv}].w = tw; pen[{tu,tv}].u = i; pen[{tu,tv}].v = -1; }
            else { pen[{tu,tv}].v = i; }
        }
    }
    for(auto edge:pen) e.pb(edge.second);
    int cnt = 0, cnt2 = 0, singedge;
    for(int i=0; i<=m; i++) p[i] = i;
    sort(e.begin(),e.end(),cmp);
    for(int i=0; i<e.size(); i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        //if(cnt==n-1) break;
        int fu = Find(u), fv = Find(v);
        if(fu!=fv) {
            p[fu] = fv; cnt++; mst+=w;
            if(v==-1 ) { singedge = w; cnt2++;}
        }
    }
    if(cnt2==1) mst-=singedge;
    cout<<mst<<fin;
}

/*
4
3 1 2 3 7 4 6
4 1 2 4 5 7 7 2 6
4 4 7 6 5 4 8 9 2
5 3 2 4 7 8 4 7 4 7 7
2 3 2
1 4 4
3 4 4
1 0 6
2 0 6
1 2 7
2 4 7
4 0 7
4 0 7
3 0 8
3 0 9
10
*/
