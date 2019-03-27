#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
map<pair<int,int>, int> mp1;
map <int, int> mp2;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n; cin>>n; ll over = 0;
    for(int i=0; i<n; i++) {
        int m,b; cin>>m>>b;
        if(!mp1[{m,b}] && mp2[m]>0) {
            over++;
        }
        mp1[{m,b}]++;
        mp2[m]++;
    }
    over++;
    ll tmp = n*(n-1)/2LL;
    ll tmp2 = over*(over-1)/2LL;
    cout<<tmp - tmp2<<fin;
}


