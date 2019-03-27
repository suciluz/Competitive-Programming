#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n,m;
typedef pair<int,int> pi;
vector<pi> cities;
map <pi,bool> mp;
pi bomb[3];

int formula(int a1, int a2, int b1, int b2, int c1, int c2) {
   return abs((a1*(b2-c2) + b1*(c2-a2)+ c1*(a2-b2)));
}
bool valid(int x, int y) {
    int a1=bomb[0].first,a2=bomb[0].second,b1=bomb[1].first,b2=bomb[1].second,c1=bomb[2].first,c2=bomb[2].second;
    int tmp = formula(a1,a2,b1,b2,c1,c2), tmp1 = formula(x,y,b1,b2,c1,c2),
    tmp2 = formula(a1,a2,x,y,c1,c2), tmp3 = formula(a1,a2,b1,b2,x,y);
    if(tmp==tmp1+tmp2+tmp3) return true;
    else return false;
}
int solve () {
    int cnt = 0;
    for(int i=0; i<cities.size(); i++) {
        if(valid(cities[i].first,cities[i].second)) {
            cnt++;
            if(mp[{cities[i].first,cities[i].second}]==1) cnt++;
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m; int dup = 0;
    for(int i=0; i<n; i++) {
        int x,y; cin>>x>>y;
        cities.pb({x,y});
        if(mp.find({x,y})==mp.end()) {mp[{x,y}] = 0;}
        else {mp[{x,y}]=1; cout<<"YYY"<<fin;}
    }
    for(int i=0; i<m; i++) {
        cin>>bomb[0].first>>bomb[0].second>>bomb[1].first>>bomb[1].second>>bomb[2].first>>bomb[2].second;
        cout<<solve()<<fin;
    }
}
