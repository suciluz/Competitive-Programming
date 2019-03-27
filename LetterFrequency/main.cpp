#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
string sent; int n;
vector<int> LF[26];
int main() {
    ios_base::sync_with_stdio(0);
    getline(cin,sent);
    for(int i=0; i<sent.length(); i++) {
        if(sent[i]!=' ') LF[sent[i]-97].pb(i);
    }
    cin>>n;
    for(int i=0,l,r; i<n; i++) {
        char c; cin>>l>>r>>c; c-=97;
        auto s = lower_bound(LF[c].begin(),LF[c].end(),l-1);
        auto e = upper_bound(LF[c].begin(),LF[c].end(),r-1);
        cout<<(e-LF[c].begin())-(s-LF[c].begin())<<fin;
    }
}



