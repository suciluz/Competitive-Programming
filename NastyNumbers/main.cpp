#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
bool nasty(int x) {
    vector <int> sum, diff;
    for(int i=1; i<=sqrt(x); i++) {
        if(x%i==0) {sum.pb(i+x/i); diff.pb(abs(i-x/i)); }
    }
    for(int i=0; i<sum.size(); i++) {
        for(int j=0; j<diff.size(); j++) {
            if(sum[i] == diff[j]) return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int in; cin>>in;
        if(nasty(in)) cout<<in<<" is nasty"<<fin;
        else cout<<in<<" is not nasty"<<fin;
    }
}
