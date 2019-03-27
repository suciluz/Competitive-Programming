#include <bits/stdc++.h>
using namespace std;
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    unordered_map <string,int> mp;
    for(int i=0; i<n; i++) {
        string s; cin>>s;
        mp[s]++;
    }
    int cnt = 0;
    for(auto i : mp) {
        if(i.second == 1) cnt++;
    }
    cout<<cnt<<fin;
}


