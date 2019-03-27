#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
string s; int n;
int solve () {
    int cnt = 0;
    unordered_set<string> ans;
    for(int i=1; i<=n/2; i++) {
        if(s.substr(0,i) == s.substr(n-i,i)) {
            ans.insert(s.substr(0,i));
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<=n-i; j++) {
            string t = s.substr(j,i);
            if(ans.count(t)) {cnt++; cout<<t<<" "; }
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>s;
    cout<<solve()+1<<fin;
}

