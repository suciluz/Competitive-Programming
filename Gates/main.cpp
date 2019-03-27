#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n,p;
set<int> ans;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>p;
    for(int i=1; i<=n; i++) ans.insert(i);
    for(int i=0; i<p; i++) {
        int plane; cin>>plane;
        if(ans.upper_bound(plane)==ans.begin()) { cout<<i<<fin; return 0; }
        else ans.erase(--ans.upper_bound(plane));
    }
    cout<<p<<fin;
}

