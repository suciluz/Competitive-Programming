#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
typedef pair<int,int> pi;
vector<pi> sx,sy, qry;
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m; cin>>n;
    for(int i=0, x,y; i<n; i++) {
        cin>>x>>y; sx.push_back({x,y}); sy.push_back({y,x});
    } cin>>m;
    sort(sx.begin(), sx.end()); sort(sy.begin(), sy.end());
    int tmp, tmp2; cin>>tmp>>tmp2; qry.push_back({tmp,tmp2});
    for(int i=1,cx,cy,px,py; i<m; i++) {
        px = qry.back().first, py = qry.back().second;
        cin>>cx>>cy;
        if(px==cx) {
            int l = lower_bound(sx.begin(), sx.end(), pi{px, min(cy,py)}) - sx.begin();
            int r = upper_bound(sx.begin(), sx.end(), pi{px, max(cy,py)}) - sx.begin();
            ans += r - l;
        }
        else {
            int l = lower_bound(sy.begin(), sy.end(), pi{py, min(cx,px)}) - sy.begin();
            int r = upper_bound(sy.begin(), sy.end(), pi{py, max(cx,px)}) - sy.begin();
            ans += r - l;
        }
        qry.push_back({cx,cy});
    }
    cout<<ans<<fin;
}


/*
sort by y,x => binary search
*/
