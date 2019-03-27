#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
struct V {int idx,c,l,trig,ans; };
bool cmp(V x, V y) {
    if(!x.trig) return x.l<y.l;
    else return x.idx < y.idx;
}

V qry[100000];
int arr[2001];
int d[10001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,v; cin>>n>>v;
    memset(d,0x3f,sizeof(d));
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=0; i<v; i++) { cin>>qry[i].c>>qry[i].l; qry[i].idx = i; qry[i].trig = 0; }
    sort(qry,qry+v,cmp); d[0] = 0;
    for(int i=1, q=0; i<=n; i++) {
        for(int j=arr[i]; j<=10001; j++) d[j] = min(d[j], d[j-arr[i]]+1);
        for(; qry[q].l == i && q<v ;q++) {
            qry[q].ans = d[qry[q].c];
        }
    }
    for(int i=0; i<v; i++) qry[i].trig = 1;
    sort(qry,qry+v,cmp);
    for(int i=0; i<v; i++)
        if(qry[i].ans == 0x3f3f3f3f) cout<<-1<<fin;
        else cout<<qry[i].ans<<fin;
}


