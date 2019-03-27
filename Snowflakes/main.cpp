#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
set<string> ans;
int tmp[100000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        for(int i=0; i<6; i++) cin>>tmp[i];
        string s="";
        sort(tmp,tmp+6);
        for(int i=0; i<6; i++) s = s+to_string(tmp[i]);
        ans.insert(s);
    }
    if(ans.size()==n) cout<<"No two snowflakes are alike."<<fin;
    else cout<<"Twin snowflakes found."<<fin;
}
