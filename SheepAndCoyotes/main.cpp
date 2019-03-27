#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef pair<double,double> pi;
pi sheep[100];
set<pi> ans;
int n;
bool vis[100];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) {
        double x,y; cin>>x>>y;
        sheep[i] = {x,y};
    }
    for(double i=0.00; i<1000.00; i+=0.01) {
        int in; double mn = (double) INT_MAX;
        for(int j=0; j<n; j++) {
            double dis = sqrt(pow(abs(sheep[j].first-i),2)+pow(sheep[j].second,2));
            if(dis<mn) {mn = dis; in = j;}
        }
        vis[in] = 1;
    }
    cout<<fixed;
    cout<<setprecision(2);
    for(int i=0; i<n; i++) {
        if(vis[i]) cout<<"The sheep at ("<<sheep[i].first<<", "<<sheep[i].second<<") might be eaten."<<fin;
    }
}
