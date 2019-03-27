#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
const int INF = 1e9+1;
typedef pair<int,int> pi;
ll ans=0;
vector<pi> sx,sy;

/*

algorithm: 2 x up x left x right x below

arr1: sorted by x, tie break by y
arr2: sorted by y, tie break b x
lowerbound to find how many below and above

*/

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int x,y; cin>>x>>y;
        sx.push_back({x,y});
        sy.push_back({y,x});
    }
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());
    for(int i=0; i<sx.size(); i++) {
        int cur = lower_bound(sy.begin(), sy.end(), pi{sx[i].second, sx[i].first}) - sy.begin();
        int down = lower_bound(sx.begin(), sx.end(), pi{sx[i].first, -INF}) - sx.begin();
        int up = lower_bound(sx.begin(), sx.end(), pi{sx[i].first, INF}) - sx.begin();
        int left = lower_bound(sy.begin(), sy.end(), pi{sx[i].second, -INF}) - sy.begin();
        int right =  lower_bound(sy.begin(), sy.end(), pi{sx[i].second, INF}) - sy.begin();
        ans += 2*(up-i-1) * (cur-left) * (right-cur-1) * (i-down);
    }
    cout<<ans<<fin;
}

