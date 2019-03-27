#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
const int inf = 0x3f3f3f3f;
int n,p;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>p; vector <pi> pl(n); int fuel, cnt=0;
    for(int i=0,a,b; i<n; i++) {
        cin>>a>>b; pl[i].first = b; pl[i].second = a;
        if(i==(p-1)) {fuel = a; pl[i].first = inf;}

    } sort(pl.begin(), pl.end());

    for(; cnt <= n ;) {
        bool done = 0;
        for(int i=0; i<n; i++) {
            if(fuel >= pl[i].first && pl[i].first <= pl[i].second) {
                fuel += (pl[i].second - pl[i].first); cnt++;
            }
            else if(fuel < pl[i].first) break;
        }
        if(!done) break;
    }
    cout<<fuel<<fin<<++cnt<<fin;
}


