#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
string g1 [30], g2[30];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>g1[i];
    for(int i=0; i<n; i++) cin>>g2[i];
    unordered_set <string> st;
    unordered_map <string,string> mp;
    for(int i=0; i<n; i++) {
        if(st.count(g1[i])) {
            if(mp[g1[i]] != g2[i] || mp[g2[i]] != g1[i]) {cout<<"bad"<<fin; return 0;}
        } else {
            mp[g1[i]] = g2[i]; mp[g2[i]] = g1[i];
            st.insert(g1[i]); st.insert(g2[i]);
        }
        if(g1[i] == g2[i]) {cout<<"bad"<<fin; return 0;}
    } cout<<"good"<<fin;
}
