#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int maxn = 100001;
typedef long long ll;
struct E {int u, v; ll w;} e[maxn];
bool cmp(E x, E y) {return x.w < y.w;}
int n,m,k,p[maxn],cnt=0; ll mst=0; bool crucial[maxn];
int Find (int d) {
    if(d!=p[d]) p[d] = Find(p[d]);
    return p[d];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0; i<k; i++) { int tmp; cin>>tmp; crucial[tmp] =1 ;}
    for(int i=1; i<=n; i++) {
        if(crucial[i]) p[i] = i;
    }
    for(int i=1; i<=n-1; i++) {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    int z = n-1;
    sort(e,e+z,cmp);
    for(int i=1; i<=n-1; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w; //cout<<w<<" ";
        //if(cnt==k-1)break;
        int fu = Find(u), fv=Find(v);
        if(fu!=fv) {p[fu] = fv; cnt++; mst+=w;}
    }
    for(int i=0; i<m; i++) {
        int zz; cin>>zz;
        if(zz==1) {
            string s; cin>>s;
        }else {
            string s,s2; cin>>s>>s2;
        }
    }
    cout<<mst<<fin;
}
