#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef pair<int,int> pi;
vector<pi> v;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int x,y;cin>>x>>y; v.push_back({x,y});
    }
    v.push_back(v.front());
    long long tmp1=0, tmp2=0;
    for(int i=n; i>0; i--) {
        tmp1 += v[i].first*v[i-1].second;
    }
    for(int i=n; i>0; i--) {
        tmp2 += v[i].second * v[i-1].first;
    }
    long long ans = abs(tmp1-tmp2);
    cout<<ceil(0.5*ans)<<fin;
}


