#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef pair<int,int> pi;
vector<pi> v;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0,x,y; i<n; i++) {
        cin>>x>>y; v.push_back({x,y});
    }
    double ans = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            for(int k=j+1; k<v.size(); k++) {
                double a = sqrt(pow(v[i].first-v[j].first,2) + pow(v[i].second-v[j].second,2));
                double b = sqrt(pow(v[j].first-v[k].first,2) + pow(v[j].second-v[k].second,2));
                double c = sqrt(pow(v[k].first-v[i].first,2) + pow(v[k].second-v[i].second,2));
                if(a+b+c == 0 || b+c == a || c+a == b || a+b == c || a*a + b*b < c*c || a*a + c*c < b*b || b*b + c*c < a*a) {
                    ans = max(ans,max(a,max(b,c)));
                }
                else {
                    double r = a*b*c / sqrt( (a+b+c)*(b+c-a)*(c+a-b)*(a+b-c) );
                    ans = max(ans, 2*r);
                }
            }
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<fin;
}


