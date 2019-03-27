#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn=3001;
typedef long long ll;
int n,X,q; ll dis[maxn];
struct c {ll x,y;} coor[maxn]; bool vis[maxn]; vector<ll> diss;
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {ll x,y; scanf("%lld%lld", &x, &y); coor[i].x=x; coor[i].y=y;}
    scanf("%d", &X);
    memset(dis,0x3f,sizeof(dis)); dis[X-1]=0;
    for(int i=0; i<n; i++) {
        ll mn = 0x3f3f3f3f3f3f3f3f; int u = -1;
        for(int j=0; j<n; j++)
            if(!vis[j] && dis[j]<mn) {mn=dis[j]; u=j;}
        if(u == -1) break; vis[u]=true;
        for(int j=0; j<n; j++) {
            if(j!=u){
                ll a = abs(coor[u].x-coor[j].x), b = abs(coor[u].y-coor[j].y);
                ll hrs = a*a+b*b;
                if(dis[u]+hrs<dis[j]) dis[j]=dis[u]+hrs;
            }
        }
    }
    for (int i=0; i<n; i++) diss.pb(dis[i]);
    sort(diss.begin(), diss.end());scanf("%d", &q);
    for(int i=0; i<q; i++) { ll in;
        scanf("%lld", &in);
        printf("%d\n",upper_bound(diss.begin(), diss.end(), in) - diss.begin());
    }
}
