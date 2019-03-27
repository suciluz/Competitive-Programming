#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef long long ll;
ll d[5001],itm[5001],ans = -0x3f3f3f3f3f3f3f3f;
int n,m;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=1,nm,w,p; i<=n; i++) {
        cin>>nm>>w>>p;
        for(int j=w; j<=5000; j++) {
            if(d[j-w]+p > d[j] && itm[j-w]+1 <= nm) {d[j] = d[j-w]+p; itm[j] = itm[j-w]+1;}
        }
        memset(itm,0,sizeof(itm));
    }
    for(int i=1; i<=5000; i++) d[i] = max(d[i],d[i-1]);
    for(int i=1,c,f; i<=m; i++) {
        cin>>c>>f; ans = max(ans,d[c]-f);
    }
    cout<<ans<<fin;
}
