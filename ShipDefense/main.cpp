#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
typedef pair<int,int> pi;
vector<pi> def;
int h,d,e,a,s,t,l,x,ter=0,star=INT_MAX,dam=0,state[1001]; double ans=0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>h>>d>>e;
    for(int i=0; i<d; i++) {
        cin>>a>>s; def.pb({a,s});
    }
    for(int i=0; i<e; i++) {
        cin>>t>>l>>x;
        for(int j=t; j<t+l; j++) {state[j]+=x; dam += x; ter = max(ter,t+l); star = min(t,star);}
    }
    ans = (double)h;
    for(int i=star; i<ter; i++) {
        double tmp = INT_MAX;
        for(int j=0; j<def.size(); j++) {
            tmp = min(tmp,(double)(state[i]-def[j].first)*(1-def[j].second*0.01));
            //cout<<tmp<<" ";
        }
        ans+=tmp;
    }
    if(ans>=h) cout<<"DO A BARREL ROLL!"<<fin;
    else cout<<(double)h-ans<<fin;
    //cout<<ans<<"T";
}
