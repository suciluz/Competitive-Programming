#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[1000001];
typedef pair<int,int> pi;
struct {pi x, y, z; } p[2001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,t; cin>>n>>t;
    for(int i=1; i<=n; i++) {
        cin>>p[i].x.first>>p[i].x.second>>p[i].y.first>>p[i].y.second>>p[i].z.first>>p[i].z.second;
        for(int j=t; j>=0; j--) {
            if(p[i].x.first <= j) d[j] = max(d[j],d[j-p[i].x.first]+p[i].x.second);
            if(p[i].y.first <= j) d[j] = max(d[j],d[j-p[i].y.first]+p[i].y.second);
            if(p[i].z.first <= j) d[j] = max(d[j],d[j-p[i].z.first]+p[i].z.second);
        }

    }
    cout<<d[t]<<fin;
}
